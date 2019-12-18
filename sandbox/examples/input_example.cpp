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

    void OnAttach() noexcept override {}

    void OnDetach() noexcept override {}

    void OnUpdate([[maybe_unused]] float deltaTime) noexcept override {
        static glm::vec2 position{0.0f, 0.0f};

        if(Bald::Input::InputManager::IsKeyPressed(BALD_KEY_W)) {
            position.y += 0.5f;
        }
        if(Bald::Input::InputManager::IsKeyPressed(BALD_KEY_A)) {
            position.x -= 0.5f;
        }
        if(Bald::Input::InputManager::IsKeyPressed(BALD_KEY_S)) {
            position.y -= 0.5f;
        }
        if(Bald::Input::InputManager::IsKeyPressed(BALD_KEY_D)) {
            position.x += 0.5f;
        }

        GAME_LOG_TRACE(std::string("Current position: [")
                           .append(std::to_string(position.x))
                           .append(", ")
                           .append(std::to_string(position.y))
                           .append("]"));
    }

    void OnRender() noexcept override {}

};

class InputExample : public Bald::Application {
GENERATE_BODY(DERIVED)

public:
    InputExample() {
        PushLayer<ExampleLayer>();
    }

    ~InputExample() override = default;
};

Bald::Application* Bald::Application::Create() noexcept {
    return new InputExample();
}
