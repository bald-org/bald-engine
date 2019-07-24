//
// Created by blinku on 22.07.19.
//

#include "opengl_vertex_array.h"
#include "opengl_vertex_buffer.h"
#include "glad/glad.h"

namespace Bald::Platform::Graphics {

    OpenGLVertexArray::OpenGLVertexArray() noexcept : m_ArrayID(0) {
        glGenVertexArrays(1, &m_ArrayID);
    }

    OpenGLVertexArray::~OpenGLVertexArray() {
        for(auto* buffer : m_Buffers) {
            delete buffer;
        }

        glDeleteVertexArrays(1, &m_ArrayID);
    }

    void OpenGLVertexArray::AddVertexBuffer(Bald::Graphics::VertexBuffer* buffer, [[maybe_unused]] unsigned index) noexcept {

        Bind();
        buffer->Bind();

        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, static_cast<int>(buffer->GetComponentCount()), GL_FLOAT, GL_FALSE, static_cast<int>(buffer->GetComponentCount() * sizeof(float)), nullptr);

        m_Buffers.push_back(buffer);

        Unbind();
        buffer->Unbind();

    }

    void OpenGLVertexArray::Bind() const noexcept {
        glBindVertexArray(m_ArrayID);
    }

    void OpenGLVertexArray::Unbind()const noexcept {
        glBindVertexArray(0);
    }

} // END OF NAMESPACE Bald::Platform::Graphics
