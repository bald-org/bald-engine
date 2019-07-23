//
// Created by blinku on 08.05.19.
//

#include "buffer.h"
#include "platform/opengl/buffers/opengl_buffer.h"

namespace Bald::Graphics {

    Buffer* Buffer::Create(float* data, unsigned count, unsigned component_count) {
        return new Bald::Platform::Graphics::OpenGLBuffer(data, count, component_count);
    }

} // END OF NAMESPACE Bald::Graphics