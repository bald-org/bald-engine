//
// Created by blinku on 26.02.2020.
//

#pragma once

#include "utils/generate_body.h"
#include "pch.h"

namespace Bald::Ecs {

    template<typename EntityType>
    class Registry {

        using ContainerType = std::vector<EntityType>;

    GENERATE_BODY(NORMAL)

        static Registry& Get() noexcept {
            return m_Registry;
        }

    public:
        auto Create() {
            m_Entities.emplace_back();
            return m_Entities.back();
        }

        template<typename ... Components>
        void Assign(EntityType, [[maybe_unused]] Components&& ... components) noexcept {

            Entity::SignatureType signature = GetSignature<Components ...>();
            EntityType::m_Signature = signature;

            CORE_LOG_TRACE("Entity ID = " + std::to_string(EntityType::m_Signature));
        }

        template<typename ... Components>
        ContainerType& View() noexcept {
            // TODO: Return matching entities
            return m_Entities;
        }


    private:
        Registry() = default;

        template<typename ... Components>
        [[nodiscard]] Entity::SignatureType GetSignature() const noexcept {
            // TODO: Calculate signature based on TypeList (probably just return compile-time calculated SignatureType)
            return {};
        }

    private:
        ContainerType m_Entities;

    private:
        static Registry m_Registry;
    };

    template<typename EntityType>
    Registry<EntityType> Registry<EntityType>::m_Registry = {};

} // END OF NAMESPACE Bald::Ecs
