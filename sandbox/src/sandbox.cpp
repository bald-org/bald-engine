//
// Created by blinku on 07.05.19.
//

#include "bald.h"

#include "graphics/rendering/rendering_device/batch_2d.h"

using namespace Bald;
using namespace Graphics;

class GameLayer : public Layer {
GENERATE_BODY(DERIVED)

public:

    GameLayer() = default;

    ~GameLayer() override = default;

    void OnAttach() noexcept override {
        m_Sprite1.SetSize({50.0f, 50.0f});
        m_Sprite2.SetSize({50.0f, 50.0f});
        m_Sprite3.SetSize({50.0f, 50.0f});
    }

    void OnDetach() noexcept override {
        Renderer2D::Shutdown();
    }

    void OnUpdate() noexcept override {
        if(Input::InputManager::IsKeyPressed(BALD_KEY_A)) {
            m_Position.x -= m_CameraSpeed;
        } else if(Input::InputManager::IsKeyPressed(BALD_KEY_D)) {
            m_Position.x += m_CameraSpeed;
        }

        if(Input::InputManager::IsKeyPressed(BALD_KEY_W)) {
            m_Position.y += m_CameraSpeed;
        } else if(Input::InputManager::IsKeyPressed(BALD_KEY_S)) {
            m_Position.y -= m_CameraSpeed;
        }

        m_Camera.SetPosition({m_Position.x, m_Position.y});

        // Begin sprite rendering
        Renderer2D::Begin(m_Camera);

        for(std::size_t i = 0; i < 20; i++) {
            m_Sprite1.SetPosition({0, i * 50});
            m_Sprite2.SetPosition({50, i * 50});
            m_Sprite3.SetPosition({2 * 50, i * 50});

            Renderer2D::Submit(m_Sprite1);
            Renderer2D::Submit(m_Sprite2);
            Renderer2D::Submit(m_Sprite3);
        }

        Renderer2D::End();
        // End sprite rendering
    }

    void OnRender() noexcept override {}

private:
    Camera2D m_Camera{glm::ortho(0.0f, 1920.0f, 0.0f, 1080.0f)};
    Sprite m_Sprite1{Texture::Create("../engine/res/textures/lena.jpg")};
    Sprite m_Sprite2{Texture::Create("../engine/res/textures/pixel_textures/Rocks/SLIMROCKS.png")};
    Sprite m_Sprite3{{0.8f, 0.2f, 0.2f, 1.0f}};

    float m_CameraSpeed = 0.5f;
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

Application* Application::Create() noexcept {
    return new Sandbox();
}
