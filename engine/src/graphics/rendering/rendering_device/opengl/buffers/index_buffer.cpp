//
// Created by blinku on 08.05.19.
//

#include "index_buffer.h"
#include "glad/glad.h"

namespace Bald::Graphics {

    IndexBuffer::IndexBuffer(unsigned short* data, unsigned count) noexcept : m_Count(count) {
        glGenBuffers(1, &m_BufferID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned short), data, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    IndexBuffer::~IndexBuffer() {
        glDeleteBuffers(1, &m_BufferID);
    }

    void IndexBuffer::Bind() const noexcept {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
    }

    void IndexBuffer::Unbind() const noexcept {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

} // END OF NAMESPACE Bald::Graphics