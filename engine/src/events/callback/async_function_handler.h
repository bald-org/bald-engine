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
    template <typename E>
    class AsyncFunctionHandler : public Handler<E> {
    public:

        /**
        * @fn                   AsyncFunctionHandler
        * @brief                Constructor
        * @param [F&&]          fun -> Function which will be wrapped
        * @param [Args&& ...]   args -> Function's arguments
        */

        template<class F, class... Args>
        explicit AsyncFunctionHandler(F&& fun, Args&& ... args): Handler<E>(fun, args...) {}

        /**
        * @fn                   Run
        * @brief                This method runs wrapped function asynchronously
        */

        void Run(const Event& ev) const override { std::async(std::launch::async, [this, &ev](){
            this->m_Function(static_cast<const E&>(ev));
        }); } //TODO: This should return std::future
    };

} //END OF NAMESPACE Bald
