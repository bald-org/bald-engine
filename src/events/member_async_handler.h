//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once
#include <future>

#include "event.h"
#include "base_handler.h"

namespace Bald::Events {
    template<class T, class EventType>
    class MemberAsyncHandler : public BaseHandler<T, EventType> {
    public:
        typedef void (T::*HandlerFunction)(EventType*);
        MemberAsyncHandler(T* instance, HandlerFunction handler_function): BaseHandler<T, EventType>(instance, handler_function) {};
    private:
        void call(Event* e) noexcept override {
            std::async(std::launch::async, (BaseHandler<T, EventType>::m_instance->*BaseHandler<T, EventType>::m_handler_function)(static_cast<EventType*>(e)));
        }
    };
}

