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

        FunctionHandler(T* instance, HandlerFunction handler_function): m_instance(instance), m_handler_function(handler_function) {};

        constexpr bool operator()(T* other_instance, HandlerFunction other_handler_function) const {
            return (other_instance == m_instance) && (other_handler_function == m_handler_function);
        }
    protected:
        T* m_instance;
        HandlerFunction m_handler_function;
    };
}

