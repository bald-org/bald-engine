//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once
#include "event.h"

namespace Bald::Events {;
    template<class T, class EventType>
    class BaseHandler {
    public:
        typedef void (T::*HandlerFunction)(EventType*);
        BaseHandler(T* instance, HandlerFunction handler_function): m_instance(instance), m_handler_function(handler_function) {};
        void exec(Event* e) {
            call(e);
        }
    protected:
        T* m_instance;
        HandlerFunction m_handler_function;
        virtual void call(Event* e) = 0;
    };
}

