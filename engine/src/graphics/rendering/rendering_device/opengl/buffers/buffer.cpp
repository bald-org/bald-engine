//
// Created by blinku on 08.05.19.
//

#include "buffer.h"
#include "glad/glad.h"

namespace Bald::Graphics {

    Buffer::Buffer(float* data, int count, unsigned component_count) noexcept : m_BufferID(0),
                                                                                m_ComponentCount(component_count) {
        glGenBuffers(1, &m_BufferID);
        glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
        glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    Buffer::~Buffer() {
        glDeleteBuffers(1, &m_BufferID);
    }

    void Buffer::Bind() const noexcept {
        glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
    }

    void Buffer::Unbind() const noexcept {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

} // END OF NAMESPACE Bald::Graphics