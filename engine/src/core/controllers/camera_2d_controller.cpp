//
// Created by blinku on 07.02.2020.
//

#include "camera_2d_controller.hpp"

#include "input/input_manager.h"

namespace Bald::Controllers {

    Camera2DController::Camera2DController(std::unique_ptr<Graphics::Camera2D> camera)
        : m_Camera(std::move(camera))
        , m_Position{0.0}
        , m_CameraSpeed{0.0005f} {}

    void Camera2DController::OnUpdate(float deltaTime) noexcept {
        if(Input::InputManager::IsKeyPressed(BALD_KEY_J)) {
            m_Position.x -= m_CameraSpeed * deltaTime;
        }

        if(Input::InputManager::IsKeyPressed(BALD_KEY_L)) {
            m_Position.x += m_CameraSpeed * deltaTime;
        }

        if(Input::InputManager::IsKeyPressed(BALD_KEY_I)) {
            m_Position.y += m_CameraSpeed * deltaTime;
        }

        if(Input::InputManager::IsKeyPressed(BALD_KEY_K)) {
            m_Position.y -= m_CameraSpeed * deltaTime;
        }

        m_Camera->SetPosition({m_Position.x, m_Position.y});
    }

} // END OF NAMESPACE Bald::Controllers