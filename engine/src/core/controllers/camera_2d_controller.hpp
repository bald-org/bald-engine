//
// Created by blinku on 07.02.2020.
//

#pragma once

#include <memory>
#include "graphics/rendering/camera_2d.h"

namespace Bald::Controllers {

    class Camera2DController {
    public:
        explicit Camera2DController(std::unique_ptr<Graphics::Camera2D> camera);

        Camera2DController(const Camera2DController&) = delete;

        Camera2DController(Camera2DController&&) noexcept = delete;

        Camera2DController& operator=(const Camera2DController&) = delete;

        Camera2DController& operator=(Camera2DController&&) = delete;

        [[nodiscard]] const Graphics::Camera2D& GetCamera() const noexcept { return *m_Camera; }

        void OnUpdate(float deltaTime) noexcept;

    private:
        std::unique_ptr<Graphics::Camera2D> m_Camera;
        glm::vec2 m_Position{0.0f};
        float m_CameraSpeed = 0.0005f;
    }; // END OF CLASS Camera2DController

} // END OF NAMESPACE Bald::Controllers
