//
// Created by blinku on 11.02.2020.
//

#pragma once

#include "glm/gtc/matrix_transform.hpp"

#include "controllers/camera_2d_controller.hpp"
#include "graphics/rendering/sprite.hpp"

namespace Bald {

    class Scene2D {
    public:
        void AddSprite(Graphics::Sprite m_Sprite);

        void Render();

        void OnUpdate(float deltaTime) noexcept;

    private:
        Controllers::Camera2DController m_CameraController{
            std::make_unique<Graphics::Camera2D>(glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f))};
        std::vector<Graphics::Sprite> m_Sprites;
    }; // END OF CLASS Scene2D

} // END OF NAMESPACE Bald
