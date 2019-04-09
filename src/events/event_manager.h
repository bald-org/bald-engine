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
#include "callback/handler.h"
#include "callback/function_handler.h"
#include "callback/async_function_handler.h"

/**
 * @class EventManager
 * @brief Central event bus. Right now this class is responsible for
 *        managing all engine's events.
 */

namespace Bald {

    enum class HandleType {
        SYNC, ASYNC
    };

    class EventManager {
    public:
        /**
        * @fn       EventManager
        * @brief    Constructor is deleted because this class is just a system,
        *           meaning you cannot instantiate it
        */
        EventManager() = delete;

        /**
        * @fn                    Subscribe
        * @brief                 Templated function which allows you to subscribe to any kind of engine's event
        * @param [HandleType]    type -> Manner in which the function will be handled e.g. synchronous/asynchronous
        * @param [F&&]           callback -> Function with which you subscribe to an event
        * @param [Args&& ...]    args -> Function's arguments
        */

        template<class T, class F, class... Args>
        static unsigned Subscribe(HandleType type, F&& callback, Args&& ... args);

        /**
        * @fn                    Unsubscribe
        * @brief                 Templated function which allows you to unsubscribe from any kind of engine's event
        * @param [unsigned]      id -> Handler id, meaning id of a function you want to get rid of
        */

        template<class T>
        static void Unsubscibe(unsigned id) noexcept;

        /**
        * @fn                    Emit
        * @brief                 Templated function which is used to emit events of any kind
        * @param [Args&& ...]    args -> Arguments for event's constructor (can be left blank)
        */

        template<class T, class... Args>
        static void Emit(Args&& ... args);

        /**
        * @fn                    IsEventInQueue
        * @brief                 Templated function checks whether or not certain event was emitted
        */

        template<class T>
        [[nodiscard]] static bool IsEventInQueue() noexcept;

        /**
        * @fn                    RemoveAllCallbacksByType
        * @brief                 Templated function which removes all event handlers for a specified event
        */

        template<class T>
        static void RemoveAllCallbacksByType() noexcept;

        /**
        * @fn                    Flush
        * @brief                 This function runs callbacks for all events that are currently in an event queue
        * @param [int]           n -> Number of events you want to proceed. If n == -1 (or argumeter left blank)
        *                             this will iterate through whole queue
        */

        static void Flush(int n = -1) noexcept;

        /**
        * @fn                    Flush
        * @brief                 This function should be called at the end of program to clean up allocated memory
        */

        static void CleanUp() noexcept;

    private:

        /**
        * @fn                    Call
        * @brief                 This function pops first element of the queue and runs all functions associated with that event
        */

        static inline void Call() noexcept;

    public:
        static std::unordered_map<std::type_index, std::vector<Handler*>*> m_Callbacks; /**< Unordered map of events' type indexes and associated functions */
        static std::deque<Event*> m_EventQueue; /**< Basically an event queue */
    }; // END OF CLASS EventManager

    template<class T, class F, class... Args>
    unsigned EventManager::Subscribe(HandleType type, F&& callback, Args&& ... args) {

        static_assert(std::is_base_of<Event, T>::value, "Event is not the base of T");

        if(m_Callbacks.find(typeid(T)) == m_Callbacks.end()) {
            m_Callbacks[typeid(T)] = new std::vector<Handler*>;
        }

        switch(type) {
            case HandleType::SYNC:
                m_Callbacks[typeid(T)]->push_back(new FunctionHandler(callback, args...));
                break;
            case HandleType::ASYNC:
                m_Callbacks[typeid(T)]->push_back(new AsyncFunctionHandler(callback, args...));
                break;
        }

        return m_Callbacks[typeid(T)]->back()->GetID();
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
