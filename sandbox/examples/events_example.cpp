//
// Created by blinku on 07.05.19.
//

#include "bald.h"

#include "glm/glm.hpp"

class ExampleLayer : public Bald::Layer {
GENERATE_BODY(DERIVED)

public:
    ExampleLayer() = default;

    ~ExampleLayer() override = default;

    void OnAttach() noexcept override {
        static glm::vec2 position{0.0f, 0.0f};

        m_EventManager.Subscribe<Bald::KeyPressedEvent>(Bald::HandleType::SYNC, [&](const Bald::KeyPressedEvent& e) {

            if(e.GetKeyCode() == BALD_KEY_W) {
                position.y += 0.5f;
            } else if(e.GetKeyCode() == BALD_KEY_A) {
                position.x -= 0.5f;
            } else if(e.GetKeyCode() == BALD_KEY_S) {
                position.y -= 0.5f;
            } else if(e.GetKeyCode() == BALD_KEY_D) {
                position.x += 0.5f;
            } else if(e.GetKeyCode() == BALD_KEY_ESCAPE) {
                Bald::EventManager::Emit<Bald::WindowClosedEvent>();
            }

            GAME_LOG_TRACE(std::string("Current position: [")
                               .append(std::to_string(position.x))
                               .append(", ")
                               .append(std::to_string(position.y))
                               .append("]"));

        });
    }

    void OnDetach() noexcept override {}

    void OnUpdate([[maybe_unused]] float deltaTime) noexcept override {}

    void OnRender() noexcept override {}

};

class EventsExample : public Bald::Application {
GENERATE_BODY(DERIVED)
public:
    EventsExample() {
        PushLayer<ExampleLayer>();
    }

    ~EventsExample() override = default;
};

Bald::Application* Bald::Application::Create() noexcept {
    return new EventsExample();
}
