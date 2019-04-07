//
// Created by grzegorz on 21.02.19.
//

#pragma once

#include <future>
#include "callback.h"

namespace Bald {

    class AsyncFunctionHandler : public Callback {
    public:
        template<class F, class... Args>
        explicit AsyncFunctionHandler(F&& fun, Args&& ... args): Callback(fun, args...) {}

        inline void run() const override { std::async(std::launch::async, _function); }
    };

} //END OF NAMESPACE Bald
