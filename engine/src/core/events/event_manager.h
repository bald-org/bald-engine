//
// Created by grzegorz on 19.02.19.
//

#pragma once

#include <unordered_map>
#include <functional>
#include <deque>
#include <vector>

#include "event.h"
#include "callback/event_handler.h"
#include "callback/event_function_handler.h"
#include "type_name.h"
#include "core/debug/bald_assert.h"

namespace Bald {

    enum class HandleType {
        SYNC, ASYNC
    };

    /**
     * @class EventManager
     * @brief Central event bus. Right now this class is responsible for
     *        managing all engine's events.
     */

    class EventManager {
    GENERATE_BODY()
    public:

        /**
        * @fn EventManager
        * @brief EventManager constructor. Its role is to increase the static reference counter variable
        */

        EventManager();

        /**
         * @fn ~EventManager
         * @brief destroys Event Manager object
         */

        ~EventManager();

        /**
        * @fn Subscribe
        * @brief Templated function which allows you to subscribe to any kind of engine's event.
         * For example:
         * with lambda: Subscribe<type of event>(HandleType::SYNC, [](const type of event&){ do something; });
         * with method: Subscribe<type of event>(HandleType::SYNC, method pointer, object on which method will be called, rest of arguments that will be needed to call the method);
        * @param [HandleType] type -> Manner in which the function will be handled e.g. synchronous/asynchronous
        * @param [F&&] callback -> Function with which you subscribe to an event. It MUST take Event reference as the first parameter
        * @param [Args&& ...]    args -> Function's arguments
        */

        template<class T, class F, class... Args>
        unsigned Subscribe(HandleType type, F&& callback, Args&& ... args);

        /**
        * @fn Unsubscribe
        * @brief Templated function which allows you to unsubscribe from any kind of engine's event
        * @param [unsigned] id -> Handler id, meaning id of a function you want to get rid of
        */

        template<class T>
        void Unsubscibe(unsigned id) noexcept;

        /**
        * @fn Emit
        * @brief Templated function which is used to emit events of any kind
        * @param [Args&& ...]    args -> Arguments for event's constructor (can be left blank)
        */

        template<class T, class... Args>
        static void Emit(Args&& ... args);

        /**
        * @fn IsEventInQueue
        * @brief Templated function checks whether or not certain event was emitted
        */

        template<class T>
        [[nodiscard]] static bool IsEventInQueue() noexcept;

        /**
        * @fn RemoveAllCallbacksByType
        * @brief Templated function which removes all event handlers for a specified event
        */

        template<class T>
        void RemoveAllCallbacksByType() noexcept;

        /**
         * @fn RemoveAllCallbacks
         * @brief removes all handlers for every event
         */

        void RemoveAllCallbacks() noexcept;

        /**
         * @fn ClearEventQueue
         * @brief deletes all events form queue
         */

        static void ClearEventQueue() noexcept;

        /**
        * @fn Flush
        * @brief This function runs callbacks for all events that are currently in an event queue
        * @param [int] n -> Number of events you want to proceed. If n == -1 (or argumeter left blank)
        *                             this will iterate through whole queue
        */

        void Flush() noexcept;

    private:

        /**
         * @fn Init
         * @brief Initialize Event Manager object
         * @return [bool] true -> if initialization was successful
         *                false -> if initialization was not successful
         */

        bool Init();

        /**
         * @fn Shutdown
         * @brief destroys Event Manager object if it is the last one also clears event queue
         */

        void Shutdown();

    private:
        std::unordered_map<unsigned, std::vector<EventHandlerInterface*>> m_CallbacksSync; /**< Unordered map of events' type indexes and associated functions which will be called synchronously */
        std::unordered_map<unsigned, std::vector<EventHandlerInterface*>> m_CallbacksAsync; /**< Unordered map of events' type indexes and associated functions which will be called asynchronously */
        static std::deque<Event*> m_EventQueue; /**< Basically an event queue */
        static int m_ReferenceCounter; /**< Number of existing EventManagers >*/

    }; // END OF CLASS EventManager

