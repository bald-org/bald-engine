//
// Created by blinku on 28.05.19.
//

#pragma once

#include "src/core/graphics/rendering/shaders/shader.h"

#include <unordered_map>
#include <string>

namespace Bald::Platform::Graphics {

    /**
     * @class OpenGLShader
     * @brief Simple OpenGL shader implementation.
     */

    class OpenGLShader : public Bald::Graphics::Shader {
    public:
        /**
         * @fn OpenGLShader
         * @brief Default constructor deleted.
         */
        OpenGLShader() = delete;

        /**
         * @fn OpenGLShader
         * @brief Constructs a shader object based on Vertex Shader and Fragment Shader.
         * @param vertexPath -> Path to vertex shader.
         * @param fragmentPath -> Path to fragment shader.
         */
        explicit OpenGLShader(const char* vertexPath, const char* fragmentPath);

        /**
         * @fn ~Shader
         * @brief Destructs (deletes) shader program.
         */
        ~OpenGLShader() override;

        /**
         * @fn Bind
         * @brief Binds (enables) shader.
         */
        void Bind() const noexcept override;

        /**
         * @fn Unbind
         * @brief Unbinds (Disables) shader.
         */
        void Unbind() const noexcept override;

        /**
         * @fn SetUniform1f
         * @brief Sets uniform of type vec1 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         */
        void SetUniform1f(const char* uniformName, float v0) const noexcept override;

        /**
         * @fn SetUniform1f
         * @brief Sets uniform of type vec1 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param [glm::tvec1<float>] vec -> Vector of values.
         */
        void SetUniform1f(const char* uniformName, const glm::tvec1<float>& vec) const noexcept override;

        /**
         * @fn SetUniform2f
         * @brief Sets uniform of type vec2 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         * @param v0 -> Value.
         */
        void SetUniform2f(const char* uniformName, float v0, float v1) const noexcept override;

        /**
         * @fn SetUniform2f
         * @brief Sets uniform of type vec2 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param [glm::tvec2<float>] vec -> Vector of values.
         */
        void SetUniform2f(const char* uniformName, const glm::tvec2<float>& vec) const noexcept override;

        /**
         * @fn SetUniform3f
         * @brief Sets uniform of type vec3 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         * @param v1 -> Value.
         * @param v2 -> Value.
         */
        void SetUniform3f(const char* uniformName, float v0, float v1, float v2) const noexcept override;

        /**
         * @fn SetUniform3f
         * @brief Sets uniform of type vec3 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param [glm::tvec3<float>] vec -> Vector of values.
         */
        void SetUniform3f(const char* uniformName, const glm::tvec3<float>& vec) const noexcept override;

        /**
         * @fn SetUniform4f
         * @brief Sets uniform of type vec4 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         * @param v1 -> Value.
         * @param v2 -> Value.
         * @param v3 -> Value.
         */
        void SetUniform4f(const char* uniformName, float v0, float v1, float v2, float v3) const noexcept override;

        /**
         * @fn SetUniform4f
         * @brief Sets uniform of type vec4 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param [glm::tvec4<float>] vec4 -> Vector of values.
         */
        void SetUniform4f(const char* uniformName, const glm::tvec4<float>& vec) const noexcept override;

        /**
         * @fn SetUniform1i
         * @brief Sets uniform of type vec1 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         */
        void SetUniform1i(const char* uniformName, int v0) const noexcept override;

        /**
         * @fn SetUniform1i
         * @brief Sets uniform of type vec4 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param [glm::tvec4<int>] vec1 -> Vector of values.
         */
        void SetUniform1i(const char* uniformName, const glm::tvec1<int>& vec) const noexcept override;

        /**
         * @fn SetUniform2i
         * @brief Sets uniform of type vec2 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         * @param v1 -> Value.
         */
        void SetUniform2i(const char* uniformName, int v0, int v1) const noexcept override;

        /**
         * @fn SetUniform2i
         * @brief Sets uniform of type vec2 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param [glm::tvec4<int>] vec2 -> Vector of values.
         */
        void SetUniform2i(const char* uniformName, const glm::tvec2<int>& vec) const noexcept override;

        /**
         * @fn SetUniform3i
         * @brief Sets uniform of type vec3 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         * @param v1 -> Value.
         * @param v2 -> Value.
         */
        void SetUniform3i(const char* uniformName, int v0, int v1, int v2) const noexcept override;

        /**
         * @fn SetUniform3i
         * @brief Sets uniform of type vec3 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param [glm::tvec4<int>] vec3 -> Vector of values.
         */
        void SetUniform3i(const char* uniformName, const glm::tvec3<int>& vec) const noexcept override;

        /**
         * @fn SetUniform4i
         * @brief Sets uniform of type vec4 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         * @param v1 -> Value.
         * @param v2 -> Value.
         * @param v3 -> Value.
         */
        void SetUniform4i(const char* uniformName, int v0, int v1, int v2, int v3) const noexcept override;

        /**
         * @fn SetUniform4i
         * @brief Sets uniform of type vec4 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param [glm::tvec4<int>] vec4 -> Vector of values.
         */
        void SetUniform4i(const char* uniformName, const glm::tvec4<int>& vec) const noexcept override;

        /**
        * @fn SetUniform1iv
        * @brief Sets uniform of type vec1* with name uniformName with given values.
        * @param const char* Name of uniform we want to set.
        * @param std::size_t* Number of elements
        * @param int Value.
        */
        void SetUniform1iv(const char* uniformName, std::size_t count, int* value) const noexcept override;

        /**
        * @fn SetUniformMatrix4fv
        * @brief Sets uniform of type mat4 with name uniformName with given values.
        * @param const char* Name of uniform we want to set.
        * @param const glm::mat4& Matrix.
        */
        void SetUniformMatrix4fv(const char* uniformName, const glm::mat4& mat) const noexcept override;

        /**
         * @fn GetID
         * @brief Returns shader's ID.
         * @return [unsigned] Shader ID.
         */
        unsigned GetID() const noexcept override;

    private:
        /**
         * @fn CreateShader
         * @brief Creates and compiles both Vertex and Fragment Shaders, then returns Shader Program.
         * @return [unsigned int] Shader program ID.
         */
        unsigned CreateShader() const noexcept;

        /**
         * @fn GetUniformLocation
         * @brief Used to retrieve Uniforms Locations. Uses unordered map (hash table) for improved performance.
         * @return [int] Uniform location.
         */
        [[nodiscard]] int GetUniformLocation(const char* uniformName) const noexcept;

    private:
        const char* m_VertexPath; /**< Relative path to Vertex Shader */
        const char* m_FragmentPath; /**< Relative path to Fragment Shader */
        unsigned int m_ShaderID; /**< Shader ID */
        mutable std::unordered_map<std::string, int> m_UniformLocationCache; /**< Unordered map of Uniform Locations for better performance*/

    }; // END OF CLASS OpenGLShader

} // END OF NAMESPACE Bald::Platform::Graphics
