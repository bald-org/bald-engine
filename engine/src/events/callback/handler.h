//
// Created by grzegorz on 21.02.19.
//

#pragma once

#include <vector>
#include <functional>
#include "Log.h"
#include "handler_interface.h"

/**
 * @class Callback
 * @brief Abstract class whose job is to provide a simple function-wrapper API
 */

namespace Bald {
    class Event;
    template<typename E>
    class Handler : public HandlerInterface {
    public:

        /**
        * @fn                   Handler
        * @brief                Constructor
        * @param [F&&]          fun -> Function which will be wrapped
        * @param [Args&& ...]   args -> Function's arguments
        */

        template<class F, class... Args>
        explicit Handler(F&& fun, Args&& ... args) :
                HandlerInterface() {
            if (this->m_ID != 0) {
                m_Function = [=](const E& ev) {
                    fun(ev, args...);
                };
            } else {
                CORE_LOG_WARN("[Handler] Could not create Handler object because maximum number of ID's was reached");
            }
        }

        /**
        * @fn                   Run
        * @brief                Virtual method which provides an API for implementing function calls.
        *                       Right now we use it to provide option for synchronous and asynchronous function calls
        */

        void Run(const Event&) const override = 0;



    protected:
        std::function<void(const E& ev)> m_Function; /**< Function wrapper */

    }; // END OF CLASS Handler

} //END OF NAMESPACE Bald
