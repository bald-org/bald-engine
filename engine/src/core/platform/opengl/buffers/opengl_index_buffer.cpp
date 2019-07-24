//
// Created by blinku on 22.07.19.
//

#include "opengl_index_buffer.h"
#include "glad/glad.h"

namespace Bald::Platform::Graphics {

    OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned short* data, unsigned count) noexcept : m_BufferID(0), m_Count(count) {
        glGenBuffers(1, &m_BufferID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned short), data, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer() {
        glDeleteBuffers(1, &m_BufferID);
    }

    void OpenGLIndexBuffer::Bind() const noexcept {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
    }

    void OpenGLIndexBuffer::Unbind() const noexcept {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

} // END OF NAMESPACE Bald::Platform::Graphics