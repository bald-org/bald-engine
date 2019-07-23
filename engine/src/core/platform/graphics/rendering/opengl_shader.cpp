//
// Created by blinku on 28.05.19.
//

#include "opengl_shader.h"

#include "opengl_shader.h"
#include "file_manager.h"
#include "pch.h"
#include "glad/glad.h"

namespace Bald::Platform::Graphics {

    OpenGLShader::OpenGLShader(const char* vertexPath, const char* fragmentPath)
        : m_VertexPath(vertexPath), m_FragmentPath(fragmentPath) {
        m_ShaderID = CreateShader();
    }

    OpenGLShader::~OpenGLShader() {
        glDeleteProgram(m_ShaderID);
    }

    void OpenGLShader::Bind() const {
        glUseProgram(m_ShaderID);
    }

    void OpenGLShader::Unbind() const {
        glUseProgram(0);
    }

    void OpenGLShader::SetUniform4f(const char* uniformName, float v0, float v1, float v2, float v3) const {
        glUniform4f(GetUniformLocation(uniformName), v0, v1, v2, v3);
    }

    unsigned OpenGLShader::GetShaderID() const {
        return m_ShaderID;
    }

    unsigned OpenGLShader::CreateShader() const {
        int success = 0;

        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);

        std::string vertexShaderSource = Utils::FileManager::ReadFile(m_VertexPath,
                                                                      Utils::FileManager::Size::SMALL_FILE);
        const char* vertexData = vertexShaderSource.c_str();

        glShaderSource(vertexShader, 1, &vertexData, nullptr);
        glCompileShader(vertexShader);

        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if(success == GL_FALSE) {
            int length = 0;
            glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &length);

            std::vector<char> errorLog(static_cast<unsigned>(length));
            glGetShaderInfoLog(vertexShader, length, &length, &errorLog[0]);

            glDeleteShader(vertexShader);

            CORE_LOG_ERROR("[Shader] Vertex shader compilation failed");
            CORE_LOG_ERROR(&errorLog[0]);

            return 0;
        }

        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

        std::string fragmentShaderSource = Utils::FileManager::ReadFile(m_FragmentPath,
                                                                        Utils::FileManager::Size::SMALL_FILE);
        const char* fragmentData = fragmentShaderSource.c_str();

        glShaderSource(fragmentShader, 1, &fragmentData, nullptr);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if(success == GL_FALSE) {
            int length = 0;
            glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &length);

            std::vector<char> errorLog(static_cast<unsigned>(length));
            glGetShaderInfoLog(fragmentShader, length, &length, &errorLog[0]);

            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            CORE_LOG_ERROR("[Shader] Fragment shader compilation failed");
            CORE_LOG_ERROR(&errorLog[0]);

            return 0;
        }

        unsigned int id = glCreateProgram();
        glAttachShader(id, vertexShader);
        glAttachShader(id, fragmentShader);
        glLinkProgram(id);

        glGetProgramiv(id, GL_LINK_STATUS, &success);
        if(success == GL_FALSE) {
            int length = 0;

            glGetProgramiv(id, GL_INFO_LOG_LENGTH, &length);

            std::vector<char> errorLog(static_cast<unsigned>(length));
            glGetProgramInfoLog(id, length, &length, &errorLog[0]);

            glDeleteProgram(id);
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            CORE_LOG_ERROR("[Shader] Linking failed");
            CORE_LOG_ERROR(&errorLog[0]);

            return 0;
        }

        glDetachShader(id, vertexShader);
        glDetachShader(id, fragmentShader);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return id;
    }

    int OpenGLShader::GetUniformLocation(const char* uniformName) const {
        if(m_UniformLocationCache.find(uniformName) != m_UniformLocationCache.end()) {
            return m_UniformLocationCache[uniformName];
        }
        int location = glGetUniformLocation(m_ShaderID, uniformName);
        m_UniformLocationCache[uniformName] = location;
        return location;
    }

} // END OF NAMESPACE Bald::Graphics