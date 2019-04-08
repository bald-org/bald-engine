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

    enum class HandleType {
        SYNC, ASYNC
    };

    class EventManager {
    public:

        EventManager() = delete;

        template<class T, class F, class... Args>
        static unsigned Subscribe(HandleType type, F&& callback, Args&& ... args);

        template<class T>
        static void Unsubscibe(unsigned id) noexcept;

        template<class T, class... Args>
        static void Emit(Args&& ... args);

        template<class T>
        [[nodiscard]] static bool IsEventInQueue() noexcept;

        template<class T>
        static void RemoveAllCallbacksByType() noexcept;

        static void Flush(int n = -1) noexcept;

        static void CleanUp() noexcept;

    private:
        static inline void Call() noexcept;

    public:
        static std::unordered_map<std::type_index, std::vector<Callback*>*> m_Callbacks; //TODO: Store callback in some structure to make possibe to delete them
        static std::deque<Event*> m_EventQueue;
    }; // END OF CLASS EventManager

    template<class T, class F, class... Args>
    unsigned EventManager::Subscribe(HandleType type, F&& callback, Args&& ... args) {

        static_assert(std::is_base_of<Event, T>::value, "Event is not the base of T");

        if(m_Callbacks.find(typeid(T)) == m_Callbacks.end()) {
            m_Callbacks[typeid(T)] = new std::vector<Callback*>;
        }

        switch(type) {
            case HandleType::SYNC:
                m_Callbacks[typeid(T)]->push_back(new FunctionHandler(callback, args...));
                break;
            case HandleType::ASYNC:
                m_Callbacks[typeid(T)]->push_back(new AsyncFunctionHandler(callback, args...));
                break;
        }

        return m_Callbacks[typeid(T)]->back()->getID();
    }

    template<class T>
    void EventManager::Unsubscibe(unsigned id) noexcept {
        static_assert(std::is_base_of<Event, T>::value, "Event is not the base of T");
        auto iter = m_Callbacks.find(typeid(T));

        if(iter == m_Callbacks.end()) return;

        auto vector = iter->second;

        for(auto i = vector->begin(); i != vector->end(); ++i) {
            if((**i) == id) {
                delete *i;
                vector->erase(i);
                return;
            }
        }
    }

    template<class T, class... Args>
    void EventManager::Emit(Args&& ... args) {
        static_assert(std::is_base_of<Event, T>::value, "Event is not the base of T");

        T* event = new T{args...};
        event->EmitConnectedEvents();
        m_EventQueue.push_back(event);
    }

    template<class T>
    bool EventManager::IsEventInQueue() noexcept {
        static_assert(std::is_base_of<Event, T>::value, "Event is not the base of T");
        for(auto ev : m_EventQueue) {
            if(ev->Type() == typeid(T)) return true;
        }
        return false;
    }

    template<class T>
    void EventManager::RemoveAllCallbacksByType() noexcept {
        auto iter = m_Callbacks.find(typeid(T));
        if(iter == m_Callbacks.end()) return;

        while(!iter->second->empty()) {
            delete iter->second->back();
            iter->second->pop_back();
        }
    }

} //END OF NAMESPACE Bald
