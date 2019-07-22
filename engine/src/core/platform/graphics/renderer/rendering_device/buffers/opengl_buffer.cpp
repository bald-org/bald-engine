//
// Created by blinku on 22.07.19.
//

#include "opengl_buffer.h"
#include "glad/glad.h"

namespace Bald::Platform::Graphics {

    OpenGLBuffer::OpenGLBuffer(float* data, int count, int component_count) noexcept
    :   m_BufferID(0),
        m_ComponentCount(component_count) {
        glGenBuffers(1, &m_BufferID);
        glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
        glBufferData(GL_ARRAY_BUFFER, count * static_cast<int>(sizeof(float)), data, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    OpenGLBuffer::~OpenGLBuffer() {
        glDeleteBuffers(1, &m_BufferID);
    }

    void OpenGLBuffer::Bind() const noexcept {
        glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
    }

    void OpenGLBuffer::Unbind() const noexcept {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

} // END OF NAMESPACE Bald::Platform::Graphics