//
// Created by blinku on 07.05.19.
//

#include "bald.h"

class GameLayer : public Bald::Layer {
GENERATE_BODY(DERIVED)
public:

    GameLayer() = default;

    ~GameLayer() override = default;

    void OnAttach() noexcept override {}

    void OnDetach() noexcept override {}

    void OnUpdate() noexcept override {}

    void OnRender() noexcept override {}

};

class Sandbox : public Bald::Application {
GENERATE_BODY(DERIVED)
public:

    Sandbox() {
        PushLayer<GameLayer>();
    }

    ~Sandbox() override = default;

};

Bald::Application* Bald::Application::Create() noexcept {
    return new Sandbox();
}
