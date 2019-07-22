//
// Created by blinku on 08.05.19.
//

#include "vertex_array.h"
#include "platform/graphics/renderer/rendering_device/buffers/opengl_vertex_array.h"
#include "glad/glad.h"

namespace Bald::Graphics {

    VertexArray* VertexArray::Create() noexcept {
        return new Bald::Platform::Graphics::OpenGLVertexArray();
    }

} // END OF NAMESPACE Bald::Graphics
