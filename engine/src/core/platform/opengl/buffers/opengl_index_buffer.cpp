//
// Created by blinku on 22.07.19.
//

#include "opengl_index_buffer.h"
#include "glad/glad.h"

namespace Bald::Platform::Graphics {

    OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned* data, unsigned size) noexcept : m_BufferID(0), m_Size(size) {
        glGenBuffers(1, &m_BufferID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
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