//
// Created by blinku on 21.05.19.
//

#pragma once

#include "event.h"
#include "event_manager.h"

namespace Bald {

    /**
     * @class LayerPushedEvent
     * @brief Specific event implementation for layer pushed type event
     */

    class LayerPushedEvent : public Event {
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */

    public:

        /**
        * @fn                           GetType
        * @brief                        This method returns type index of this specific class. This is used for polymorphism
        * @return [unsigned]            Type index
        */

        [[nodiscard]] inline unsigned GetType() const override { return get_type_id(*this); }

    }; // END OF CLASS LayerPushedEvent

/**
     * @class LayerPoppedEvent
     * @brief Specific event implementation for layer popped type event
     */

    class LayerPoppedEvent : public Event {
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */

    public:

        /**
        * @fn                           GetType
        * @brief                        This method returns type index of this specific class. This is used for polymorphism
        * @return [unsigned]            Type index
        */

        [[nodiscard]] inline unsigned GetType() const override { return get_type_id(*this); }

    }; // END OF CLASS LayerPoppedEvent

} // END OF NAMESPACE Bald
