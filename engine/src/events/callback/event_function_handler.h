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
    public:

        /**
        * @fn                   FunctionHandler
        * @brief                Constructor
        * @param [F&&]          fun -> Function which will be wrapped *HAS TO* take as first parameter an const reference to Event
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
