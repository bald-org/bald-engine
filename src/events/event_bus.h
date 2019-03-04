//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once

#include <list>
#include <queue>

#include "pch.h"
#include "base_handler.h"
#include "function_handler.h"
#include "member_handler.h"
#include "member_async_handler.h"


namespace Bald::Events {
    using HandlersVector = std::vector<BaseHandler *>;

    /**
     * Enum, which represents types of handlers
     */
    enum class HandlerType {
        SyncHandler = 0, /** Sync handler **/
        AsyncHandler = 1 /** Async handler **/
    };

    /**
     * @class                                                   EventBus
     * @brief                                                   Static class, which takes care of events
     */
    class EventBus {
    public:
        /**
         * @fn                                                  clearEvent
         * @brief                                               Function, which deletes event of certain type
         * @tparam EventType                                    Type of event to clear
         * @param [Event*] e                                    Pointer to event type
         */
        template<class EventType>
        static void clearEvent(EventType *e) {
            static_assert(std::is_base_of<Event, EventType>::value, "Event is not the base of EventType");
            delete e;
        }

        /**
         * @fn                                                  clearHandler
         * @brief                                               Function, which deletes handler
         * @param [BaseHandler*] h                              Pointer to handler
         */
        static void clearHandler(BaseHandler *h) {
            delete h;
        }

        /**
         * @fn                                                  clearHandlers
         * @brief                                               Function, which deletes handlers vector
         * @param [HandlersList*] h                             Pointer to handlers list
         */
        static void clearHandlers(HandlersVector *hl) {
            std::for_each(hl->begin(), hl->end(), [](BaseHandler *h) {
                EventBus::clearHandler(h);
            });
            hl->clear();
            delete hl;
        }

        /**
         * @fn                                                  clearByEventType
         * @brief                                               Function, which clears whole vector of handlers of certain event type
         * @tparam EventType                                    Type of event
         */
        template<class EventType>
        static void clearByEventType() {
            static_assert(std::is_base_of<Event, EventType>::value, "Event is not the base of EventType");
            HandlersVector *handlers = m_Subscribers[EventType::eventId];

            EventBus::clearHandlers(handlers);
        }

        /**
         * @fn                                                  clearEventQueue
         * @brief                                               Function, which clears whole queue of events
         */
        static void clearEventQueue() {
            std::for_each(m_EventQueue.begin(), m_EventQueue.end(), [](Event* e){
                EventBus::clearEvent(e);
            });
            m_EventQueue.clear();
        }

        /**
         * @fn                                                  cleanUp
         * @brief                                               Function, which cleans all event related stuff
         */
        static void cleanUp() {
            EventBus::clearEventQueue();
            EventBus::flush();
        }

        /**
         * @fn                                                  emit
         * @brief                                               Function, which emits certain event and takes care of doing it
         * @tparam EventType                                    Type of event
         * @param [EventType*] e                                Pointer to type of event
         */
        template<typename EventType>
        static void emit(EventType *e) {
            static_assert(std::is_base_of<Event, EventType>::value, "Event is not the base of EventType");
            m_EventQueue.push_back(e);
        }

        /**
         * @fn                                                  flush
         * @brief                                               Function, which clears whole handlers map
         */
        static void flush() noexcept {
            std::for_each(m_Subscribers.begin(), m_Subscribers.end(),
                          [](const std::pair<unsigned int, HandlersVector *> p) {
                              EventBus::clearHandlers(p.second);
                          });
        }

        /**
         * @fn                                                  isEventInQueue
         * @brief                                               Function, which checks whether event is in queue
         * @tparam EventType                                    Type of event
         * @result Boolean                                      Presence of event
         */
        static bool isEventInQueue(unsigned int& eId) {
            for(auto e : m_EventQueue) {
                if (e->getId() == eId) {
                    return true;
                }
            }
            return false;
        }

        /**
         * @fn                                                  runEventQueue
         * @brief                                               Gets thru event queue and calls all handlers
         */
        static void runEventQueue() {
            for(auto e : m_EventQueue) {
                HandlersVector *handlers = m_Subscribers[e->getId()];
                if (handlers == nullptr) {
                    return;
                }
                for (auto &handler : *handlers) {
                    if (handler != nullptr) {
                        handler->exec(e);
                    }
                }
                EventBus::clearEvent(e);
            }
            m_EventQueue.clear();
        }

        /**
         * @fn                                                  subscribe
         * @brief                                               Function, via which you can subscribe for certain event
         * @tparam T                                            Type of instance, where handler function is
         * @tparam EventType                                    Type of event to subscribe to
         * @param [T*] instance                                 Instance, where handler function is
         * @param [void (T::*)(EventType*)] handler_function    Pointer to function, which will be invoked at event
         * @param [HandlerType] hType                           Type of handler, which will be invoking the function
         * @result [unsigned int]                               Handler ID
         */
        template<class T, class EventType>
        static unsigned int subscribe(T *instance, void (T::*handler_function)(EventType *),
                              HandlerType hType = HandlerType::SyncHandler) noexcept {
            static_assert(std::is_base_of<Event, EventType>::value, "Event is not the base of EventType");
            HandlersVector *handlers = m_Subscribers[EventType::eventId];

            if (handlers == nullptr) {
                handlers = new HandlersVector();
                m_Subscribers[EventType::eventId] = handlers;
            }

            switch (hType) {
                case HandlerType::SyncHandler: {
                    auto mh = new MemberHandler<T, EventType>(instance, handler_function);
                    handlers->push_back(mh);
                    return mh->handlerId;
                }
                case HandlerType::AsyncHandler: {
                    auto mha = new MemberAsyncHandler<T, EventType>(instance, handler_function);
                    handlers->push_back(mha);
                    return mha->handlerId;
                }
                default:
                    return 0; /** It's needed to shut the warning up **/
            }
        }

        /**
         * @fn                                                  unsubscribe
         * @brief                                               Function, via which you can remove handler from event
         * @tparam EventType                                    Type of event to remove handler from
         * @param [unsigned int] hId                            ID of Handler
         */
        template<class EventType>
        static void unsubscribe(unsigned int hId) {
            static_assert(std::is_base_of<Event, EventType>::value, "Event is not the base of EventType");
            HandlersVector *handlers = m_Subscribers[EventType::eventId];

            unsigned int i = 0;

            for (auto h : *handlers) {
                if ((*h)(hId)) {
                    handlers->erase(handlers->begin() + i);
                    EventBus::clearHandler(h);
                }
                ++i;
            }
        }

    private:
        static std::unordered_map<unsigned int, HandlersVector *> m_Subscribers; /** Map of event types to it's handlers list **/
        static std::deque<Event*> m_EventQueue; /** Queue of events to handle **/
    };

    std::unordered_map<unsigned int, HandlersVector *> EventBus::m_Subscribers;
    std::deque<Event*> EventBus::m_EventQueue;
}