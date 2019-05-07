//
// Created by grzegorz on 21.02.19.
//

#pragma once

#include <future>
#include "handler.h"

/**
 * @class AsyncFunctionHandler
 * @brief Asynchronous function wrapper implementation
 */

namespace Bald {
    template <class Event>
    class AsyncFunctionHandler : public Handler<Event> {
    public:

        /**
        * @fn                   AsyncFunctionHandler
        * @brief                Constructor
        * @param [F&&]          fun -> Function which will be wrapped
        * @param [Args&& ...]   args -> Function's arguments
        */

        template<class F, class... Args>
        explicit AsyncFunctionHandler(F&& fun, Args&& ... args): Handler<Event>(fun, args...) {}

        /**
        * @fn                   Run
        * @brief                This method runs wrapped function asynchronously
        */

        inline void Run(const Event& ev) const override { std::async(std::launch::async, [this, &ev](){
                this->m_Function(ev);
            });
        }
    };

} //END OF NAMESPACE Bald
