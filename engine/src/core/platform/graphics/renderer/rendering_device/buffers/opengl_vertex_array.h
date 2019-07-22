//
// Created by blinku on 22.07.19.
//

#pragma once

#include <vector>
#include "graphics/renderer/rendering_device/buffers/vertex_array.h"
#include "graphics/renderer/rendering_device/buffers/buffer.h"

namespace Bald::Platform::Graphics {

    /**
     * @class OpenGLVertexArray
     * @brief Simple OpenGL vertex array implementation.
     */

    class OpenGLVertexArray : public Bald::Graphics::VertexArray {
    public:

        /**
         * @fn OpenGLVertexArray
         * @brief Create OpenGL vertex array Object.
         */

        OpenGLVertexArray() noexcept;

        /**
         * @fn ~OpenGLVertexArray
         * @brief OpenGLVertexArray destructor.
         */

        ~OpenGLVertexArray() override;

        /**
         * @fn AddBuffer
         * @brief Adds buffer to vertex array.
         * @param [Buffer*] buffer -> Pointer to dynamically created buffer.
         * @param [GLuint aka unsinged int] index -> Specifies the index of the generic vertex attribute to be enabled.
         */

        void AddBuffer(Bald::Graphics::Buffer* buffer, unsigned index) noexcept override;

        /**
         * @fn Bind
         * @brief Binds a vertex array object.
         */

        void Bind() noexcept override;

        /**
         * @fn Unbind
         * @brief Unbind a vertex array object.
         */

        void Unbind() noexcept override;

    private:
        unsigned m_ArrayID; /**< identifier of Vertex Array object >*/
        std::vector<Bald::Graphics::Buffer*> m_Buffers; /**< pointers to buffers added to Vertex Array >*/
    }; // END OF CLASS OpenGLVertexArray

} // END OF NAMESPACE Bald::Platform::Graphics
