//
// Created by grzegorz on 19.02.19.
//

#pragma once

#include <typeindex>
#include "type_id.h"

namespace Bald {

    /**
     * @class Event
     * @brief Abstract class which provides simple API for specific events implementations
     */

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
        * @fn       Type
        * @brief    This method queries specific object for its type.
        *           This function MUST be overwritten in every single specific event class implementation
        *           Overwrite it like this: [[nodiscard]] inline std::type_index Type() const override { return typeid(decltype(*this)); }
        */

        [[nodiscard]] virtual unsigned Type() const = 0;

    }; //END OF CLASS Event

} //END OF NAMESPACE Bald
