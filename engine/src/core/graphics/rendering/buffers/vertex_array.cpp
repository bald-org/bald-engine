//
// Created by blinku on 08.05.19.
//

#include "vertex_array.h"
#include "platform/opengl/buffers/opengl_vertex_array.h"

namespace Bald::Graphics {

    VertexArray* VertexArray::Create() {
        return new Bald::Platform::Graphics::OpenGLVertexArray();
    }

} // END OF NAMESPACE Bald::Graphics
