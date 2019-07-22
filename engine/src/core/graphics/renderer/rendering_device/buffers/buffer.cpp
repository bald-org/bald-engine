//
// Created by blinku on 08.05.19.
//

#include "buffer.h"
#include "platform/rendering/rendering_device/buffers/opengl_buffer.h"
#include "glad/glad.h"

namespace Bald::Graphics {

    std::unique_ptr<Buffer> Buffer::Create(float* data, int count, unsigned component_count) noexcept {
        return std::make_unique<Bald::Platform::Graphics::OpenGLBuffer>((data, count, component_count));
    }

} // END OF NAMESPACE Bald::Graphics