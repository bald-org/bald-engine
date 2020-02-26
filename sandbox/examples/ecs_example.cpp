//
// Created by blinku on 26.02.2020.
//

#include "bald.h"

class ExampleLayer : public Bald::Layer {
GENERATE_BODY(DERIVED)

public:
    ExampleLayer() = default;

    ~ExampleLayer() override = default;

    void OnAttach() noexcept override {
        using namespace Bald::Ecs;

        auto& registry = Registry<Model>::Get();
        auto entity = registry.Create();

        registry.Assign<PositionComponent, RotationComponent>(entity, {{}, 0.0f, 0.0f, 0.0f}, {{}, 30.0f, 90.0f, 0.0f});
    }

    void OnDetach() noexcept override {}

    void OnUpdate(float deltaTime) noexcept override {
        m_RenderingSystem.OnUpdate(deltaTime);
    }

    void OnRender() noexcept override {}

private:
    Bald::Ecs::RenderingSystem m_RenderingSystem;
};

class EcsExample : public Bald::Application {
GENERATE_BODY(DERIVED)

public:
    EcsExample() {
        PushLayer<ExampleLayer>();
    }

    ~EcsExample() override = default;
};

Bald::Application* Bald::Application::Create() noexcept {
    return new EcsExample();
}
