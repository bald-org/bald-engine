//
// Created by blinku on 29.07.2019.
//

#include "texture.h"
#include "platform/opengl/textures/opengl_texture.h"
#include <iostream>

namespace Bald::Graphics {

    Texture* Texture::Create(const std::string& filepath) {
        return new Bald::Platform::Graphics::OpenGLTexture(filepath);
    }

} // END OF NAMESPACE Bald::Graphics


