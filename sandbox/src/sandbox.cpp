//
// Created by blinku on 07.05.19.
//

#include "bald.h"

class DebugLayer : public Bald::Layer {
public:
    DebugLayer() = default;

    ~DebugLayer() override = default;

    void OnAttach() noexcept override {

        m_EventManager.Subscribe<Bald::KeyTypedEvent>(Bald::HandleType::ASYNC, [](const Bald::KeyTypedEvent& e) {
            CORE_LOG_TRACE(static_cast<char>(e.GetKeyCode()));
        });


        m_EventManager.Subscribe<Bald::MouseMovedEvent>(Bald::HandleType::ASYNC, [](const Bald::MouseMovedEvent&) {
            CORE_LOG_TRACE("MouseMovedEvent");
        });

    }

    void OnDetach() noexcept override {

    }

    void OnUpdate() noexcept override {
        if(Bald::Input::InputManager::IsKeyTyped(GLFW_KEY_ESCAPE)) {
            Bald::EventManager::Emit<Bald::WindowClosedEvent>();
        }
    }

    [[nodiscard]] std::type_index GetType() const override { return typeid(decltype(*this)); };

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
