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

        void OnKeyPressedEvent(const KeyPressedEvent& e);
        void OnKeyTypedEvent(const KeyTypedEvent& e);
        void OnKeyReleasedEvent(const KeyReleasedEvent& e);

        void OnMouseButtonPressedEvent(const MouseButtonPressedEvent& e);
        void OnMouseButtonReleasedEvent(const MouseButtonReleasedEvent& e);
        void OnMouseScrolledEvent(const MouseScrolledEvent& e);
        void OnMouseMovedEvent(const MouseMovedEvent& e);

        void OnWindowResizedEvent(const WindowResizedEvent& e);

    }; // END OF CLASS ImGuiLayer

} // END OF NAMESPACE Bald
