//
// Created by blinku on 08.05.19.
//

#include "index_buffer.h"
#include "platform/graphics/renderer/rendering_device/buffers/opengl_index_buffer.h"
#include "glad/glad.h"

namespace Bald::Graphics {

    IndexBuffer* IndexBuffer::Create(unsigned short* data, unsigned count) noexcept {
        return new Bald::Platform::Graphics::OpenGLIndexBuffer(data, count);
    }
} // END OF NAMESPACE Bald::Graphics