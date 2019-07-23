//
// Created by blinku on 22.07.19.
//

#include <algorithm>
#include "opengl_vertex_array.h"
#include "opengl_buffer.h"

#include "glad/glad.h"

namespace Bald::Platform::Graphics {

    OpenGLVertexArray::OpenGLVertexArray() noexcept : m_ArrayID(0) {
        glGenVertexArrays(1, &m_ArrayID);
    }

    OpenGLVertexArray::~OpenGLVertexArray() {

        std::for_each(m_Buffers.begin(), m_Buffers.end(), [](Bald::Graphics::Buffer* buffer) { delete buffer; });

        glDeleteVertexArrays(1, &m_ArrayID);
    }

    void OpenGLVertexArray::AddBuffer(Bald::Graphics::Buffer* buffer, [[maybe_unused]] unsigned index) noexcept {

        Bind();
        buffer->Bind();

        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, static_cast<int>(buffer->GetComponentCount()), GL_FLOAT, GL_FALSE, static_cast<int>(buffer->GetComponentCount() * sizeof(float)), nullptr);

        m_Buffers.push_back(buffer);

        // As far as I remember we shouldn't unbind the buffer here. This will end up in it not being bound to vertex array object.
        // Gotta check this.
        // buffer->Unbind();
        Unbind();

    }

    void OpenGLVertexArray::Bind() noexcept {
        glBindVertexArray(m_ArrayID);
    }

    void OpenGLVertexArray::Unbind() noexcept {
        glBindVertexArray(0);
    }

} // END OF NAMESPACE Bald::Platform::Graphics
