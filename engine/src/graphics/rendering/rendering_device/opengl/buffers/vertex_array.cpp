//
// Created by blinku on 08.05.19.
//

#include "vertex_array.h"
#include "buffer.h"
#include "glad/glad.h"

namespace Bald::Graphics {

    VertexArray::VertexArray() noexcept : m_ArrayID(0) {
        glGenVertexArrays(1, &m_ArrayID);
    }

    VertexArray::~VertexArray() {

        std::for_each(m_Buffers.begin(), m_Buffers.end(), [](Buffer* param) { delete param; });

        glDeleteVertexArrays(1, &m_ArrayID);
    }

    void VertexArray::AddBuffer(Buffer* buffer, [[maybe_unused]] unsigned index) noexcept {

        Bind();
        buffer->Bind();

        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, buffer->GetComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

        m_Buffers.push_back(buffer);

        buffer->Unbind();
        Unbind();

    }

    void VertexArray::Bind() noexcept {
        glBindVertexArray(m_ArrayID);
    }

    void VertexArray::Unbind() noexcept {
        glBindVertexArray(0);
    }

} // END OF NAMESPACE Bald::Graphics
