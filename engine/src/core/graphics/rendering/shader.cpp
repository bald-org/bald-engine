//
// Created by blinku on 28.05.19.
//

#include "shader.h"
#include "platform/graphics/rendering/opengl_shader.h"


namespace Bald::Graphics {

    Shader* Graphics::Shader::Create(const char* vertexPath, const char* fragmentPath) {
        return new Bald::Platform::Graphics::OpenGLShader(vertexPath, fragmentPath);
    }
} // END OF NAMESPACE Bald::Graphics