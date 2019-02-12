//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once
#include <future>

#include "event.h"
#include "base_handler.h"

namespace Bald::Events {
    template<class T, class EventType>
    class MemberAsyncHandler : public BaseHandler {
    public:
        typedef void (T::*HandlerFunction)(EventType*);
        MemberAsyncHandler(T* instance, HandlerFunction handler_function): m_instance(instance), m_handler_function(handler_function) {};

        void call(Event* e) noexcept override {
            std::async(std::launch::async, (m_instance->*m_handler_function)(static_cast<EventType*>(e)));
        }

        constexpr bool operator ()(T* other_instance, HandlerFunction other_handler_function) const noexcept {
            return m_instance == other_instance && m_handler_function == other_handler_function;
        }
    private:
        T* m_instance;
        HandlerFunction m_handler_function;
    };
}

