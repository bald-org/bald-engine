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
        ++m_ReferenceCounter;
        return m_ReferenceCounter > 0;
    }

    void EventManager::Shutdown() {
        RemoveAllCallbacks();
        --m_ReferenceCounter;
        if(m_ReferenceCounter == 0){
            ClearEventsQueue();
        }
    }

    void EventManager::Call() noexcept {
        Event* event = m_EventQueue.front();

        auto callbacks = m_Callbacks.find(event->Type());

        if(callbacks == m_Callbacks.end()) {
            return;
        }

        for(auto& fun : *callbacks->second) fun->Run(*event);

        m_EventQueue.pop_front();
        delete event;
    }

    void EventManager::Flush(int n) noexcept {
        CORE_LOG_INFO("[EventManager] Flushing events...");
        if(n == -1) {
            while(!m_EventQueue.empty()) Call();
        } else {
            for(int i = 0; i < n; ++i) if(m_EventQueue.empty()) return; else Call();
        }
        CORE_LOG_INFO("[EventManager] Flush was successful");
    }

    void EventManager::RemoveAllCallbacks() noexcept {
        std::for_each(m_Callbacks.begin(), m_Callbacks.end(), [](std::pair<std::type_index, std::vector<EventHandlerInterface*>*>&& pair) {
            std::for_each(pair.second->begin(), pair.second->end(), [](EventHandlerInterface* handler) { delete handler; });
            delete pair.second;
        });
    }

    void EventManager::ClearEventsQueue() noexcept {
        std::for_each(m_EventQueue.begin(), m_EventQueue.end(), [](Event* ev) { delete ev; });
    }

} //END OF NAMESPACE Bald
