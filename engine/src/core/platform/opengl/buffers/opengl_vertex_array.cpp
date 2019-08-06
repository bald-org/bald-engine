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
        glDeleteVertexArrays(1, &m_ArrayID);
    }

    void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<Bald::Graphics::VertexBuffer>& buffer) noexcept {
        Bind();
        buffer->Bind();

        const auto& layout = buffer->GetLayout();
        for(const auto& layoutElement : layout) {

            glEnableVertexAttribArray(layoutElement.GetShaderLayoutLocation());
            glVertexAttribPointer(layoutElement.GetShaderLayoutLocation(),
                                  static_cast<int>(layoutElement.GetComponentCount()),
                                  layoutElement.GetOpenGLType(),
                                  layoutElement.IsNormalized(),
                                  static_cast<int>(layout.GetStride()),
                                  reinterpret_cast<const void*>(layoutElement.GetOffset()));
        }

        m_VertexBuffers.push_back(buffer);

        Unbind();
        buffer->Unbind();
    }

    void OpenGLVertexArray::AddIndexBuffer(const std::shared_ptr<Bald::Graphics::IndexBuffer>& indexBuffer) noexcept {
        Bind();
        indexBuffer->Bind();

        m_IndexBuffer = indexBuffer;

        Unbind();
        indexBuffer->Unbind();
    }

    std::shared_ptr<Bald::Graphics::IndexBuffer> OpenGLVertexArray::GetIndexBuffer() noexcept {
        return m_IndexBuffer;
    }

    void OpenGLVertexArray::Bind() const noexcept {
        glBindVertexArray(m_ArrayID);
    }

    void OpenGLVertexArray::Unbind()const noexcept {
        glBindVertexArray(0);
    }

} // END OF NAMESPACE Bald::Platform::Graphics
