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
#include "key_events.h"
#include "callback/handler.h"
#include "callback/function_handler.h"
#include "callback/async_function_handler.h"

/**
 * @class EventManager
 * @brief Central event bus. Right now this class is responsible for
 *        managing all engine's events.
 */

namespace Bald {

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
        static void Unsubscibe(HandleType type, unsigned id) noexcept;

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
        static std::deque<Event*> m_EventQueue; /**< Basically an event queue */
    }; // END OF CLASS EventManager

    template<class T, class F, class... Args>
    unsigned EventManager::Subscribe(HandleType type, F&& callback, Args&& ... args) {
        static_assert(std::is_base_of<Event, T>::value, "Event is not the base of T");

        switch(type) {
            case HandleType::SYNC:
                Bald::Subscribe(FunctionHandler<T>(callback, args...)); //TODO: probably to make it this way we have to define move  constructor or make it on the heap
                break;
            case HandleType::ASYNC:
                Bald::Subscribe(AsyncFunctionHandler<T>(callback, args...));
                break;
        }

        return 1; //TODO: we have to send user ID of what we created
    }

    template<class T>
    void EventManager::Unsubscibe(HandleType type, unsigned id) noexcept {
        static_assert(std::is_base_of<Event, T>::value, "Event is not the base of T");
        Bald::Unsubscibe<T>(type, id);
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
        return false;
    }

    template<class T>
    void EventManager::RemoveAllCallbacksByType() noexcept {

    }

} //END OF NAMESPACE Bald
