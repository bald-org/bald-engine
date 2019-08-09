//
// Created by blinku on 09.08.2019.
//

#include "sprite.h"

namespace Bald::Graphics {


    Sprite::Sprite(std::shared_ptr<Texture> texture)
        : m_Rotation(0.0f),
          m_Position(0.0f),
          m_Size(1.0f),
          m_Color(0.0f),
          m_Texture(std::move(texture)) {}
          
} // END OF NAMESPACE Bald::Graphics