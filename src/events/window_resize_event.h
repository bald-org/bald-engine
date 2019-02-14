//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once

#include "event.h"

namespace Bald::Events {
    /**
     * @struct                              WindowResizeEvent
     * @brief                               Event, which will get invoked when user changes window's size
     */
    struct WindowResizeEvent : public Event {
        /**
         * @fn                              WindowResizeEvent
         * @brief                           Constructor of WindowResizeEvent
         * @param [unsigned int] x          X coordinate of new window's size
         * @param [unsigned int] y          Y coordinate of new window's size
         */
        inline constexpr WindowResizeEvent(unsigned int x, unsigned int y) noexcept : x(x), y(y) {}

        unsigned int x; /** X coordinate of new window's size **/
        unsigned int y; /** Y coordinate of new window's size **/
    };
}
