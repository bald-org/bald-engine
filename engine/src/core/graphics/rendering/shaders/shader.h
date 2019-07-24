//
// Created by blinku on 28.05.19.
//

#pragma once

#include "glm/glm.hpp"

namespace Bald::Graphics {

    /**
     * @class Shader
     * @brief Simple OpenGL shader implementation.
     */

    class Shader {

    public:

        /**
         * @fn Shader
         * @brief Constructs a shader object based on Vertex Shader and Fragment Shader.
         * @param vertexPath -> Path to vertex shader.
         * @param fragmentPath -> Path to fragment shader.
         */
        static Shader* Create(const char* vertexPath, const char* fragmentPath);

        /**
         * @fn ~Shader
         * @brief Destructs (deletes) shader program.
         */
        virtual ~Shader() = default;

        /**
         * @fn Bind
         * @brief Binds (enables) shader.
         */
        virtual void Bind() const noexcept = 0;

        /**
         * @fn Unbind
         * @brief Unbinds (Disables) shader.
         */
        virtual void Unbind() const noexcept = 0;

        /**
         * @fn SetUniform1f
         * @brief Sets uniform of type vec1 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         */
        virtual void SetUniform1f(const char* uniformName, float v0) const noexcept = 0;

        /**
         * @fn SetUniform1f
         * @brief Sets uniform of type vec1 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param [glm::tvec1<float>] vec -> Vector of values.
         */
        virtual void SetUniform1f(const char* uniformName, const glm::tvec1<float>& vec) const noexcept = 0;

        /**
         * @fn SetUniform2f
         * @brief Sets uniform of type vec2 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         * @param v0 -> Value.
         */
        virtual void SetUniform2f(const char* uniformName, float v0, float v1) const noexcept = 0;

        /**
         * @fn SetUniform2f
         * @brief Sets uniform of type vec2 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param [glm::tvec2<float>] vec -> Vector of values.
         */
        virtual void SetUniform2f(const char* uniformName, const glm::tvec2<float>& vec) const noexcept = 0;

        /**
         * @fn SetUniform3f
         * @brief Sets uniform of type vec3 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         * @param v1 -> Value.
         * @param v2 -> Value.
         */
        virtual void SetUniform3f(const char* uniformName, float v0, float v1, float v2) const noexcept = 0;

        /**
         * @fn SetUniform3f
         * @brief Sets uniform of type vec3 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param [glm::tvec3<float>] vec -> Vector of values.
         */
        virtual void SetUniform3f(const char* uniformName, const glm::tvec3<float>& vec) const noexcept = 0;

        /**
         * @fn SetUniform4f
         * @brief Sets uniform of type vec4 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         * @param v1 -> Value.
         * @param v2 -> Value.
         * @param v3 -> Value.
         */
        virtual void SetUniform4f(const char* uniformName, float v0, float v1, float v2, float v3) const noexcept = 0;

        /**
         * @fn SetUniform4f
         * @brief Sets uniform of type vec4 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param [glm::tvec4<float>] vec4 -> Vector of values.
         */
        virtual void SetUniform4f(const char* uniformName, const glm::tvec4<float>& vec) const noexcept = 0;

        /**
         * @fn SetUniform1i
         * @brief Sets uniform of type vec1 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         */
        virtual void SetUniform1i(const char* uniformName, int v0) const noexcept = 0;

        /**
         * @fn SetUniform1i
         * @brief Sets uniform of type vec4 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param [glm::tvec4<int>] vec1 -> Vector of values.
         */
        virtual void SetUniform1i(const char* uniformName, const glm::tvec1<int>& vec) const noexcept = 0;

        /**
         * @fn SetUniform2i
         * @brief Sets uniform of type vec2 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         * @param v1 -> Value.
         */
        virtual void SetUniform2i(const char* uniformName, int v0, int v1) const noexcept = 0;

        /**
         * @fn SetUniform2i
         * @brief Sets uniform of type vec2 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param [glm::tvec4<int>] vec2 -> Vector of values.
         */
        virtual void SetUniform2i(const char* uniformName, const glm::tvec2<int>& vec) const noexcept = 0;

        /**
         * @fn SetUniform3i
         * @brief Sets uniform of type vec3 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         * @param v1 -> Value.
         * @param v2 -> Value.
         */
        virtual void SetUniform3i(const char* uniformName, int v0, int v1, int v2) const noexcept = 0;

        /**
         * @fn SetUniform3i
         * @brief Sets uniform of type vec3 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param [glm::tvec4<int>] vec3 -> Vector of values.
         */
        virtual void SetUniform3i(const char* uniformName, const glm::tvec3<int>& vec) const noexcept = 0;

        /**
         * @fn SetUniform4i
         * @brief Sets uniform of type vec4 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         * @param v1 -> Value.
         * @param v2 -> Value.
         * @param v3 -> Value.
         */
        virtual void SetUniform4i(const char* uniformName, int v0, int v1, int v2, int v3) const noexcept = 0;

        /**
         * @fn SetUniform4i
         * @brief Sets uniform of type vec4 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param [glm::tvec4<int>] vec4 -> Vector of values.
         */
        virtual void SetUniform4i(const char* uniformName, const glm::tvec4<int>& vec) const noexcept = 0;

        /**
         * @fn GetID
         * @brief Returns shader's ID.
         * @return [unsigned] Shader ID.
         */
        virtual unsigned GetID() const noexcept = 0;

    }; // END OF CLASS Shader

} // END OF NAMESPACE Bald::Graphics
