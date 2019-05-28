//
// Created by grzegorz on 21.02.19.
//

#pragma once

#include "event_handler.h"

namespace Bald {
    class Event;
    /**
     * @class FunctionHandler
     * @brief Synchronous function wrapper implementation
     */

    template <typename E>
    class EventFunctionHandler : public EventHandler<E> {
    GENERATE_BODY(DERIVED)
    public:

        /**
        * @fn                   FunctionHandler
        * @brief                Constructor
        * @param [F&&]          fun -> Function which will be wrapped. This function *MUST* take Event as first parameter
        * @param [Args&& ...]   args -> Function's arguments
        */

        template<class F, class... Args>
        explicit EventFunctionHandler(F&& fun, Args&& ... args): EventHandler<E>(fun, args...) {}

        /**
        * @fn                   Run
        * @brief                This method runs wrapped function
        * @param [Event]        ev -> event that will be casted to E type and passed to the function
        */

        void Run(const Event& ev) const override { this->m_Function(static_cast<const E&>(ev)); }

    }; // END OF CLASS EventFunctionHandler

} //END OF NAMESPACE Bald
