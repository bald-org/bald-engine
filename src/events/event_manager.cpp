//
// Created by grzegorz on 19.02.19.
//

#include "event_manager.h"

namespace Bald {

    std::unordered_map<std::type_index, std::vector<Callback*>*> EventManager::m_Callbacks;
    std::deque<Event*> EventManager::m_EventQueue;

    void EventManager::Call() noexcept {
        Event* event = m_EventQueue.front();
        m_EventQueue.pop_front();

        auto callbacks = m_Callbacks.find(event->Type());

        if(callbacks == m_Callbacks.end()) {
            delete event;
            return;
        }

        for(auto& fun : *callbacks->second) fun->run();

        delete event;
    }

    void EventManager::Flush(int n) noexcept {
        if(n == -1) {
            while(!m_EventQueue.empty()) Call();
        } else {
            for(int i = 0; i < n; ++i) if(m_EventQueue.empty()) return; else Call();
        }
    }

    void EventManager::CleanUp() noexcept {
        std::for_each(m_EventQueue.begin(), m_EventQueue.end(), [](Event* ev) { delete ev; });
        for(auto a : m_Callbacks) {

            for(auto b: *a.second) {
                delete b;
            }

            delete a.second;
        }
    }
} //END OF NAMESPACE Bald