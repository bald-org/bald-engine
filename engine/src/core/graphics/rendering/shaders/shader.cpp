//
// Created by blinku on 28.05.19.
//

#include "shader.h"
#include "src/core/platform/opengl/shaders/opengl_shader.h"


namespace Bald::Graphics {

    Shader* Graphics::Shader::Create(const char* vertexPath, const char* fragmentPath) {
        return new Bald::Platform::Graphics::OpenGLShader(vertexPath, fragmentPath);
    }
} // END OF NAMESPACE Bald::Graphics