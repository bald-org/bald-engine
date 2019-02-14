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
        constexpr FunctionHandler(T *instance, HandlerFunction handler_function) noexcept : m_Instance(instance),
                                                                                            m_HandlerFunction(
                                                                                                    handler_function) {};
        /**
         * @fn                              operator()
         * @brief                           Compares instance of handler with elements of FunctionHandler class
         * @param other_instance            Instance which we want to compare handler's to
         * @param other_handler_function    Handler Function pointer which we want to compare handler's to
         * @return [bool]                   Result of comparison
         */
        constexpr bool operator()(T *other_instance, HandlerFunction other_handler_function) const noexcept {
            return (other_instance == m_Instance) && (other_handler_function == m_HandlerFunction);
        }

    protected:
        T *m_Instance; /** Instance of class where HandlerFunction is **/
        HandlerFunction m_HandlerFunction; /** Pointer to function, which will be invoked on event **/
    };
}

