//
// Created by blinku on 07.05.19.
//

#include "bald.h"

class DebugLayer : public Bald::Layer {
public:
    DebugLayer() = default;
    ~DebugLayer() override = default;

    void OnAttach() noexcept override {
        Bald::EventManager::Subscribe<Bald::MouseMovedEvent>(Bald::HandleType::ASYNC, []() {
            CORE_LOG_INFO("MouseMovedEvent!");
        });
    }

    void OnDetach () noexcept override {

    }

    void Update() override {
        if(Bald::Input::InputManager::IsKeyPressed(GLFW_KEY_ESCAPE))
        {
            CORE_LOG_TRACE("WindowClosedEvent!");
            Bald::EventManager::Emit<Bald::WindowClosedEvent>();
        }
    }

};

class Sandbox : public Bald::Application {
public:
    Sandbox() {
        PushLayer<DebugLayer>();
    }

    ~Sandbox() override = default;
};

Bald::Application* Bald::Application::Create() noexcept {
    return new Sandbox();
}
