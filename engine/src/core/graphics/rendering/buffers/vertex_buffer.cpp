//
// Created by blinku on 08.05.19.
//

#include "vertex_buffer.h"
#include "platform/opengl/buffers/opengl_vertex_buffer.h"

namespace Bald::Graphics {

    std::shared_ptr<VertexBuffer> VertexBuffer::Create(float* data, unsigned size) {
        return std::shared_ptr<Bald::Platform::Graphics::OpenGLVertexBuffer>(new Bald::Platform::Graphics::OpenGLVertexBuffer(data, size));
    }

    void VertexBuffer::SetLayout(const Bald::Graphics::VertexBufferLayout& layout) noexcept {
        m_Layout = layout;

        uint32_t offset = 0;
        for(auto& layoutElement: m_Layout) {
            layoutElement.SetOffset(offset);
            offset += layoutElement.GetStride();
        }
    }

} // END OF NAMESPACE Bald::Graphics