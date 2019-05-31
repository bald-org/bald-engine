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

    class ImGuiLayer : public Layer {
    friend class Application;
    GENERATE_BODY(DERIVED)
    public:
        ImGuiLayer() = default;
        ~ImGuiLayer() override = default;

        void OnAttach() noexcept override;

        void OnDetach() noexcept override;

        void OnUpdate() noexcept override;

        void OnRender() noexcept override;

        static void Begin() noexcept;

        static void End() noexcept;
    }; // END OF CLASS ImGuiLayer

} // END OF NAMESPACE Bald::Debug

