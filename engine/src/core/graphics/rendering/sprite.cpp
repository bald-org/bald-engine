//
// Created by blinku on 09.08.2019.
//

#include "sprite.h"

namespace Bald::Graphics {

    Sprite::Sprite(const glm::vec4& color)
        : m_Rotation(0.0f),
          m_Position(0.0f),
          m_Size(100.0f) {

        MaterialProps materialProps = {
            glm::vec4{0.2f, 0.2f, 0.2f, 1.0f},
            color,
            glm::vec4{0.5f, 0.5f, 0.5f, 1.0f},
            32.0f,
            Texture::Create(1, 1),
            nullptr
        };

        m_Material = Material::Create(materialProps);
    }

    Sprite::Sprite(std::shared_ptr<Texture> texture)
        : m_Rotation(0.0f),
          m_Position(0.0f),
          m_Size(100.0f) {

        MaterialProps materialProps = {
            glm::vec4{0.2f, 0.2f, 0.2f, 1.0f},
            glm::vec4{1.0f, 1.0f, 1.0f, 1.0f},
            glm::vec4{0.5f, 0.5f, 0.5f, 1.0f},
            32.0f,
            std::move(texture),
            nullptr
        };

        m_Material = Material::Create(materialProps);
    }

} // END OF NAMESPACE Bald::Graphics