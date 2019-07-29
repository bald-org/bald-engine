//
// Created by blinku on 29.07.2019.
//

#include "opengl_texture.h"
#include "bald_assert.h"
#include "glad/glad.h"

unsigned char* stbi_load(char const *filename, int* x, int*y, int *channels_in_file, int desired_channels);
void stbi_image_free(void* retval_from_stbi_load);

namespace Bald::Platform::Graphics {

    OpenGLTexture::OpenGLTexture(std::string filepath) : Texture(std::move(filepath)), m_ID(0) {
        m_Data = stbi_load("container.jpg", &m_Width, &m_Height, &m_NrChannels, 0);

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
            glBindTexture(GL_TEXTURE_2D, m_ID);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            glTexImage2D(GL_TEXTURE_2D, 0, format, m_Width, m_Height, 0, format, GL_UNSIGNED_BYTE, m_Data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            CORE_LOG_ERROR("[OpenGLTexture] Failed to load texture!");
        }
    }

    OpenGLTexture::~OpenGLTexture() {
        stbi_image_free(m_Data);
    }

    void OpenGLTexture::Bind() const noexcept {
        glBindTexture(GL_TEXTURE_2D, m_ID);
    }

    void OpenGLTexture::Unbind() const noexcept {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

} // END OF NAMESPACE Bald::Platform::Graphics


