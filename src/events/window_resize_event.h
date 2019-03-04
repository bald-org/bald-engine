//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once

#include "event.h"

namespace Bald::Events {
    /**
     * @class                              WindowResizeEvent
     * @brief                               Event, which will get invoked when user changes window's size
     */
    class WindowResizeEvent : public Event {
    public:
        /**
         * @fn                              WindowResizeEvent
         * @brief                           Constructor of WindowResizeEvent
         * @param [unsigned int] x          X coordinate of new window's size
         * @param [unsigned int] y          Y coordinate of new window's size
         */
        inline constexpr WindowResizeEvent(unsigned int x, unsigned int y) noexcept : x(x), y(y) {}

        /**
         * @fn                              getId
         * @return [unsigned int]           Id of Event
         */
        unsigned int getId() override {
            return eventId;
        }

        static unsigned int eventId;
        unsigned int x; /** X coordinate of new window's size **/
        unsigned int y; /** Y coordinate of new window's size **/
    };

    unsigned int WindowResizeEvent::eventId = 1;
}
