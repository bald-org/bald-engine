//
// Created by grzegorz on 19.02.19.
//

#include "event_manager.h"

namespace Bald {

    std::unordered_map<std::type_index, std::vector<Callback*>*> EventManager::_events_callbacks;
    std::deque<Event*> EventManager::_events_queue;

    void EventManager::call() {
        Event* event = _events_queue.front();
        _events_queue.pop_front();

        auto callbacks = _events_callbacks.find(event->Type());

        if(callbacks == _events_callbacks.end()) {
            delete event;
            return;
        }

        for(auto& fun : *callbacks->second) fun->run();

        delete event;
    }

    void EventManager::Flush(int n) {
        if(n == -1) {
            while(!_events_queue.empty()) call();
        } else {
            for(int i = 0; i < n; ++i) if(_events_queue.empty()) return; else call();
        }
    }

    void EventManager::CleanUp() {
        std::for_each(_events_queue.begin(), _events_queue.end(), [](Event* ev) { delete ev; });
        for(auto a : _events_callbacks) {

            for(auto b: *a.second) {
                delete b;
            }

            delete a.second;
        }
    }
} //END OF NAMESPACE Bald