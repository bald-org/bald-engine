//
// Created by blinku on 28.05.19.
//

#pragma once

#include "unordered_map"
#include "string"

namespace Bald::Graphics {

    /**
     * @class Shader
     * @brief Implementation of simple Shader class
     */

    class Shader {
    public:
        /**
         * @fn      Shader
         * @brief   default constructor deleted
         */
        Shader() = delete;

        /**
         * @fn      Shader
         * @brief   Constructs a shader object based on Vertex Shader and Fragment Shader
         * @param   vertexPath    Path to vertex shader
         * @param   fragmentPath  Path to fragment shader
         */
        explicit Shader(const char* vertexPath, const char* fragmentPath);

        /**
         * @fn      ~Shader
         * @brief   Destructs (deletes) shader program
         */
        ~Shader();

        /**
         * @fn      Bind
         * @brief   Binds (enables) shader.
         */
        void Bind() const;

        /**
         * @fn      Unbind
         * @brief   Uninds (Disables) shader.
         */
        void Unbind() const;

        /**
         * @fn      SetUniform4f
         * @brief   Sets uniform of type vec4 with name uniformName with given values
         * @param   uniformName     Name of uniform we want to set
         * @param   v0              Value
         * @param   v1              Value
         * @param   v2              Value
         * @param   v3              Value
         */
        void SetUniform4f(const char* uniformName, float v0, float v1, float v2, float v3) const;

        /**
         * @fn      GetShaderID
         * @brief   Returns shader's ID
         * @return  unsigned int
         */
        unsigned int GetShaderID() const;

    private:
        /**
         * @fn      CreateShader
         * @brief   Creates and compiles both Vertex and Fragment Shaders, then returns Shader Program
         * @return  unsigned int
         */
        unsigned int CreateShader() const;

        /**
         * @fn      GetUniformLocation
         * @brief   Used to retrieve Uniforms Locations. Uses unordered map (hash table) for improved performance
         * @return  int
         */
        [[nodiscard]] int GetUniformLocation(const char* uniformName) const;

    private:
        unsigned int m_ShaderID; /**< Shader ID */
        const char* m_VertexPath; /**< Relative path to Vertex Shader */
        const char* m_FragmentPath; /**< Relative path to Fragment Shader */
        mutable std::unordered_map<std::string, int> m_UniformLocationCache; /**< Unordered map of Uniform Locations for better performance*/

    }; // END OF CLASS Shader

} // END OF NAMESPACE Bald::Graphics
