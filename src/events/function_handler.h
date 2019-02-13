//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once
#include "event.h"

namespace Bald::Events {
    template<class T, class EventType>
    class FunctionHandler : public BaseHandler {
    public:
        typedef void (T::*HandlerFunction)(EventType*);

        constexpr FunctionHandler(T* instance, HandlerFunction handler_function) noexcept : m_Instance(instance), m_HandlerFunction(handler_function) {};

        constexpr bool operator()(T* other_instance, HandlerFunction other_handler_function) const noexcept {
            return (other_instance == m_Instance) && (other_handler_function == m_HandlerFunction);
        }
    protected:
        T* m_Instance;
        HandlerFunction m_HandlerFunction;
    };
}

