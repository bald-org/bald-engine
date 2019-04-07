//
// Created by grzegorz on 19.02.19.
//

#pragma once

#include <unordered_map>
#include <functional>
#include <deque>
#include <vector>
#include <typeindex>
#include <typeinfo>

#include "event.h"
#include "callback/callback.h"
#include "callback/function_handler.h"
#include "callback/async_function_handler.h"

namespace Bald {

    enum class handle {
        sync, async
    };

    class EventManager {
    public:

        EventManager() = delete;

        template<class T, class F, class... Args>
        static unsigned Subscribe(handle type, F&& callback, Args&& ... args);

        template<class T>
        static void Unsubscibe(unsigned id);

        template<class T>
        static void RemoveAllCallbacks();

        template<class T, class... Args>
        static void Emit(Args&& ... args);

        template<class T>
        static bool IsEventInQueue();

        static void CleanUp();

        static void Flush(int n = -1);

    private:
        static inline void call();

    public:
        static std::unordered_map<std::type_index, std::vector<Callback*>*> _events_callbacks; //TODO: Store callback in some structure to make possibe to delete them
        static std::deque<Event*> _events_queue;
    }; // END OF CLASS EventManager

    template<class T, class... Args>
    void EventManager::Emit(Args&& ... args) {
        static_assert(std::is_base_of<Event, T>::value, "Event is not the base of T");

        T* event = new T{args...};
        event->EmitConnectedEvents();
        _events_queue.push_back(event);
    }

    template<class T, class F, class... Args>
    unsigned EventManager::Subscribe(handle type, F&& callback, Args&& ... args) {

        static_assert(std::is_base_of<Event, T>::value, "Event is not the base of T");

        if(_events_callbacks.find(typeid(T)) == _events_callbacks.end()) {
            _events_callbacks[typeid(T)] = new std::vector<Callback*>;
        }

        switch(type) {
            case handle::sync:
                _events_callbacks[typeid(T)]->push_back(new FunctionHandler(callback, args...));
                break;
            case handle::async:
                _events_callbacks[typeid(T)]->push_back(new AsyncFunctionHandler(callback, args...));
                break;
        }

        return _events_callbacks[typeid(T)]->back()->getID();
    }

    template<class T>
    void EventManager::RemoveAllCallbacks() {
        auto iter = _events_callbacks.find(typeid(T));
        if(iter == _events_callbacks.end()) return;

        while(!iter->second->empty()) {
            delete iter->second->back();
            iter->second->pop_back();
        }
    }

    template<class T>
    bool EventManager::IsEventInQueue() {
        static_assert(std::is_base_of<Event, T>::value, "Event is not the base of T");
        for(auto ev : _events_queue) {
            if(ev->Type() == typeid(T)) return true;
        }
        return false;
    }

    template<class T>
    void EventManager::Unsubscibe(unsigned id) {
        static_assert(std::is_base_of<Event, T>::value, "Event is not the base of T");
        auto iter = _events_callbacks.find(typeid(T));

        if(iter == _events_callbacks.end()) return;

        auto vecotr = iter->second;

        for(auto i = vecotr->begin(); i != vecotr->end(); ++i) {
            if((**i) == id) {
                delete *i;
                vecotr->erase(i);
                return;
            }
        }
    }

} //END OF NAMESPACE Bald
