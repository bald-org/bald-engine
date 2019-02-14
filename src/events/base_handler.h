//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once

#include "event.h"

namespace Bald::Events {
    /**
     * @class                               BaseHandler
     * @brief                               Base class of event handlers
     */
    class BaseHandler {
    public:
        /**
         * @fn                              ~BaseHandler
         * @brief                           Default virtual destructor of BaseHandler
         */
        virtual ~BaseHandler() = default;

        /**
         * @fn                              exec
         * @brief                           Function, which executes the event
         * @param [Event*] e                Pointer to event instance
         */
        void exec(Event *e) noexcept {
            call(e);
        }

    protected:
        /**
         * @fn                              call
         * @brief                           Function, which gets invoked on event
         * @param [Event*] e                Pointer to event instance
         */
        virtual void call(Event *e) const noexcept = 0;
    };
}
