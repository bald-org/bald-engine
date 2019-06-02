//
// Created by grzegorz on 19.02.19.
//

#include "event_manager.h"
#include <future>

namespace Bald {

    std::deque<Event*> EventManager::m_EventQueue;
    int EventManager::m_ReferenceCounter = 0;

    EventManager::EventManager() {
        [[maybe_unused]] bool state = Init();
        BALD_ASSERT(state, "EventManager", "Failed to initialized EventManager", state);
    }

    EventManager::~EventManager() {
        Shutdown();
    }

    bool EventManager::Init() {
        CORE_LOG_INFO("[EventManager] Initializing EventManager...");
        ++m_ReferenceCounter;
        CORE_LOG_INFO(("[EventManager] Actual number of EventManagers: " + std::to_string(m_ReferenceCounter)).c_str());
        return m_ReferenceCounter > 0;
    }

    void EventManager::Shutdown() {
        CORE_LOG_INFO("[EventManager] Shutting down EventManager...");
        RemoveAllCallbacks();
        --m_ReferenceCounter;
        CORE_LOG_INFO(("[EventManager] Actual number of EventManagers: " + std::to_string(m_ReferenceCounter)).c_str());
        if(m_ReferenceCounter == 0) {
            CORE_LOG_INFO("[EventManager] This was last one EventManager");
            CORE_LOG_INFO("[EventManager] Clearing event queue...");
            ClearEventQueue();
            CORE_LOG_INFO("[EventManager] Clearing event queue was successful");
        }
        CORE_LOG_INFO("[EventManager] Shutdown was successful");
    }

    void EventManager::Flush() noexcept {
        for(auto it = m_EventQueue.begin(); it != m_EventQueue.end();) {
            const auto& async_callbacks = m_CallbacksAsync.find((*it)->GetType());
            const auto& sync_callbacks = m_CallbacksSync.find((*it)->GetType());

            if(async_callbacks == m_CallbacksAsync.end() && sync_callbacks == m_CallbacksSync.end()) {
                ++it;
                continue;
            }
            std::vector<std::future<void>> ft;
            if(async_callbacks != m_CallbacksAsync.end()) {
                for(const auto& fun : async_callbacks->second) {
                    ft.emplace_back(std::async(std::launch::async, [&it, &fun]() {
                        fun->Run(**it);
                    }));
                }
            }

            if(sync_callbacks != m_CallbacksSync.end()) {
                for(const auto& fun : sync_callbacks->second) fun->Run(**it);
            }

            for(const auto& f : ft) {
                f.wait();
            }

            delete *it;
            it = m_EventQueue.erase(it);
        }
    }

    void EventManager::RemoveAllCallbacks() noexcept {
        for(auto it = m_CallbacksSync.begin(); it != m_CallbacksSync.end(); it = m_CallbacksSync.erase(it)) {
            for(auto fun = it->second.begin(); fun != it->second.end(); fun = it->second.erase(fun)) {
                delete *fun;
            }
        }

        for(auto it = m_CallbacksAsync.begin(); it != m_CallbacksAsync.end(); it = m_CallbacksAsync.erase(it)) {
            for(auto fun = it->second.begin(); fun != it->second.end(); fun = it->second.erase(fun)) {
                delete *fun;
            }
        }
    }

    void EventManager::ClearEventQueue() noexcept {
        while(!m_EventQueue.empty()) {
            auto ev = m_EventQueue.back();
            delete ev;
            m_EventQueue.pop_back();
        }
    }

} //END OF NAMESPACE Bald