    template<class T, class F, class... Args>
    unsigned EventManager::Subscribe(HandleType type, F&& callback, Args&& ... args) {
        BALD_STATIC_ASSERT(std::is_base_of<Event, T>::value, "Event is not the base of T");
        CORE_LOG_INFO("[EventManager] Subscribing function " + Utils::type_name<F>() + " to an " + Utils::type_name<T>() + " ...");

        switch(type) {
            case HandleType::SYNC: {
                if(m_CallbacksSync.find(Utils::get_type_id<T>()) == m_CallbacksSync.end()) {
                    m_CallbacksSync[Utils::get_type_id<T>()] = std::vector<EventHandlerInterface*>{};
                }
                m_CallbacksSync[Utils::get_type_id<T>()].emplace_back(new EventFunctionHandler<T>(callback, args...));
                CORE_LOG_INFO("[EventManager] Subscribe was successful...");
                return m_CallbacksSync[Utils::get_type_id<T>()].back()->GetID();
            }
            case HandleType::ASYNC: {
                if(m_CallbacksAsync.find(Utils::get_type_id<T>()) == m_CallbacksAsync.end()) {
                    m_CallbacksAsync[Utils::get_type_id<T>()] = std::vector<EventHandlerInterface*>{};
                }
                m_CallbacksAsync[Utils::get_type_id<T>()].emplace_back(new EventFunctionHandler<T>(callback, args...));
                CORE_LOG_INFO("[EventManager] Subscribe was successful...");
                return m_CallbacksAsync[Utils::get_type_id<T>()].back()->GetID();
            }
            default:
                return 0;
        }
    }

    template<class T>
    void EventManager::Unsubscibe(unsigned id) noexcept {
        BALD_STATIC_ASSERT(std::is_base_of<Event, T>::value, "Event is not the base of T");
        CORE_LOG_INFO("[EventManager] Unsubscribing to an event...");

        auto iter = m_CallbacksSync.find(Utils::get_type_id<T>());
        if(iter == m_CallbacksSync.end()) {
            iter = m_CallbacksAsync.find(Utils::get_type_id<T>());
            if(iter == m_CallbacksAsync.end()) {
                return;
            }
        }

        auto& vector = iter->second;
        for(auto it = vector.begin(); it != vector.end(); ++it) {
            if((**it) == id) {
                delete *it;
                vector.erase(it);
                CORE_LOG_INFO("[EventManager] Unsubscribed was successful...");
                return;
            }
        }
        CORE_LOG_WARN("[EventManager] Unsubscribe failed...");
    }

    template<class T, class... Args>
    void EventManager::Emit(Args&& ... args) {
        BALD_STATIC_ASSERT(std::is_base_of<Event, T>::value, "Event is not the base of T");

        T* event = new T{args...};
        m_EventQueue.push_back(event);
    }

    template<class T>
    bool EventManager::IsEventInQueue() noexcept {
        BALD_STATIC_ASSERT(std::is_base_of<Event, T>::value, "Event is not the base of T");

        for(auto ev : m_EventQueue) {
            if(ev->GetType() == Utils::get_type_id<T>()) return true;
        }

        return false;
    }

    template<class T>
    void EventManager::RemoveAllCallbacksByType() noexcept {
        BALD_STATIC_ASSERT(std::is_base_of<Event, T>::value, "Event is not the base of T");
        CORE_LOG_INFO("[EventManager] Removing all callbacks by type...");

        auto iter = m_CallbacksSync.find(Utils::get_type_id<T>());
        if(iter != m_CallbacksSync.end()) {
            while(!iter->second.empty()) {
                delete iter->second.back();
                iter->second.pop_back();
            }
        }

        iter = m_CallbacksAsync.find(Utils::get_type_id<T>());
        if(iter != m_CallbacksAsync.end()) {
            while(!iter->second.empty()) {
                delete iter->second.back();
                iter->second.pop_back();
            }
        }

        CORE_LOG_INFO("[EventManager] Removed all callbacks by type successfully");
    }

} //END OF NAMESPACE Bald
