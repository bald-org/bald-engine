//
// Created by blinku on 21.05.19.
//

#pragma once

#include "core.hpp"
#include "event.hpp"

namespace Bald::Events {

    /**
     * @class LayerPushedEvent
     * @brief Specific event implementation for layer pushed type event.
     */

    class LayerPushedEvent : public Event {
    GENERATE_BODY(DERIVED)

    public:

        /**
        * @fn LayerPushedEvent
        * @brief Default constructor.
        */

        LayerPushedEvent() = default;

    }; // END OF CLASS LayerPushedEvent

    /**
     * @class LayerPoppedEvent
     * @brief Specific event implementation for layer popped type event.
     */

    class LayerPoppedEvent : public Event {
    GENERATE_BODY(DERIVED)

    public:

        /**
        * @fn LayerPoppedEvent
        * @brief Default constructor.
        */

        LayerPoppedEvent() = default;

    }; // END OF CLASS LayerPoppedEvent

} // END OF NAMESPACE Bald::Events
