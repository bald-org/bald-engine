//
// Created by grzegorz on 21.02.19.
//

#pragma once

#include "callback.h"

namespace Bald {

    class FunctionHandler : public Callback {
    public:
        template<class F, class... Args>
        explicit FunctionHandler(F&& fun, Args&& ... args): Callback(fun, args...) {}

        inline void run() const override { _function(); }
    }; // END OF CLASS FunctionHandler

} //END OF NAMESPACE Bald
