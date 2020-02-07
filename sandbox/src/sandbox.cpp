//
// Created by blinku on 07.05.19.
//

#include "bald.h"

using namespace Bald;
using namespace Graphics;
using namespace Controllers;

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

    void OnUpdate(float deltaTime) noexcept override {
        // Begin sprite rendering
        m_CameraController.OnUpdate(deltaTime);

        Renderer2D::Begin(m_CameraController.GetCamera());

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
    Camera2DController m_CameraController{std::make_unique<Camera2D>(glm::ortho(0.0f, 1920.0f, 0.0f, 1080.0f))};
    Sprite m_Sprite1{Texture::Create("../engine/res/textures/lena.jpg")};
    Sprite m_Sprite2{Texture::Create("../engine/res/textures/pixel_textures/Rocks/SLIMROCKS.png")};
    Sprite m_Sprite3{{0.8f, 0.2f, 0.2f, 1.0f}};
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
