//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once
#include "event.h"
#include "function_handler.h"

namespace Bald::Events {
    template<class T, class EventType>
    class MemberHandler : public FunctionHandler<T, EventType> {
    public:
        using HandlerFunction = void(T::*)(EventType*);

        constexpr MemberHandler(T* instance, HandlerFunction handler_function) noexcept : FunctionHandler<T, EventType>(instance, handler_function) {};
    private:
        constexpr void call(Event* e) const noexcept override {
            (FunctionHandler<T, EventType>::m_Instance->*FunctionHandler<T, EventType>::m_HandlerFunction)(static_cast<EventType*>(e));
        }
    };
}
