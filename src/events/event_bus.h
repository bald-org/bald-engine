//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once

#include <list>
#include <typeindex>

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
        }

        /**
         * @fn                                                  clear
         * @brief                                               Function, which clears whole vector of handlers of certain event type
         * @tparam EventType                                    Type of event
         */
        template<class EventType>
        static void clear() {
            HandlersVector *handlers = m_Subscribers[typeid(EventType)];

            EventBus::clearHandlers(handlers);
        }

        /**
         * @fn                                                  emit
         * @brief                                               Function, which emits certain event and takes care of doing it
         * @tparam EventType                                    Type of event
         * @param [EventType*] e                                Pointer to type of event
         */
        template<typename EventType>
        static void emit(EventType *e) {
            HandlersVector *handlers = m_Subscribers[typeid(EventType)];

            if (handlers == nullptr) return;

            for (auto &handler : *handlers) {
                if (handler != nullptr) {
                    handler->exec(e);
                }
            }

            EventBus::clearEvent(e);
        }

        /**
         * @fn                                                  flush
         * @brief                                               Function, which clears whole handlers map
         */
        static void flush() noexcept {
            std::for_each(m_Subscribers.begin(), m_Subscribers.end(),
                          [](const std::pair<std::type_index, HandlersVector *> p) {
                              EventBus::clearHandlers(p.second);
                          });
        }

        /**
         * @fn                                                  subscribe
         * @brief                                               Function, via which you can subscribe for certain event
         * @tparam T                                            Type of instance, where handler function is
         * @tparam EventType                                    Type of event to subscribe to
         * @param [T*] instance                                 Instance, where handler function is
         * @param [void (T::*)(EventType*)] handler_function    Pointer to function, which will be invoked at event
         * @param [HandlerType] hType                           Type of handler, which will be invoking the function
         */
        template<class T, class EventType>
        static void subscribe(T *instance, void (T::*handler_function)(EventType *),
                              HandlerType hType = HandlerType::SyncHandler) noexcept {
            HandlersVector *handlers = m_Subscribers[typeid(EventType)];

            if (handlers == nullptr) {
                handlers = new HandlersVector();
                m_Subscribers[typeid(EventType)] = handlers;
            }

            switch (hType) {
                case HandlerType::SyncHandler:
                    handlers->push_back(new MemberHandler<T, EventType>(instance, handler_function));
                    break;
                case HandlerType::AsyncHandler:
                    handlers->push_back(new MemberAsyncHandler<T, EventType>(instance, handler_function));
                    break;
            }
        }

        /**
         * @fn                                                  unsubscribe
         * @brief                                               Function, via which you can remove handler from event
         * @tparam T                                            Type of instance, where handler function is
         * @tparam EventType                                    Type of event to remove handler from
         * @param [T*] instance                                 Instance, where handler function is
         * @param [void (T::*)(EventType*)] handler_function    Pointer to function, which will be invoked at event
         */
        template<class T, class EventType>
        static void unsubscribe(T *instance, void (T::*handler_function)(EventType *)) noexcept {
            HandlersVector *handlers = m_Subscribers[typeid(EventType)];

            for (auto h = handlers->begin(), e = handlers->end(); h != e;) {
                auto h_casted = dynamic_cast<FunctionHandler<T, EventType> *>(*h);
                if ((*h_casted)(instance, handler_function)) {
                    delete h_casted;
                    h = handlers->erase(h);
                } else
                    ++h;
            }
        }

    private:
        static std::unordered_map<std::type_index, HandlersVector *> m_Subscribers; /** Map of event types to it's handlers list **/
    };

    std::unordered_map<std::type_index, HandlersVector *> EventBus::m_Subscribers;
}