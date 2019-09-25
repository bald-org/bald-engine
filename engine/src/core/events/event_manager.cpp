//
// Created by grzegorz on 19.02.19.
//

#include "event_manager.h"
#include <future>
#include "assert.h"

namespace Bald {

    std::vector<Event*> EventManager::m_EventQueue;
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
        CORE_LOG_INFO("[EventManager] Actual number of EventManagers: " + std::to_string(m_ReferenceCounter));
        return m_ReferenceCounter > 0;
    }

    void EventManager::Shutdown() {
        CORE_LOG_INFO("[EventManager] Shutting down EventManager...");
        RemoveAllCallbacks();
        --m_ReferenceCounter;
        CORE_LOG_INFO("[EventManager] Actual number of EventManagers: " + std::to_string(m_ReferenceCounter));
        if (m_ReferenceCounter == 0) {
            CORE_LOG_INFO("[EventManager] This was last one EventManager");
            CORE_LOG_INFO("[EventManager] Clearing event queue...");
            ClearEventQueue();
            CORE_LOG_INFO("[EventManager] Clearing event queue was successful");
        }
        CORE_LOG_INFO("[EventManager] Shutdown was successful");
    }

    void EventManager::Flush() noexcept {
        for (auto & it : m_EventQueue) {
            const auto& async_callbacks = m_CallbacksAsync.find(it->GetType());
            const auto& sync_callbacks = m_CallbacksSync.find(it->GetType());

            if (async_callbacks == m_CallbacksAsync.end() && sync_callbacks == m_CallbacksSync.end()) {
                continue;
            }
            std::vector<std::future<void>> ft;
            if (async_callbacks != m_CallbacksAsync.end()) { //TODO: investigate impact of resizing std::vector -> ft to correct size inside this if
                for (const auto& fun : async_callbacks->second) {
                    ft.emplace_back(std::async(std::launch::async, [&it, &fun]() {
                        fun->Run(*it);
                    }));
                }
            }

            if (sync_callbacks != m_CallbacksSync.end()) {
                for (const auto& fun : sync_callbacks->second) fun->Run(*it);
            }

            for (const auto& f : ft) {
                f.wait();
            }

            delete it;
            it = nullptr;
        }
        m_EventQueue.erase(std::remove(m_EventQueue.begin(), m_EventQueue.end(), nullptr), m_EventQueue.end());
    }

    void EventManager::RemoveAllCallbacks() noexcept {
        for (auto& it : m_CallbacksSync) {
            for (const auto& fun : it.second) delete fun;
            it.second.erase(it.second.begin(), it.second.end());
        }
        m_CallbacksSync.erase(m_CallbacksSync.begin(), m_CallbacksSync.end());

        for (auto& it : m_CallbacksAsync) {
            for (const auto& fun : it.second) delete fun;
            it.second.erase(it.second.begin(), it.second.end());
        }
        m_CallbacksAsync.erase(m_CallbacksAsync.begin(), m_CallbacksAsync.end());
    }

    void EventManager::ClearEventQueue() noexcept {
        for (const auto& elem : m_EventQueue)
            delete elem;
        m_EventQueue.clear();
    }

} //END OF NAMESPACE Bald
