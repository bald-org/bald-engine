//
// Created by grzegorz on 19.02.19.
//

#include "event_manager.h"

namespace Bald {

    std::deque<Event*> EventManager::m_EventQueue;
    int EventManager::m_ReferenceCounter = 0;

    EventManager::EventManager() {
        [[maybe_unused]] bool state = Init();
        assert(state);
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

    void EventManager::Call() noexcept {
        Event* event = m_EventQueue.front();

        auto callbacks = m_Callbacks.find(event->GetType());

        if(callbacks == m_Callbacks.end()) {
            return;
        }

        for(auto& fun : *callbacks->second) fun->Run(*event);

        m_EventQueue.pop_front();
        delete event;
    }

    void EventManager::Flush(int n) noexcept {
        if(n == -1) {
            for(auto it = m_EventQueue.begin(); it != m_EventQueue.end();) {
                const auto& callbacks = m_Callbacks.find((*it)->GetType());

                if(callbacks == m_Callbacks.end()) {
                    ++it;
                    continue;
                }

                for(const auto& fun : *(callbacks)->second) fun->Run(**it);

                delete *it;
                it = m_EventQueue.erase(it);
            }
        } else {
            for(int i = 0; i < n; ++i) if(m_EventQueue.empty()) return; else Call();
        }
    }

    void EventManager::RemoveAllCallbacks() noexcept {
        std::for_each(m_Callbacks.begin(), m_Callbacks.end(), [](std::pair<std::type_index, std::vector<EventHandlerInterface*>*>&& pair) {
            std::for_each(pair.second->begin(), pair.second->end(), [](EventHandlerInterface* handler) { delete handler; });
            delete pair.second;
        });
    }

    void EventManager::ClearEventQueue() noexcept {
        while(!m_EventQueue.empty()) {
            auto ev = m_EventQueue.back();
            delete ev;
            m_EventQueue.pop_back();
        }
    }

} //END OF NAMESPACE Bald
