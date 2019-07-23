//
// Created by blinku on 28.05.19.
//

#pragma once

#include "unordered_map"
#include "string"

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
        virtual void Bind() const = 0;

        /**
         * @fn Unbind
         * @brief Unbinds (Disables) shader.
         */
        virtual void Unbind() const = 0;

        /**
         * @fn SetUniform4f
         * @brief Sets uniform of type vec4 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         * @param v1 -> Value.
         * @param v2 -> Value.
         * @param v3 -> Value.
         */
        virtual void SetUniform4f(const char* uniformName, float v0, float v1, float v2, float v3) const = 0;

        /**
         * @fn GetShaderID
         * @brief Returns shader's ID.
         * @return [unsigned] Shader ID.
         */
        virtual unsigned GetShaderID() const = 0;

    }; // END OF CLASS Shader

} // END OF NAMESPACE Bald::Graphics
