//
// Created by blinku on 29.07.2019.
//

#include "texture.h"
#include "platform/opengl/textures/opengl_texture.h"
#include <iostream>

namespace Bald::Graphics {

    std::shared_ptr<Texture> Texture::Create(const int32_t width, const int32_t height) {
        return std::shared_ptr<Texture>(new Bald::Platform::Graphics::OpenGLTexture(width, height));
    }

    std::shared_ptr<Texture> Texture::Create(const std::string& filepath) {
        return std::shared_ptr<Texture>(new Bald::Platform::Graphics::OpenGLTexture(filepath));
    }

} // END OF NAMESPACE Bald::Graphics


