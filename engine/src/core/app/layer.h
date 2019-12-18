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
    GENERATE_BODY(BASE)
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
         * @param deltaTime -> Time elapsed since last frame.
         */

        virtual void OnUpdate(float deltaTime) noexcept = 0;

        /**
         * @fn OnRender
         * @brief A pure virtual method which must be implemented on the client's side.
         *        It is updated in every iteration of the core engine loop.
         */

        virtual void OnRender() noexcept = 0;

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

    protected:
        EventManager m_EventManager; /**< Layer-specific EventManager*/

    private:
        bool m_IsEnabled = true; /**< State of the layer */

    }; // END OF CLASS Layer

} // END OF NAMESPACE Bald
