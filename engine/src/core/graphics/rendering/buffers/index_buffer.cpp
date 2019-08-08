//
// Created by blinku on 08.05.19.
//

#include "index_buffer.h"
#include "platform/opengl/buffers/opengl_index_buffer.h"

namespace Bald::Graphics {

    std::shared_ptr<IndexBuffer> IndexBuffer::Create(unsigned* data, unsigned size) {
        return std::shared_ptr<Bald::Platform::Graphics::OpenGLIndexBuffer>(new Bald::Platform::Graphics::OpenGLIndexBuffer(data, size));
    }
} // END OF NAMESPACE Bald::Graphics