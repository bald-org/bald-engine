//
// Created by blinku on 08.05.19.
//

#include "vertex_array.h"
#include "buffer.h"
#include "glad/glad.h"

namespace Bald::Graphics {

    std::unique_ptr<VertexArray> VertexArray::Create() noexcept {
        return std::make_unique<Bald::Platform::Graphics::OpenGLVertexArray>();
    }

} // END OF NAMESPACE Bald::Graphics
