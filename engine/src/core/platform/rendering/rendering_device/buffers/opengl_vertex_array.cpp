//
// Created by blinku on 22.07.19.
//

#include "opengl_vertex_array.h"
#include "buffer.h"
#include "glad/glad.h"

namespace Bald::Platform::Graphics {

    OpenGLOpenGLVertexArray::OpenGLOpenGLVertexArray() noexcept : m_ArrayID(0) {
        glGenOpenGLOpenGLVertexArrays(1, &m_ArrayID);
    }

    OpenGLOpenGLVertexArray::~OpenGLOpenGLVertexArray() {

        std::for_each(m_Buffers.begin(), m_Buffers.end(), [](Buffer* buffer) { delete buffer; });

        glDeleteOpenGLOpenGLVertexArrays(1, &m_ArrayID);
    }

    void OpenGLOpenGLVertexArray::AddBuffer(Buffer* buffer, [[maybe_unused]] unsigned index) noexcept {

        Bind();
        buffer->Bind();

        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, buffer->GetComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

        m_Buffers.push_back(buffer);

        // As far as I remember we shouldnt unbind the buffer here. This will end up in it not being bound to vertex array object.
        // Gotta check this.
        // buffer->Unbind();
        Unbind();

    }

    void OpenGLOpenGLVertexArray::Bind() noexcept {
        glBindVertexArray(m_ArrayID);
    }

    void OpenGLOpenGLVertexArray::Unbind() noexcept {
        glBindVertexArray(0);
    }

} // END OF NAMESPACE Bald::Platform::Graphics
