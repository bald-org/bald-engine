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
        explicit BaseHandler(unsigned int hId) : handlerId(hId) {
            BaseHandler::maxHandlerId++;
        }
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

        /**
         * @fn                              operator()
         * @brief                           Compares two handlers
         * @param hId                       Handler's ID
         * @return [bool]                   Result of comparison
         */
        constexpr bool operator()(unsigned int hId) const noexcept {
            return hId == handlerId;
        }

        unsigned int handlerId;

        static unsigned int maxHandlerId;

    protected:
        /**
         * @fn                              call
         * @brief                           Function, which gets invoked on event
         * @param [Event*] e                Pointer to event instance
         */
        virtual void call(Event *e) const noexcept = 0;
    };

    unsigned int BaseHandler::maxHandlerId = 0;
}
