//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once

#include <future>

#include "event.h"
#include "function_handler.h"

namespace Bald::Events {
    /**
     * @class                               MemberAsyncHandler
     * @brief                               Async handler, which is used to invoke events
     * @tparam T                            Instance of class where Event will be invoked
     * @tparam EventType                    Type of Event
     */
    template<class T, class EventType>
    class MemberAsyncHandler : public FunctionHandler<T, EventType> {
    public:
        using HandlerFunction = void (T::*)(EventType *);

        /**
         * @fn                              MemberAsyncHandler
         * @brief                           Constructor of MemberAsyncHandler class
         * @param instance                  Instance of class where handler function pointer is
         * @param handler_function          Handler function pointer
         */
        constexpr MemberAsyncHandler(T *instance, HandlerFunction handler_function) noexcept
                : FunctionHandler<T, EventType>(instance, handler_function) {};
    private:
        /**
         * @fn                              call
         * @brief                           Function, which gets invoked on event
         * @param [Event*] e                Pointer to event instance
         */
        constexpr void call(Event *e) const noexcept override {
            auto handle = std::async([&](EventType *params) {
                (FunctionHandler<T, EventType>::m_Instance->*FunctionHandler<T, EventType>::m_HandlerFunction)(params);
            }, static_cast<EventType *>(e));
            handle.get();
        }
    };
}

