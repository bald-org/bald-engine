//
// Created by blinku on 28.05.19.
//

#include "opengl_shader.h"
#include <unordered_map>
#include "file_manager.h"
#include "pch.h"
#include "glad/glad.h"

namespace Bald::Platform::Graphics {

    OpenGLShader::OpenGLShader(const char* vertexPath, const char* fragmentPath)
        : m_ShaderID(CreateShader()), m_VertexPath(vertexPath), m_FragmentPath(fragmentPath) {}

    OpenGLShader::~OpenGLShader() {
        glDeleteProgram(m_ShaderID);
    }

    void OpenGLShader::Bind() const {
        glUseProgram(m_ShaderID);
    }

    void OpenGLShader::Unbind() const {
        glUseProgram(0);
    }


    void OpenGLShader::SetUniform1f(const char* uniformName, float v0) const {
        glUniform1f(GetUniformLocation(uniformName), v0);
    }

    void OpenGLShader::SetUniform1f(const char* uniformName, const glm::tvec1<float>& vec) const {
        glUniform1f(GetUniformLocation(uniformName), vec.x);
    }

    void OpenGLShader::SetUniform2f(const char* uniformName, float v0, float v1) const {
        glUniform2f(GetUniformLocation(uniformName), v0, v1);
    }

    void OpenGLShader::SetUniform2f(const char* uniformName, const glm::tvec2<float>& vec) const {
        glUniform2f(GetUniformLocation(uniformName), vec.x, vec.y);
    }

    void OpenGLShader::SetUniform3f(const char* uniformName, float v0, float v1, float v2) const {
        glUniform3f(GetUniformLocation(uniformName), v0, v1, v2);
    }

    void OpenGLShader::SetUniform3f(const char* uniformName, const glm::tvec3<float>& vec) const {
        glUniform3f(GetUniformLocation(uniformName), vec.x, vec.y, vec.z);
    }

    void OpenGLShader::SetUniform4f(const char* uniformName, float v0, float v1, float v2, float v3) const {
        glUniform4f(GetUniformLocation(uniformName), v0, v1, v2, v3);
    }

    void OpenGLShader::SetUniform4f(const char* uniformName, const glm::vec4& vec) const {
        glUniform4f(GetUniformLocation(uniformName), vec.x, vec.y, vec.z, vec.w);
    }

    void OpenGLShader::SetUniform1i(const char* uniformName, int v0) const {
        glUniform1i(GetUniformLocation(uniformName), v0);
    }

    void OpenGLShader::SetUniform1i(const char* uniformName, const glm::tvec1<int>& vec) const {
        glUniform1i(GetUniformLocation(uniformName), vec.x);
    }

    void OpenGLShader::SetUniform2i(const char* uniformName, int v0, int v1) const {
        glUniform2i(GetUniformLocation(uniformName), v0,v1);
    }

    void OpenGLShader::SetUniform2i(const char* uniformName, const glm::tvec2<int>& vec) const {
        glUniform2i(GetUniformLocation(uniformName), vec.x, vec.y);
    }

    void OpenGLShader::SetUniform3i(const char* uniformName, int v0, int v1, int v2) const {
        glUniform3i(GetUniformLocation(uniformName), v0, v1, v2);
    }

    void OpenGLShader::SetUniform3i(const char* uniformName, const glm::tvec3<int>& vec) const {
        glUniform3i(GetUniformLocation(uniformName), vec.x, vec.y, vec.z);
    }

    void OpenGLShader::SetUniform4i(const char* uniformName, int v0, int v1, int v2, int v3) const {
        glUniform4i(GetUniformLocation(uniformName), v0, v1, v2, v3);
    }

    void OpenGLShader::SetUniform4i(const char* uniformName, const glm::tvec4<int>& vec) const {
        glUniform4i(GetUniformLocation(uniformName), vec.x, vec.y, vec.z, vec.w);
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
        auto iter = m_UniformLocationCache.find(uniformName);

        if(iter != m_UniformLocationCache.end()) {
            return iter->second;
        }

        int location = glGetUniformLocation(m_ShaderID, uniformName);
        m_UniformLocationCache[uniformName] = location;

        return location;
    }

} // END OF NAMESPACE Bald::Graphics