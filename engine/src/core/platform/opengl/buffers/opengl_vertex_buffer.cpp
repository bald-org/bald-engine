//
// Created by blinku on 22.07.19.
//

#include "opengl_vertex_buffer.h"
#include "glad/glad.h"

namespace Bald::Platform::Graphics {

    OpenGLVertexBuffer::OpenGLVertexBuffer(float* data, unsigned size) noexcept
    :   m_BufferID(0) {
        glGenBuffers(1, &m_BufferID);
        glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer() {
        glDeleteBuffers(1, &m_BufferID);
    }

    void OpenGLVertexBuffer::Bind() const noexcept {
        glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
    }

    void OpenGLVertexBuffer::Unbind() const noexcept {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

} // END OF NAMESPACE Bald::Platform::Graphics