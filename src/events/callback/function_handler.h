//
// Created by grzegorz on 21.02.19.
//

#pragma once

#include "handler.h"

namespace Bald {

    /**
     * @class FunctionHandler
     * @brief Synchronous function wrapper implementation
     */

    class FunctionHandler : public Handler {
    public:

        /**
        * @fn                   FunctionHandler
        * @brief                Constructor
        * @param [F&&]          fun -> Function which will be wrapped
        * @param [Args&& ...]   args -> Function's arguments
        */

        template<class F, class... Args>
        explicit FunctionHandler(F&& fun, Args&& ... args): Handler(fun, args...) {}

        /**
        * @fn                   Run
        * @brief                This method runs wrapped function
        */

        inline void Run() const override { m_Function(); }
    }; // END OF CLASS FunctionHandler

} //END OF NAMESPACE Bald
