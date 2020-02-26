//
// Created by blinku on 11.02.2020.
//

#include "scene.hpp"
#include "graphics/rendering/rendering_device/renderer_2d.hpp"
#include "input/input_manager.hpp"

namespace Bald {

    void Scene2D::AddSprite(Graphics::Sprite m_Sprite) {
        m_Sprites.push_back(std::move(m_Sprite));
    }

    void Scene2D::Render() {
        auto&&[x, y] = Input::InputManager::GetMousePos();
        Graphics::Renderer2D::Begin(m_CameraController.GetCamera(), std::make_pair(x, 720.0 - y));
        for(const auto& sprite : m_Sprites) {
            Graphics::Renderer2D::Submit(sprite);
        }
        Graphics::Renderer2D::End();
    }

    void Scene2D::OnUpdate(float deltaTime) noexcept {
        m_CameraController.OnUpdate(deltaTime);
    }
} // END OF NAMESPACE Bald
