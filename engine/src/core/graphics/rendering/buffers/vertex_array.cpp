//
// Created by blinku on 08.05.19.
//

#include "vertex_array.hpp"
#include "platform/opengl/buffers/opengl_vertex_array.hpp"

namespace Bald::Graphics {

    std::shared_ptr<VertexArray> VertexArray::Create() {
        return std::shared_ptr<Bald::Platform::Graphics::OpenGLVertexArray>(new Bald::Platform::Graphics::OpenGLVertexArray);
    }

} // END OF NAMESPACE Bald::Graphics
