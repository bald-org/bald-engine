//
// Created by grzegorz on 21.02.19.
//

#pragma once

#include <vector>
#include <functional>
#include "core/debug/logger/log_manager.h"
#include <type_traits>
#include "core/debug/logger/logger.h"
#include "event_handler_interface.h"

namespace Bald {

    /**
     * @class EventHandler
     * @brief class that holds a function that takes  specific event as a parameter
     * @tparam E -> type of event that will be passed to the function
     */

    template<typename E>
    class EventHandler : public EventHandlerInterface {
    GENERATE_BODY(DERIVED)

    public:

        /**
        * @fn                   EventHandler
        * @brief                Constructor
        * @param [F&&]          fun -> Function which will be wrapped it *HAS TO* take as first parameter an const reference to Event
        * @param [Args&& ...]   args -> Function's arguments
        */

        template<class F, class... Args>
        explicit EventHandler(F&& fun, Args&& ... args) :
            EventHandlerInterface() {
            if(this->m_ID != 0) {
                if constexpr (std::is_member_function_pointer_v<F>) {
                    Unpack(std::forward<F>(fun), std::forward<Args>(args)...);
                } else {
                    m_Function = [=](const E& ev) {
                        fun(ev, args...);
                    };
                }

            } else {
                CORE_LOG_WARN(
                    "[EventHandler] Could not create EventHandler object because maximum number of ID's was reached");
            }
        }

        /**
        * @fn                   Run
        * @brief                Virtual method which provides an API for implementing function calls.
        *                       Right now we use it to provide option for synchronous and asynchronous function calls
        * @param [Event]        ev -> Event that will be casted to E type and passed to the function
        */

        void Run(const Event&) const override = 0;

    private:

        /**
         * @fn Unpack
         * @brief Method which allows separating object form the rest of arguments.
         * @tparam F -> Method type
         * @tparam O -> Object type
         * @tparam Args -> Arguments types
         * @param fun -> Method pointer
         * @param obj -> Object reference or pointer to object
         * @param args -> Arguments that will be bound to the method.
         */

        template<class F, class O, class ...Args>
        void Unpack(F&& fun, O&& obj, Args&& ...args) {
            // TODO: Once we employ C++20 use ... args = std::forward<Args>(args)
            m_Function = [function = std::forward<F>(fun), object = std::forward<O>(obj), args...](const E& ev) {
                std::invoke(function, object, ev, args...);
            };
        }

    protected:
        std::function<void(const E& ev)> m_Function; /**< Function wrapper */

    }; // END OF CLASS EventHandler

} //END OF NAMESPACE Bald
