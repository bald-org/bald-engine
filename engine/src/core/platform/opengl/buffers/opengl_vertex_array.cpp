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

    void OpenGLVertexArray::AddVertexBuffer(Bald::Graphics::VertexBuffer* buffer) noexcept {
        Bind();
        buffer->Bind();

        const auto& layout = buffer->GetLayout();
        for(const auto& layoutElement : layout) {

            glEnableVertexAttribArray(layoutElement.GetShaderLayoutLocation());
            glVertexAttribPointer(layoutElement.GetShaderLayoutLocation(),
                                  static_cast<int>(layoutElement.GetComponentCount()),
                                  layoutElement.GetOpenGLType(),
                                  layoutElement.IsNormalized() ? GL_TRUE : GL_FALSE,
                                  static_cast<int>(layout.GetStride()),
                                  reinterpret_cast<const void*>(layoutElement.GetOffset()));
        }

        m_Buffers.push_back(buffer);

        Unbind();
        buffer->Unbind();
    }

    void OpenGLVertexArray::AddIndexBuffer(Bald::Graphics::IndexBuffer* indexBuffer) noexcept {
        Bind();
        indexBuffer->Bind();
        Unbind();
        indexBuffer->Unbind();
    }

    void OpenGLVertexArray::Bind() const noexcept {
        glBindVertexArray(m_ArrayID);
    }

    void OpenGLVertexArray::Unbind()const noexcept {
        glBindVertexArray(0);
    }

} // END OF NAMESPACE Bald::Platform::Graphics
