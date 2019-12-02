//
// Created by blinku on 09.08.2019.
//

#include "sprite.h"

namespace Bald::Graphics {

    Sprite::Sprite(const glm::vec4& color)
        : m_Rotation(0.0f),
          m_Position(0.0f),
          m_Size(1.0f),
          m_Color(color),
          m_Texture{Texture::Create(1, 1)} {}

    Sprite::Sprite(std::shared_ptr<Texture> texture)
        : m_Rotation(0.0f),
          m_Position(0.0f),
          m_Size(1.0f),
          m_Color(1.0f),
          m_Texture(std::move(texture)) {}

} // END OF NAMESPACE Bald::Graphics