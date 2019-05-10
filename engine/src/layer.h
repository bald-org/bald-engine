//
// Created by blinku on 08.05.19.
//

#pragma once

#include "event_manager.h"

namespace Bald {

    /**
     * @class Layer
     * @brief Simple layer interface. This is the class that one should derive from
     *        when implementing specific application layers
     */

    class Layer {
    public:

        /**
         * @fn Layer
         * @brief Layer constructor
         */

        Layer() = default;

        /**
         * @fn ~Layer
         * @brief Layer destructor
         */

        virtual ~Layer() = default;

        /**
         * @fn OnAttach
         * @brief A pure virtual method which must be implemented on the client's side.
         *        It is run when the layer gets pushed to the application's layer stack.
         */

        virtual void OnAttach() noexcept = 0;

        /**
         * @fn OnDetach
         * @brief A pure virtual method which must be implemented on the client's side.
         *        It is run when the layer gets popped from the application's layer stack.
         */

        virtual void OnDetach() noexcept = 0;

        /**
         * @fn OnUpdate
         * @brief A pure virtual method which must be implemented on the client's side.
         *        It is updated in every iteration of the core engine loop.
         */

        virtual void OnUpdate() noexcept = 0;

        /**
         * @fn RunEvents
         * @brief A method that flushes layer's event manager.
         */

        inline void RunEvents() noexcept { m_EventManager.Flush(); }

        /**
         * @fn Enable
         * @brief A method that enables a layer.
         */

        inline void Enable() noexcept { m_IsEnabled = true; }

        /**
         * @fn Disable
         * @brief A method that disables a layer.
         */

        inline void Disable() noexcept { m_IsEnabled = false; }

        /**
         * @fn IsEnabled
         * @brief Queries layer for its state
         * @return [bool] true -> layer is enabled
         *                false -> layer is disabled
         */

        [[nodiscard]] inline bool IsEnabled() const noexcept { return m_IsEnabled; };

        /**
        * @fn       GetType
        * @brief    This method queries specific object for its type.
        *           This function MUST be overwritten in every single specific layer class implementation
        *           Overwrite it like this: [[nodiscard]] inline std::type_index GetType() const override { return typeid(decltype(*this)); }
        */

        [[nodiscard]] virtual std::type_index GetType() const = 0;

    private:
        bool m_IsEnabled = true; /**< State of the layer */
        EventManager m_EventManager; /**< Layer-specific EventManager*/

    }; // END OF CLASS Layer

} // END OF NAMESPACE Bald
