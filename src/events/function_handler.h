//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once

#include "event.h"

namespace Bald::Events {
    template<class T, class EventType>
    class FunctionHandler : public BaseHandler {
    public:
        using HandlerFunction = void (T::*)(EventType *);

        /**
         * @fn                              FunctionHandler
         * @brief                           Constructor of FunctionHandler class
         * @param instance                  Instance of class where handler function pointer is
         * @param handler_function          Handler function pointer
         */
        constexpr FunctionHandler(T *instance, HandlerFunction handler_function) noexcept : BaseHandler(
                BaseHandler::maxHandlerId), m_Instance(instance),
                                                                                            m_HandlerFunction(
                                                                                                    handler_function) {};

    protected:
        T *m_Instance; /** Instance of class where HandlerFunction is **/
        HandlerFunction m_HandlerFunction; /** Pointer to function, which will be invoked on event **/
    };
}

