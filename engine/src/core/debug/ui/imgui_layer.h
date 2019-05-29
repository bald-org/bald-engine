//
// Created by blinku on 29.05.19.
//

#pragma once

#include "core.h"

#include "app/layer.h"
#include "events/window_events.h"
#include "events/key_events.h"
#include "events/mouse_events.h"

namespace Bald {

    class ImGuiLayer : public Layer {
    GENERATE_BODY(DERIVED)
    public:
        ImGuiLayer() = default;
        ~ImGuiLayer() override = default;

        void OnAttach() noexcept override;

        void OnDetach() noexcept override;

        void OnUpdate() noexcept override;

    private:

        static void OnKeyPressedEvent(const KeyPressedEvent& e);
        static void OnKeyTypedEvent(const KeyTypedEvent& e);
        static void OnKeyReleasedEvent(const KeyReleasedEvent& e);

        static void OnMouseButtonPressedEvent(const MouseButtonPressedEvent& e);
        static void OnMouseButtonReleasedEvent(const MouseButtonReleasedEvent& e);
        static void OnMouseScrolledEvent(const MouseScrolledEvent& e);
        static void OnMouseMovedEvent(const MouseMovedEvent& e);

        static void OnWindowResizedEvent(const WindowResizedEvent& e);

    }; // END OF CLASS ImGuiLayer

} // END OF NAMESPACE Bald
