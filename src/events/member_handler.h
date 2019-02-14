//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once
#include "event.h"
#include "function_handler.h"

namespace Bald::Events {
    /**
     * @class                               MemberHandler
     * @brief                               Normal Sync handler, which is used to invoke events
     * @tparam T                            Instance of class where Event will be invoked
     * @tparam EventType                    Type of Event
     */
    template<class T, class EventType>
    class MemberHandler : public FunctionHandler<T, EventType> {
    public:
        using HandlerFunction = void (T::*)(EventType *);

        /**
         * @fn                              MemberHandler
         * @brief                           Constructor of MemberHandler class
         * @param instance                  Instance of class where handler function pointer is
         * @param handler_function          Handler function pointer
         */
        constexpr MemberHandler(T* instance, HandlerFunction handler_function) noexcept : FunctionHandler<T, EventType>(instance, handler_function) {};
    private:
        /**
         * @fn                              call
         * @brief                           Function, which gets invoked on event
         * @param [Event*] e                Pointer to event instance
         */
        constexpr void call(Event* e) const noexcept override {
            (FunctionHandler<T, EventType>::m_Instance->*FunctionHandler<T, EventType>::m_HandlerFunction)(static_cast<EventType*>(e));
        }
    };
}
