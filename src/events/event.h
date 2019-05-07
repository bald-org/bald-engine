//
// Created by grzegorz on 19.02.19.
//

#pragma once

#include <typeindex>
#include "Log.h"
/**
 * @class Event
 * @brief Abstract class which provides simple API for specific events implementations
 */

namespace Bald {

    template<class E, class H>
    void Subscribe([[maybe_unused]]const H& ev) {
        CORE_LOG_ERROR("[Event Manager] ");
        assert(false);
    }

    enum class HandleType {
        SYNC, ASYNC
    };

    class Event {
    public:

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
    }; //END OF CLASS Event

    template<class E>
    void run(const E& event) {
        for (const auto& callback : E::callbacks) {
            callback.Run(event);
        }

        for (const auto& callback : E::async_callbacks) {
            callback.Run(event);
        }
    }

    template<>
    void run<Event>([[maybe_unused]]const Event& event) {
        assert(false); //TODO: some info
    }

} //END OF NAMESPACE Bald
