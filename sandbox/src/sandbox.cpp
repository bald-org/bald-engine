//
// Created by blinku on 07.05.19.
//

#include "bald.h"

class GameLayer : public Bald::Layer {
GENERATE_BODY(DERIVED)

public:

    GameLayer() = default;

    ~GameLayer() override = default;

    void OnAttach() noexcept override {}

    void OnDetach() noexcept override {}

    void OnUpdate() noexcept override {
        if(Bald::Input::InputManager::IsKeyPressed(GLFW_KEY_A)) {
            m_Position.x -= m_CameraSpeed;
        } else if(Bald::Input::InputManager::IsKeyPressed(GLFW_KEY_D)) {
            m_Position.x += m_CameraSpeed;
        }

        if(Bald::Input::InputManager::IsKeyPressed(GLFW_KEY_W)) {
            m_Position.y  += m_CameraSpeed;
        } else if(Bald::Input::InputManager::IsKeyPressed(GLFW_KEY_S)) {
            m_Position.y -= m_CameraSpeed;
        }
        m_Camera.SetPosition(m_Position);

        const auto& spritePos = m_Sprite.GetPosition();
        if(Bald::Input::InputManager::IsKeyPressed(GLFW_KEY_LEFT)) {
            m_Sprite.SetPosition({spritePos.x - m_CameraSpeed, spritePos.y});
        } else if(Bald::Input::InputManager::IsKeyPressed(GLFW_KEY_RIGHT)) {
            m_Sprite.SetPosition({spritePos.x + m_CameraSpeed, spritePos.y});
        }

        if(Bald::Input::InputManager::IsKeyPressed(GLFW_KEY_UP)) {
            m_Sprite.SetPosition({spritePos.x, spritePos.y + m_CameraSpeed});
        } else if(Bald::Input::InputManager::IsKeyPressed(GLFW_KEY_DOWN)) {
            m_Sprite.SetPosition({spritePos.x, spritePos.y - m_CameraSpeed});
        }

        // Begin sprite rendering
        m_Renderer2D.Begin(m_Camera);
        m_Renderer2D.Submit(m_Sprite);
        m_Renderer2D.End();
        // End sprite rendering
    }

    void OnRender() noexcept override {}

private:
private:
    Bald::Graphics::Renderer2D m_Renderer2D;
    Bald::Graphics::Camera2D m_Camera{glm::ortho(-1.6f, 1.6f, -0.9f, 0.9f)};
    Bald::Graphics::Sprite m_Sprite{Bald::Graphics::Texture::Create("../engine/res/textures/lena.jpg")};
    float m_CameraSpeed = 0.005f;
    glm::vec2 m_Position{0.0f};
};

class Sandbox : public Bald::Application {
GENERATE_BODY(DERIVED)

public:

    Sandbox() {
        PushLayer<GameLayer>();
    }

    ~Sandbox() override = default;

};

Bald::Application* Bald::Application::Create() noexcept {
    return new Sandbox();
}
