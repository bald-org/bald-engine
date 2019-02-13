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
    using HandlersList = std::vector<BaseHandler*>;

    enum class HandlerType {
        SyncHandler = 0,
        AsyncHandler = 1
    };

    class EventBus {
    public:
        template<class EventType>
        static void clearEvent(EventType* e) {
            delete e;
        }

        static void clearHandler(BaseHandler* h) {
            delete h;
        }

        static void clearHandlers(HandlersList* hl) {
            std::for_each(hl->begin(), hl->end(), [](BaseHandler* h){
               EventBus::clearHandler(h);
            });
            hl->clear();
        }

        template<class EventType>
        static void clear() {
            HandlersList * handlers = m_Subscribers[typeid(EventType)];

            EventBus::clearHandlers(handlers);
        }

        template<typename EventType>
        static void emit(EventType* e) {
            HandlersList * handlers = m_Subscribers[typeid(EventType)];

            if (handlers == nullptr) return;

            for (auto & handler : *handlers) {
                if (handler != nullptr) {
                    handler->exec(e);
                }
            }

            EventBus::clearEvent(e);
        }

        static void flush() noexcept {
            std::for_each(m_Subscribers.begin(), m_Subscribers.end(), [](const std::pair<std::type_index, HandlersList*> p){
                EventBus::clearHandlers(p.second);
            });
        }

        template<class T, class EventType>
        static void subscribe(T* instance, void (T::*handler_function)(EventType*), HandlerType hType = HandlerType::SyncHandler) noexcept {
            HandlersList * handlers = m_Subscribers[typeid(EventType)];

            if (handlers == nullptr) {
                handlers = new HandlersList();
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

        template<class T, class EventType>
        static void unsubscribe(T* instance, void (T::*handler_function)(EventType*)) noexcept {
            HandlersList * handlers = m_Subscribers[typeid(EventType)];

            for (auto h = handlers->begin(), e = handlers->end(); h != e; )
            {
                auto h_casted = dynamic_cast<FunctionHandler<T, EventType>*>(*h);
                if ((*h_casted)(instance, handler_function)) {
                    delete h_casted;
                    h = handlers->erase(h);
                }
                else
                    ++h;
            }
        }
    private:
        static std::unordered_map<std::type_index, HandlersList*> m_Subscribers;
    };

    std::unordered_map<std::type_index, HandlersList*> EventBus::m_Subscribers;
}