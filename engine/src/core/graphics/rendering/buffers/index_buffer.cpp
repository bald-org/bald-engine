//
// Created by blinku on 08.05.19.
//

#include "index_buffer.h"
#include "platform/opengl/buffers/opengl_index_buffer.h"

namespace Bald::Graphics {

    IndexBuffer* IndexBuffer::Create(unsigned short* data, unsigned count) {
        return new Bald::Platform::Graphics::OpenGLIndexBuffer(data, count);
    }
} // END OF NAMESPACE Bald::Graphics