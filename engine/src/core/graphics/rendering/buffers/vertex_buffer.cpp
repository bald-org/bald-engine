//
// Created by blinku on 08.05.19.
//

#include "vertex_buffer.h"
#include "platform/opengl/buffers/opengl_vertex_buffer.h"

namespace Bald::Graphics {

    VertexBuffer* VertexBuffer::Create(float* data, unsigned count, unsigned component_count) {
        return new Bald::Platform::Graphics::OpenGLVertexBuffer(data, count, component_count);
    }

} // END OF NAMESPACE Bald::Graphics