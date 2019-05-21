//
// Created by blinku on 07.05.19.
//

#include "bald.h"

class DebugLayer : public Bald::Layer {
public:
    DebugLayer() = default;

    ~DebugLayer() override = default;

    void OnAttach() noexcept override {

        m_EventManager.Subscribe<Bald::MouseMovedEvent>(Bald::HandleType::SYNC, [](const Bald::MouseMovedEvent& e) {
            CORE_LOG_TRACE(std::string("MouseMovedEvent: [")
                               .append(std::to_string(e.GetX()))
                               .append(", ")
                               .append(std::to_string(e.GetY()))
                               .append("]")
            );
        });

    }

    void OnDetach() noexcept override {}

    void OnUpdate() noexcept override {}

    [[nodiscard]] inline unsigned GetType() const override { return get_type_id(*this); }

};

class GameLayer : public Bald::Layer {
public:
    GameLayer() = default;

    ~GameLayer() override = default;

    void OnAttach() noexcept override {

        m_EventManager.Subscribe<Bald::KeyTypedEvent>(Bald::HandleType::SYNC, [](const Bald::KeyTypedEvent& e) {
            static bool isMenuUp = false;

            if(e.GetKeyCode() == GLFW_KEY_ESCAPE) {
                if(!isMenuUp) {
                    Bald::Application& app = Bald::Application::GetApplication();
                    app.PushOverlay<DebugLayer>();
                    isMenuUp = true;
                } else {
                    Bald::Application& app = Bald::Application::GetApplication();
                    app.PopOverlay<DebugLayer>();
                    isMenuUp = false;
                }
            }
        });

    }

    void OnDetach() noexcept override {}

    void OnUpdate() noexcept override {}

    [[nodiscard]] inline unsigned GetType() const override { return get_type_id(*this); }

};

class Sandbox : public Bald::Application {
public:
    Sandbox() {
        PushLayer<GameLayer>();
    }

    ~Sandbox() override = default;
};

Bald::Application* Bald::Application::Create() noexcept {
    return new Sandbox();
}
