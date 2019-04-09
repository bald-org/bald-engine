//
// Created by grzegorz on 19.02.19.
//

#pragma once

#include <typeindex>

/**
 * @class Event
 * @brief Abstract class which provides simple API for specific events implementations
 */

namespace Bald {

    class Event {
    protected:

        /**
        * @fn       Event
        * @brief    Default constructor
        */

        Event() = default;
        
    public:

        /**
        * @fn       ~Event
        * @brief    Default constructor
        */

        virtual ~Event() = default;

    public:

        /**
        * @fn       EmitConnectedEvents
        * @brief    This method is used to create specific events which also emit
        *           associated events (ex. KeyPressedEvent also emits KeyEvent).
        *           This function must be overwritten in all scenarios!
        */

        virtual void EmitConnectedEvents() const = 0;

        /**
        * @fn       Type
        * @brief    This method queries specific object for its type.
        *           This function MUST be overwritten in every single specific event class implementation
        *           Overwrite it like this: [[nodiscard]] inline std::type_index Type() const override { return typeid(decltype(*this)); }
        */

        [[nodiscard]] virtual std::type_index Type() const = 0;

    }; //END OF CLASS Event

} //END OF NAMESPACE Bald
