//
// Created by blinku on 29.07.2019.
//

#include "opengl_texture.h"
#include "bald_assert.h"
#include "glad/glad.h"

extern "C" unsigned char* stbi_load(char const *filename, int *x, int *y, int *channels_in_file, int desired_channels);
extern "C" void stbi_image_free(void* retval_from_stbi_load);
extern "C" void stbi_set_flip_vertically_on_load(int flag_true_if_should_flip);

namespace Bald::Platform::Graphics {

    OpenGLTexture::OpenGLTexture(std::string filepath) : Texture(std::move(filepath)), m_ID(0) {
        stbi_set_flip_vertically_on_load(true);
        m_Data = stbi_load(m_Filepath.c_str(), &m_Width, &m_Height, &m_NrChannels, 0);
        if(m_Data) {
            uint32_t format = 0;
            switch(m_NrChannels) {
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
                    BALD_ASSERT(false, "OpenGLTexture", "Texture format (number of channels) is unknown!", m_NrChannels);
                    break;
            }

            glGenTextures(1, &m_ID);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, m_ID);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            glTexImage2D(GL_TEXTURE_2D, 0, static_cast<int32_t>(format), m_Width, m_Height, 0, format, GL_UNSIGNED_BYTE, m_Data);
            glGenerateMipmap(GL_TEXTURE_2D);

            glBindTexture(GL_TEXTURE_2D, 0);
        } else {
            CORE_LOG_ERROR("[OpenGLTexture] Failed to load texture!");
        }
    }

    OpenGLTexture::~OpenGLTexture() {
        glDeleteTextures(1, &m_ID);
        stbi_image_free(m_Data);
    }

    void OpenGLTexture::Bind() const noexcept {
        glBindTexture(GL_TEXTURE_2D, m_ID);
    }

    void OpenGLTexture::Unbind() const noexcept {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void OpenGLTexture::Activate(uint8_t index) const noexcept {
        if(index < 16) {
            glActiveTexture(GL_TEXTURE0 + index);
        } else {
            BALD_ASSERT(false, "OpenGLTexture", "OpenGL only guarantees to support 16 textures per shader!", index);
        }
    }

    void OpenGLTexture::SetWrapping(Bald::Graphics::TextureCoordinate texCoord, Bald::Graphics::TextureWrapMode wrappingMode) {
        auto setTexParameter = [&wrappingMode](uint32_t coord) {
            switch(wrappingMode) {
                case Bald::Graphics::TextureWrapMode::Repeat:           glTexParameteri(GL_TEXTURE_2D, coord, GL_REPEAT); break;
                case Bald::Graphics::TextureWrapMode::MirroredRepeat:   glTexParameteri(GL_TEXTURE_2D, coord, GL_MIRRORED_REPEAT); break;
                case Bald::Graphics::TextureWrapMode::ClampToEdge:      glTexParameteri(GL_TEXTURE_2D, coord, GL_CLAMP_TO_EDGE); break;
                case Bald::Graphics::TextureWrapMode::ClampToBorder:    glTexParameteri(GL_TEXTURE_2D, coord, GL_CLAMP_TO_BORDER); break;
                default: BALD_ASSERT(false, "OpenGLTexture", "Unknown texture wrapping mode!", static_cast<uint8_t>(wrappingMode)); break;
            }
        };

        switch(texCoord) {
            case Bald::Graphics::TextureCoordinate::S: setTexParameter(GL_TEXTURE_WRAP_S); break;
            case Bald::Graphics::TextureCoordinate::T: setTexParameter(GL_TEXTURE_WRAP_T); break;
            default: BALD_ASSERT(false, "OpenGLTexture", "Unknown texture coordinate!", static_cast<uint8_t>(texCoord));
        }
    }

    void OpenGLTexture::SetFiltering(Bald::Graphics::TextureFilterMode filterMode, Bald::Graphics::TextureFilterMethod filterMethod) {
        auto setFilterMethod = [&filterMethod](uint32_t mode) {
            switch(filterMethod) {
                case Bald::Graphics::TextureFilterMethod::Nearest:              glTexParameteri(GL_TEXTURE_2D, mode, GL_NEAREST); break;
                case Bald::Graphics::TextureFilterMethod::Linear:               glTexParameteri(GL_TEXTURE_2D, mode, GL_LINEAR); break;
                case Bald::Graphics::TextureFilterMethod::NearestMipmapNearest: glTexParameteri(GL_TEXTURE_2D, mode, GL_NEAREST_MIPMAP_NEAREST); break;
                case Bald::Graphics::TextureFilterMethod::NearestMipmapLinear:  glTexParameteri(GL_TEXTURE_2D, mode, GL_NEAREST_MIPMAP_LINEAR); break;
                case Bald::Graphics::TextureFilterMethod::LinearMipmapNearest:  glTexParameteri(GL_TEXTURE_2D, mode, GL_LINEAR_MIPMAP_NEAREST); break;
                case Bald::Graphics::TextureFilterMethod::LinearMipmapLinear:   glTexParameteri(GL_TEXTURE_2D, mode, GL_LINEAR_MIPMAP_LINEAR); break;
                default: BALD_ASSERT(false, "OpenGLTexture", "Unknown texture filter method!", static_cast<uint8_t>(filterMethod));
            }
        };

        switch(filterMode) {
            case Bald::Graphics::TextureFilterMode::Min: setFilterMethod(GL_TEXTURE_MIN_FILTER); break;
            case Bald::Graphics::TextureFilterMode::Mag: setFilterMethod(GL_TEXTURE_MAG_FILTER); break;
            default: BALD_ASSERT(false, "OpenGLTexture", "Unknown texture filter mode!", static_cast<uint8_t>(filterMode));
        }
    }

} // END OF NAMESPACE Bald::Platform::Graphics
