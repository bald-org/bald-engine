//
// Created by blinku on 26.02.2020.
//

#pragma once

#include "core.h"

#include "registry.hpp"

namespace Bald::Ecs {

    class System {
    GENERATE_BODY(BASE)

    public:
        virtual ~System() = default;

        virtual void OnUpdate(float deltaTime) noexcept = 0;
    };

    class RenderingSystem : public System {
    GENERATE_BODY(DERIVED)

    public:
        void OnUpdate(float deltaTime) noexcept override {
            CORE_LOG_TRACE("Rendering, ts=" + std::to_string(deltaTime));

            auto registry = Registry<Model>::Get();
            auto view = registry.View<PositionComponent, RotationComponent>();

            for(auto entity : view) {
                CORE_LOG_TRACE(std::to_string(entity.m_Signature));
                // const auto& positionComponent = view.get<PositionComponent>(entity);
                // Renderer::Submit(...);
            }

        }
    };

} // END OF NAMESPACE Bald::Ecs