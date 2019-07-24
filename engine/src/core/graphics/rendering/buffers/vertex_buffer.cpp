//
// Created by blinku on 08.05.19.
//

#include "vertex_buffer.h"
#include "platform/opengl/buffers/opengl_vertex_buffer.h"

namespace Bald::Graphics {

    VertexBuffer* VertexBuffer::Create(float* data, unsigned size) {
        return new Bald::Platform::Graphics::OpenGLVertexBuffer(data, size);
    }
} // END OF NAMESPACE Bald::Graphics