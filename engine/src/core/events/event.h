//
// Created by grzegorz on 19.02.19.
//

#pragma once

#include "core.h"

namespace Bald {

    /**
     * @class Event
     * @brief Abstract class which provides simple API for specific events implementations
     */

    class Event {
    GENERATE_BODY(BASE)
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

    }; //END OF CLASS Event

} //END OF NAMESPACE Bald
