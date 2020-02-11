//
// Created by blinku on 08.02.2020.
//

#pragma once

#include <memory>
#include "glm/glm.hpp"
#include "graphics/rendering/textures/texture.h"

namespace Bald::Graphics {

    struct MaterialProps {
        glm::vec4 m_Ambient;
        glm::vec4 m_Diffuse;
        glm::vec4 m_Specular;
        float m_Shininess;
        std::shared_ptr<Texture> m_DiffuseMap;
        std::shared_ptr<Texture> m_SpecularMap;
    };

    class Material {

        explicit Material(const MaterialProps& materialProps);

    public:

        [[nodiscard]] static std::unique_ptr<Material> Create(const MaterialProps& materialProps);

        void SetAmbient(const glm::vec4& ambient) { m_Ambient = ambient; }

        void SetDiffuse(const glm::vec4& diffuse) { m_Diffuse = diffuse; }

        void SetSpecular(const glm::vec4& specular) { m_Specular = specular; }

        void SetShininess(float shininess) { m_Shininess = shininess; }

        void SetDiffuseMap(const std::shared_ptr<Texture>& texture) { m_DiffuseMap = texture; }

        void SetSpecularMap(const std::shared_ptr<Texture>& texture) { m_SpecularMap = texture; }

        [[nodiscard]] const glm::vec4& GetAmbient() const noexcept { return m_Ambient; }

        [[nodiscard]] const glm::vec4& GetDiffuse() const noexcept { return m_Diffuse; }

        [[nodiscard]] const glm::vec4& GetSpecular() const noexcept { return m_Specular; }

        [[nodiscard]] float GetShininess() const noexcept { return m_Shininess; }

        [[nodiscard]] const std::shared_ptr<Texture>& GetDiffuseMap() const noexcept { return m_DiffuseMap; }

        [[nodiscard]] const std::shared_ptr<Texture>& GetSpecularMap() const noexcept { return m_SpecularMap; }

    private:
        glm::vec4 m_Ambient = glm::vec4{0.2f, 0.2f, 0.2f, 1.0f};
        glm::vec4 m_Diffuse = glm::vec4{0.8f, 0.2f, 0.2f, 1.0f};
        glm::vec4 m_Specular = glm::vec4{0.5f, 0.5f, 0.5f, 1.0f};
        float m_Shininess = 32.0f;
        std::shared_ptr<Texture> m_DiffuseMap = nullptr;
        std::shared_ptr<Texture> m_SpecularMap = nullptr;
    }; // END OF CLASS Material

} // END OF NAMESPACE Bald::Graphics