//
// Created by blinku on 07.05.19.
//

#include "bald.h"

#include "graphics/rendering/rendering_device/batch_2d.h"

using namespace Bald;

class GameLayer : public Layer {
GENERATE_BODY(DERIVED)

public:

    GameLayer() = default;

    ~GameLayer() override = default;

    void OnAttach() noexcept override {
        Graphics::Renderer2D::Init();
        m_Sprite1.SetSize({10.0f, 10.0f});
        m_Sprite2.SetSize({10.0f, 10.0f});
        m_Sprite3.SetSize({10.0f, 10.0f});
    }

    void OnDetach() noexcept override {
        Graphics::Renderer2D::Shutdown();
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
        Graphics::Renderer2D::Begin(m_Camera);

        for(std::size_t i = 0; i < 100; i++) {
            for(std::size_t j = 0; j < 33; j++) {
                m_Sprite1.SetPosition({i * 10, j * 10});
                Graphics::Renderer2D::Submit(m_Sprite1);
            }

            for(std::size_t j = 33; j < 2 * 33; j++) {
                m_Sprite2.SetPosition({i * 10, j * 10});
                Graphics::Renderer2D::Submit(m_Sprite2);
            }
            for(std::size_t j = 2 * 33; j < 3 * 33; j++) {
                m_Sprite3.SetPosition({i * 10, j * 10});
                Graphics::Renderer2D::Submit(m_Sprite3);
            }
        }

        Graphics::Renderer2D::Draw();
        Graphics::Renderer2D::End();
        // End sprite rendering
    }

    void OnRender() noexcept override {}

private:
    Graphics::Camera2D m_Camera{glm::ortho(0.0f, 1920.0f, 0.0f, 1080.0f)};
    Graphics::Sprite m_Sprite1{Graphics::Texture::Create("../engine/res/textures/lena.jpg")};
    Graphics::Sprite m_Sprite2{Graphics::Texture::Create("../engine/res/textures/fabric.jpg")};
    Graphics::Sprite m_Sprite3{Graphics::Texture::Create("../engine/res/textures/checkerboard.jpg")};
    float m_CameraSpeed = 5.0f;
    glm::vec2 m_Position{0.0f};
};

class Sandbox : public Application {
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
