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
    typedef std::list<BaseHandler*> HandlersList;

    enum HandlerType {
        SyncHandler = 0,
        AsyncHandler = 1
    };

    class EventBus {
    public:
        template<typename EventType>
        static void emit(EventType* e) noexcept {
            HandlersList * handlers = m_subscribers[typeid(EventType)];

            if (handlers == nullptr) return;

            for (auto & handler : *handlers) {
                if (handler != nullptr) {
                    handler->exec(e);
                }
            }
        }

        template<class T, class EventType>
        static void subscribe(T* instance, void (T::*handler_function)(EventType*), HandlerType hType = SyncHandler) noexcept {
            HandlersList * handlers = m_subscribers[typeid(EventType)];

            if (handlers == nullptr) {
                handlers = new HandlersList();
                m_subscribers[typeid(EventType)] = handlers;
            }

            if (hType == SyncHandler) {
                handlers->push_back(new MemberHandler<T, EventType>(instance, handler_function));
            } else if (hType == AsyncHandler) {
                handlers->push_back(new MemberAsyncHandler<T, EventType>(instance, handler_function));
            } else {
                return;
            }
        }

        template<class T, class EventType>
        constexpr static void unsubscribe(T* instance, void(T::*handler_function)(EventType*)) noexcept {
            HandlersList * handlers = m_subscribers[typeid(EventType)];
            std::remove_if(handlers->begin(), handlers->end(), [&](BaseHandler* const& h){
                auto h_casted = static_cast<FunctionHandler<T, EventType>*>(h);
                return (*h_casted)(instance, handler_function);
            });
        }
    private:
        static std::unordered_map<std::type_index, HandlersList*> m_subscribers;
    };

    std::unordered_map<std::type_index, HandlersList*> EventBus::m_subscribers;
}