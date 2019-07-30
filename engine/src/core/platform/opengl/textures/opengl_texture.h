//
// Created by blinku on 29.07.2019.
//

#pragma once

#include "pch.h"
#include "graphics/rendering/textures/texture.h"

namespace Bald::Platform::Graphics {

    class OpenGLTexture : public Bald::Graphics::Texture {
    public:
        OpenGLTexture() = delete;
        explicit OpenGLTexture(std::string filepath);

        ~OpenGLTexture() override;

        void Bind() const noexcept override;
        void Unbind() const noexcept override;
        void Activate(uint8_t index) const noexcept override;
        void SetWrapping(Bald::Graphics::TextureCoordinate texCoord, Bald::Graphics::TextureWrapMode wrappingMode) override;
        void SetFiltering(Bald::Graphics::TextureFilterMode filterMode, Bald::Graphics::TextureFilterMethod filterMethod) override;

    private:
        uint32_t m_ID;
    };

}


