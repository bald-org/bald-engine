//
// Created by blinku on 07.05.19.
//

#include <src/core/app/scene.hpp>
#include "bald.hpp"

using namespace Bald;
using namespace Graphics;
using namespace Controllers;

class GameLayer : public Layer {
GENERATE_BODY(DERIVED)

public:

    GameLayer() = default;

    ~GameLayer() override = default;

    void OnAttach() noexcept override {
        auto texture = Texture::Create("../engine/res/textures/lena.jpg");
        for(std::size_t i = 0; i < 10; i++) {
            for(std::size_t j = 0; j < 10; j++) {
                if(j % 2 == 0) {
                    Sprite sprite = Sprite{{1.0f, 0.0f, 0.0f, 1.0f}};
                    sprite.SetSize({50.0f, 50.0f});
                    sprite.SetPosition({static_cast<float>(j) * 50.0f, static_cast<float>(i) * 50.0f});
                    m_Scene.AddSprite(std::move(sprite));
                } else {
                    Sprite sprite = Sprite{texture};
                    sprite.SetSize({50.0f, 50.0f});
                    sprite.SetPosition({static_cast<float>(j) * 50.0f, static_cast<float>(i) * 50.0f});
                    m_Scene.AddSprite(std::move(sprite));
                }
            }
        }

        Events::EventBus::Subscribe<Events::KeyPressedEvent>([this](const Events::KeyPressedEvent& e) {
            if(e.GetKeyCode() == BALD_KEY_ESCAPE) {
                isMenuActive = !isMenuActive;
            }
        });
    }

    void OnDetach() noexcept override {}

    void OnUpdate(float deltaTime) noexcept override {
        m_Scene.OnUpdate(deltaTime);
        m_Scene.Render();
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

            ImGui::PlotLines("FPS Over Time", my_values.data(), static_cast<int32_t>(my_values.size()));
            ImGui::Text("FPS: %.1f", static_cast<double>(fps));

            ImGui::End();
        }

        ++frameCounter;
    }

private:
    Scene2D m_Scene;
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
