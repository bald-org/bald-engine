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
        using HandlerFunction = void(T::*)(EventType*);

        constexpr MemberAsyncHandler(T* instance, HandlerFunction handler_function) noexcept : FunctionHandler<T, EventType>(instance, handler_function) {};
    private:
        constexpr void call(Event* e) const noexcept override {
            auto handle = std::async([&](EventType* params) {
                (FunctionHandler<T, EventType>::m_Instance->*FunctionHandler<T, EventType>::m_HandlerFunction)(params);
            }, static_cast<EventType*>(e));
            handle.get();
        }
    };
}

