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
        m_Lena.SetSize({50.0f, 50.0f});
        m_Square.SetSize({50.0f, 50.0f});

        m_EventManager.Subscribe<KeyPressedEvent>(HandleType::SYNC, [this](const KeyPressedEvent& e) {
            if(e.GetKeyCode() == BALD_KEY_ESCAPE) {
                isMenuActive = !isMenuActive;
            }
        });
    }

    void OnDetach() noexcept override {}

    void OnUpdate(float deltaTime) noexcept override {
        m_CameraController.OnUpdate(deltaTime);

        auto&&[x, y] = Input::InputManager::GetMousePos();

        Renderer2D::Begin(m_CameraController.GetCamera(), std::make_pair(x, 720.0 - y));

        if(Input::InputManager::IsKeyPressed(BALD_KEY_E)) {
            m_Rotation += 0.005f * deltaTime;
        }

        if(Input::InputManager::IsKeyPressed(BALD_KEY_Q)) {
            m_Rotation -= 0.005f * deltaTime;
        }

        if(Input::InputManager::IsKeyPressed(BALD_KEY_W)) {
            m_Offset.y += 0.0005f * deltaTime;
        }

        if(Input::InputManager::IsKeyPressed(BALD_KEY_S)) {
            m_Offset.y -= 0.0005f * deltaTime;
        }

        if(Input::InputManager::IsKeyPressed(BALD_KEY_A)) {
            m_Offset.x -= 0.0005f * deltaTime;
        }

        if(Input::InputManager::IsKeyPressed(BALD_KEY_D)) {
            m_Offset.x += 0.0005f * deltaTime;
        }

        for(float i = 0; i < 20.0f; i++) {
            m_Lena.SetRotation(m_Rotation);
            m_Lena.SetPosition({m_Offset.x, i * 50.0f +  m_Offset.y});

            m_Square.SetPosition({1 * 50, i * 50});
            m_Square.SetColor(m_SpriteColor);

            Renderer2D::Submit(m_Lena);
            Renderer2D::Submit(m_Square);
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
    Camera2DController m_CameraController{std::make_unique<Camera2D>(glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f))};

    glm::vec2 m_Offset = glm::vec2{0.0f, 0.0f};
    float m_Rotation = 0.0f;
    Sprite m_Lena{Texture::Create("../engine/res/textures/lena.jpg")};

    glm::vec4 m_SpriteColor = glm::vec4{1.0f, 0.0f, 0.0f, 1.0f};
    Sprite m_Square{m_SpriteColor};

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
