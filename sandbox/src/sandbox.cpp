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

        m_EventManager.Subscribe<KeyPressedEvent>(HandleType::SYNC, [this](const KeyPressedEvent& e) {
            if(e.GetKeyCode() == BALD_KEY_ESCAPE) {
                isMenuActive = !isMenuActive;
            }
        });
    }

    void OnDetach() noexcept override {
        Renderer2D::Shutdown();
    }

    void OnUpdate(float deltaTime) noexcept override {
        m_CameraController.OnUpdate(deltaTime);

        Renderer2D::Begin(m_CameraController.GetCamera());

        Renderer2D::Submit(m_Sprite1);

        for(std::size_t i = 0; i < 20; i++) {
            float rotation = m_Sprite1.GetRotation();
            if(Input::InputManager::IsKeyPressed(BALD_KEY_E)) {
                rotation += 0.005f * deltaTime;
            }

            if(Input::InputManager::IsKeyPressed(BALD_KEY_Q)) {
                rotation -= 0.005f * deltaTime;
            }

            m_Sprite1.SetRotation(rotation);

            m_Sprite1.SetPosition({0, i * 50});
            m_Sprite2.SetPosition({50, i * 50});
            m_Sprite3.SetPosition({2 * 50, i * 50});

            m_Sprite3.SetColor(m_SpriteColor);

            Renderer2D::Submit(m_Sprite1);
            Renderer2D::Submit(m_Sprite2);
            Renderer2D::Submit(m_Sprite3);
        }

        Renderer2D::End();
    }

    void OnRender() noexcept override {
        static bool init = true;
        static Models::Timer timer;
        static float frameCounter = 0;
        static float fps = 0;
        static std::vector<float> my_values(10);

        if(init) {
            timer.Start();
            init = false;
        }

        float elapsedSeconds = timer.ElapsedSeconds();
        if(elapsedSeconds >= 1.0f) {
            fps = frameCounter / elapsedSeconds;
            my_values.push_back(fps);
            my_values.erase(my_values.begin());
            frameCounter = 0;
            timer.Reset();
        }

        if(isMenuActive) {
            ImGui::Begin("Debug Menu", &isMenuActive, ImGuiWindowFlags_MenuBar);

            if(ImGui::BeginMenuBar()) {
                if(ImGui::BeginMenu("File")) {
                    if(ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
                    if(ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
                    if(ImGui::MenuItem("Close", "Ctrl+W")) { isMenuActive = false; }
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }

            ImGui::ColorEdit4("Color", glm::value_ptr(m_SpriteColor));
            ImGui::PlotLines("FPS Over Time", my_values.data(), static_cast<int32_t>(my_values.size()));
            ImGui::Text("FPS: %.1f", static_cast<double>(fps));

            ImGui::End();
        }


        ++frameCounter;
    }

private:
    Camera2DController m_CameraController{std::make_unique<Camera2D>(glm::ortho(0.0f, 1920.0f, 0.0f, 1080.0f))};
    Sprite m_Sprite1{Texture::Create("../engine/res/textures/lena.jpg")};
    Sprite m_Sprite2{Texture::Create("../engine/res/textures/pixel_textures/Rocks/SLIMROCKS.png")};
    Sprite m_Sprite3{{0.8f, 0.2f, 0.2f, 1.0f}};
    glm::vec4 m_SpriteColor = glm::vec4{1.0f, 0.0f, 0.0f, 1.0f};
    bool isMenuActive = true;
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
