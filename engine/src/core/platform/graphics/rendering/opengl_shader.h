//
// Created by blinku on 28.05.19.
//

#pragma once

#include "graphics/rendering/shader.h"
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
        void Bind() const override;

        /**
         * @fn Unbind
         * @brief Unbinds (Disables) shader.
         */
        void Unbind() const override;

        /**
         * @fn SetUniform4f
         * @brief Sets uniform of type vec4 with name uniformName with given values.
         * @param uniformName -> Name of uniform we want to set.
         * @param v0 -> Value.
         * @param v1 -> Value.
         * @param v2 -> Value.
         * @param v3 -> Value.
         */
        void SetUniform4f(const char* uniformName, float v0, float v1, float v2, float v3) const override;

        /**
         * @fn GetShaderID
         * @brief Returns shader's ID.
         * @return [unsigned] Shader ID.
         */
        unsigned GetShaderID() const override;

    private:
        /**
         * @fn CreateShader
         * @brief Creates and compiles both Vertex and Fragment Shaders, then returns Shader Program.
         * @return [unsigned int] Shader program ID.
         */
        unsigned CreateShader() const;

        /**
         * @fn GetUniformLocation
         * @brief Used to retrieve Uniforms Locations. Uses unordered map (hash table) for improved performance.
         * @return [int] Uniform location.
         */
        [[nodiscard]] int GetUniformLocation(const char* uniformName) const;

    private:
        unsigned int m_ShaderID; /**< Shader ID */
        const char* m_VertexPath; /**< Relative path to Vertex Shader */
        const char* m_FragmentPath; /**< Relative path to Fragment Shader */
        mutable std::unordered_map<std::string, int> m_UniformLocationCache; /**< Unordered map of Uniform Locations for better performance*/

    }; // END OF CLASS OpenGLShader

} // END OF NAMESPACE Bald::Platform::Graphics
