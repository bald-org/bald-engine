//
// Created by blinku on 29.05.19.
//

#pragma once

#include "core.h"

#include "app/layer.h"
#include "events/window_events.h"
#include "events/key_events.h"
#include "events/mouse_events.h"

namespace Bald::Debug {

    /**
     * @class ImGuiLayer
     * @brief In-engine implementation of abstract class Layer. This layer currently behaves as the engine's menu.
     */

    class ImGuiLayer : public Layer {
    GENERATE_BODY(DERIVED)
    public:

        /**
         * @fn ImGuiLayer
         * @brief Default constructor.
         */

        ImGuiLayer() = default;

        /**
         * @fn ImGuiLayer
         * @brief Default destructor.
         */

        ~ImGuiLayer() override = default;

        /**
         * @fn OnAttach
         * @brief Initializes ImGui.
         */

        void OnAttach() noexcept override;

        /**
         * @fn OnDetach
         * @brief Deinitializes ImGui.
         */

        void OnDetach() noexcept override;

        /**
         * @fn OnUpdate
         * @brief Currently it is an empty method.
         */

        void OnUpdate() noexcept override;

        /**
         * @fn OnRender
         * @brief Draws menu on the screen.
         */

        void OnRender() noexcept override;

        /**
         * @fn Begin
         * @brief Begins ImGui frame.
         */

        static void Begin() noexcept;

        /**
         * @fn End
         * @brief Ends ImGui frame.
         */

        static void End() noexcept;
    }; // END OF CLASS ImGuiLayer

} // END OF NAMESPACE Bald::Debug

