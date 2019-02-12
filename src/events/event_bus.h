//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once
#include <list>
#include <typeindex>

#include "pch.h"
#include "base_handler.h"
#include "member_handler.h"
#include "member_async_handler.h"


namespace Bald::Events {
    typedef std::list<BaseHandler*> HandlersList;

    class EventBus {
    public:
        template<typename EventType>
        void emit(EventType* e) noexcept {
            HandlersList * handlers = m_subscribers[typeid(EventType)];

            if (handlers == nullptr) return;

            for (auto & handler : *handlers) {
                if (handler != nullptr) {
                    handler->exec(e);
                }
            }
        }

        template<class T, class EventType, typename HandlerType>
        constexpr void subscribe(T* instance, void (T::*handler_function)(EventType*)) noexcept {
            HandlersList * handlers = m_subscribers[typeid(EventType)];

            if (handlers == nullptr) {
                handlers = new HandlersList();
                m_subscribers[typeid(EventType)] = handlers;
            }

            // TODO: This may be sooo bad :<
            auto new_handler = new HandlerType(instance, handler_function);

            handlers->push_back(new_handler);
        }

        template<class T, class EventType, typename HandlerType>
        constexpr void unsubscribe(T* instance, void(T::*handler_function)(EventType*)) noexcept {
            HandlersList * handlers = m_subscribers[typeid(EventType)];
            std::remove_if(handlers->begin(), handlers->end(), [&](BaseHandler* const& h){
                auto h_casted = static_cast<HandlerType*>(h);
                return (*h_casted)(instance, handler_function);
            });
        }
    private:
        std::unordered_map<std::type_index, HandlersList*> m_subscribers;
    };
}
