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
        m_Sprite.SetSize({10.0f, 10.0f});
    }

    void OnDetach() noexcept override {
        Graphics::Renderer2D::Shutdown();
    }

    void OnUpdate() noexcept override {
        if(Input::InputManager::IsKeyPressed(GLFW_KEY_A)) {
            m_Position.x -= m_CameraSpeed;
        } else if(Input::InputManager::IsKeyPressed(GLFW_KEY_D)) {
            m_Position.x += m_CameraSpeed;
        }

        if(Input::InputManager::IsKeyPressed(GLFW_KEY_W)) {
            m_Position.y += m_CameraSpeed;
        } else if(Input::InputManager::IsKeyPressed(GLFW_KEY_S)) {
            m_Position.y -= m_CameraSpeed;
        }
        m_Camera.SetPosition(m_Position);

        const auto& spritePos = m_Sprite.GetPosition();
        if(Input::InputManager::IsKeyPressed(GLFW_KEY_LEFT)) {
            m_Sprite.SetPosition({spritePos.x - m_CameraSpeed, spritePos.y});
        } else if(Input::InputManager::IsKeyPressed(GLFW_KEY_RIGHT)) {
            m_Sprite.SetPosition({spritePos.x + m_CameraSpeed, spritePos.y});
        }

        if(Input::InputManager::IsKeyPressed(GLFW_KEY_UP)) {
            m_Sprite.SetPosition({spritePos.x, spritePos.y + m_CameraSpeed});
        } else if(Input::InputManager::IsKeyPressed(GLFW_KEY_DOWN)) {
            m_Sprite.SetPosition({spritePos.x, spritePos.y - m_CameraSpeed});
        }


        // Begin sprite rendering
        m_Sprite.GetTexture()->Bind();
        Graphics::Renderer2D::Begin(m_Camera);
        for(std::size_t i = 0; i < 100; i++) {
            for(std::size_t j = 0; j < 100; j++) {
                m_Sprite.SetPosition({i * 10, j * 10});
                 Graphics::Renderer2D::Submit(m_Sprite);
            }
        }
        Graphics::Renderer2D::Draw();

        m_Sprite.GetTexture()->Unbind();
        Graphics::Renderer2D::End();
        // End sprite rendering
    }

    void OnRender() noexcept override {}

private:
    Graphics::Camera2D m_Camera{glm::ortho(0.0f, 1920.0f, 0.0f, 1080.0f)};
    Graphics::Sprite m_Sprite{Graphics::Texture::Create("../engine/res/textures/lena.jpg")};
    float m_CameraSpeed = 15.0f;
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
