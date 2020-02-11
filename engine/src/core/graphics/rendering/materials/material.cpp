//
// Created by blinku on 08.02.2020.
//

#include "material.hpp"

namespace Bald::Graphics {

    Material::Material(const MaterialProps& materialProps)
        : m_Ambient{materialProps.m_Ambient}
        , m_Diffuse{materialProps.m_Diffuse}
        , m_Specular{materialProps.m_Specular}
        , m_Shininess{materialProps.m_Shininess}
        , m_DiffuseMap{materialProps.m_DiffuseMap}
        , m_SpecularMap{materialProps.m_SpecularMap} {}

    std::unique_ptr<Material> Material::Create(const MaterialProps& materialProps) {
        return std::unique_ptr<Material>(new Material(materialProps));
    }

} // END OF NAMESPACE Bald::Graphics
