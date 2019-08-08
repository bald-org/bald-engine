//
// Created by blinku on 29.07.2019.
//

#include "opengl_texture.h"
#include "bald_assert.h"
#include "glad/glad.h"

namespace Bald::Platform::Graphics {

    OpenGLTexture::OpenGLTexture(std::string filepath) : Texture(std::move(filepath)), m_ID(0) {
        [[maybe_unused]] bool state = Init();
        BALD_ASSERT(state, "Application", "Failed to initialized application", state);
    }

    OpenGLTexture::~OpenGLTexture() {
        Shutdown();
    }

    void OpenGLTexture::Bind() const noexcept {
        glBindTexture(GL_TEXTURE_2D, m_ID);
    }

    void OpenGLTexture::Unbind() const noexcept {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void OpenGLTexture::Activate(uint8_t index) const noexcept {
        BALD_ASSERT(index < 16, "OpenGLTexture", "OpenGL only guarantees to support 16 textures per shader!", index);
        glActiveTexture(GL_TEXTURE0 + index);
    }

    void OpenGLTexture::SetWrapping(Bald::Graphics::TextureCoordinate texCoord, Bald::Graphics::TextureWrapMode wrappingMode) {
        auto setTexParameter = [&wrappingMode](uint32_t coord) {
            BALD_ASSERT(static_cast<uint8_t>(wrappingMode), "OpenGLTexture", "Unknown texture wrapping mode!", static_cast<uint8_t>(wrappingMode));
            switch(wrappingMode) {
                case Bald::Graphics::TextureWrapMode::Repeat:           glTexParameteri(GL_TEXTURE_2D, coord, GL_REPEAT); break;
                case Bald::Graphics::TextureWrapMode::MirroredRepeat:   glTexParameteri(GL_TEXTURE_2D, coord, GL_MIRRORED_REPEAT); break;
                case Bald::Graphics::TextureWrapMode::ClampToEdge:      glTexParameteri(GL_TEXTURE_2D, coord, GL_CLAMP_TO_EDGE); break;
                case Bald::Graphics::TextureWrapMode::ClampToBorder:    glTexParameteri(GL_TEXTURE_2D, coord, GL_CLAMP_TO_BORDER); break;
                default: CORE_LOG_ERROR("[OpenGLTexture] Unknown texture wrapping mode!");
            }
        };

        BALD_ASSERT(static_cast<uint8_t>(texCoord), "OpenGLTexture", "Unknown texture coordinate!", static_cast<uint8_t>(texCoord));
        switch(texCoord) {
            case Bald::Graphics::TextureCoordinate::S: setTexParameter(GL_TEXTURE_WRAP_S); break;
            case Bald::Graphics::TextureCoordinate::T: setTexParameter(GL_TEXTURE_WRAP_T); break;
            default: CORE_LOG_ERROR("[OpenGLTexture] Unknown texture coordinate!");
        }
    }

    void OpenGLTexture::SetFiltering(Bald::Graphics::TextureFilterMode filterMode, Bald::Graphics::TextureFilterMethod filterMethod) {
        auto setFilterMethod = [&filterMethod](uint32_t mode) {
            BALD_ASSERT(static_cast<uint8_t>(filterMethod), "OpenGLTexture", "Unknown texture filter method!", static_cast<uint8_t>(filterMethod));
            switch(filterMethod) {
                case Bald::Graphics::TextureFilterMethod::Nearest:              glTexParameteri(GL_TEXTURE_2D, mode, GL_NEAREST); break;
                case Bald::Graphics::TextureFilterMethod::Linear:               glTexParameteri(GL_TEXTURE_2D, mode, GL_LINEAR); break;
                case Bald::Graphics::TextureFilterMethod::NearestMipmapNearest: glTexParameteri(GL_TEXTURE_2D, mode, GL_NEAREST_MIPMAP_NEAREST); break;
                case Bald::Graphics::TextureFilterMethod::NearestMipmapLinear:  glTexParameteri(GL_TEXTURE_2D, mode, GL_NEAREST_MIPMAP_LINEAR); break;
                case Bald::Graphics::TextureFilterMethod::LinearMipmapNearest:  glTexParameteri(GL_TEXTURE_2D, mode, GL_LINEAR_MIPMAP_NEAREST); break;
                case Bald::Graphics::TextureFilterMethod::LinearMipmapLinear:   glTexParameteri(GL_TEXTURE_2D, mode, GL_LINEAR_MIPMAP_LINEAR); break;
                default: CORE_LOG_ERROR("[OpenGLTexture] Unknown texture filter method!");
            }
        };

        BALD_ASSERT(static_cast<uint8_t>(filterMode), "OpenGLTexture", "Unknown texture coordinate!", static_cast<uint8_t>(filterMode));
        switch(filterMode) {
            case Bald::Graphics::TextureFilterMode::Min: setFilterMethod(GL_TEXTURE_MIN_FILTER); break;
            case Bald::Graphics::TextureFilterMode::Mag: setFilterMethod(GL_TEXTURE_MAG_FILTER); break;
            default: CORE_LOG_ERROR("[OpenGLTexture] Unknown texture filter mode!");
        }
    }

    bool OpenGLTexture::Init() noexcept {
        if(m_Image.GetData()) {
            uint32_t format = 0;
            switch(m_Image.GetNrChannels()) {
                case 1 :
                    format = GL_RED;
                    break;
                case 3 :
                    format = GL_RGB;
                    break;
                case 4 :
                    format = GL_RGBA;
                    break;
                default:
                    BALD_ASSERT(false, "OpenGLTexture", "Texture format (number of channels) is unknown!", m_Image.GetNrChannels());
                    break;
            }

            glGenTextures(1, &m_ID);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, m_ID);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            glTexImage2D(GL_TEXTURE_2D, 0, static_cast<int32_t>(format), m_Image.GetWidth(), m_Image.GetHeight(), 0, format, GL_UNSIGNED_BYTE, m_Image.GetData());
            glGenerateMipmap(GL_TEXTURE_2D);

            glBindTexture(GL_TEXTURE_2D, 0);
            return true;
        } else {
            CORE_LOG_ERROR("[OpenGLTexture] Failed to load texture!");
            return false;
        }
    }

    void OpenGLTexture::Shutdown() {
        glDeleteTextures(1, &m_ID);
    }

} // END OF NAMESPACE Bald::Platform::Graphics
