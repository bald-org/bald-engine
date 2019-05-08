//
// Created by grzegorz on 19.02.19.
//

#pragma once

#include <typeindex>
#include "Log.h"
#include "function_handler.h"
#include "async_function_handler.h"
#include "interface_impl.h"
/**
 * @class Event
 * @brief Abstract class which provides simple API for specific events implementations
 */

namespace Bald {

    struct Event {
        /**
        * @fn       Event
        * @brief    Default constructor
        */

        Event() = default;

        /**
        * @fn       ~Event
        * @brief    Default constructor
        */

        virtual ~Event() = default;

        /**
        * @fn       EmitConnectedEvents
        * @brief    This method is used to create specific events which also emit
        *           associated events (ex. KeyPressedEvent also emits KeyEvent).
        *           This function must be overwritten in all scenarios!
        */

        virtual void EmitConnectedEvents() const = 0;

    }; //END OF CLASS Event



    template<>
    inline void run<Event>([[maybe_unused]]const Event& event) {
        assert(false); //TODO: log some info
    }

    template <>
    inline void Subscribe<Event>([[maybe_unused]]FunctionHandler <Event>* ev ){
        assert(false);
    }

    template <>
    inline void Subscribe<Event>([[maybe_unused]] AsyncFunctionHandler <Event>* ev ){
        assert(false);
    }

    template <>
    inline void Unsubscibe<Event>([[maybe_unused]]HandleType type, [[maybe_unused]]unsigned int id){
        assert(false);
    }

} //END OF NAMESPACE Bald
