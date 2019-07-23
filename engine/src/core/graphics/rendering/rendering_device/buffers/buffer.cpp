//
// Created by blinku on 08.05.19.
//

#include "buffer.h"
#include "platform/graphics/rendering/rendering_device/buffers/opengl_buffer.h"
#include "glad/glad.h"

namespace Bald::Graphics {

    Buffer* Buffer::Create(float* data, unsigned count, unsigned component_count) {
        return new Bald::Platform::Graphics::OpenGLBuffer(data, count, component_count);
    }

} // END OF NAMESPACE Bald::Graphics