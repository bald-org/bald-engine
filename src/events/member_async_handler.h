//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once
#include <future>

#include "event.h"
#include "function_handler.h"

namespace Bald::Events {
    template<class T, class EventType>
    class MemberAsyncHandler : public FunctionHandler<T, EventType> {
    public:
        typedef void (T::*HandlerFunction)(EventType*);
        MemberAsyncHandler(T* instance, HandlerFunction handler_function): FunctionHandler<T, EventType>(instance, handler_function) {};
    private:
        void call(Event* e) noexcept override {
            // TODO: Isn't it working sync cuz of .get() ?
            //auto handle = std::async(std::launch::async, FunctionHandler<T, EventType>::m_instance->*FunctionHandler<T, EventType>::m_handler_function, static_cast<EventType*>(e));
            //handle.get();
        }
    };
}

