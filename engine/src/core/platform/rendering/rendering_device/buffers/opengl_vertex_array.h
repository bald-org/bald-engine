//
// Created by blinku on 22.07.19.
//

#pragma once

#include <vector>
#include "graphics/renderer/rendering_device/vertex_array.h"

namespace Bald::Platform::Graphics {

    class Buffer;

    class OpenGLOpenGLVertexArray : public Bald::Graphics::VertexArray {
    public:

        /**
         * @fn    OpenGLVertexArray
         * @brief Create Vertex Array Object
         */

        OpenGLVertexArray() noexcept;

        /**
         * @fn    ~OpenGLVertexArray
         * @brief OpenGLVertexArray destructor
         */

        ~OpenGLVertexArray();

        /**
         * @fn                              AddBuffer
         * @brief                           Adds buffer to vertex array
         * @param [Buffer*]                 buffer -> Pointer to dynamically created buffer
         * @param [GLuint aka unsinged int] index -> Specifies the index of the generic vertex attribute to be enabled
         */

        void AddBuffer(Buffer* buffer, unsigned index) noexcept;

        /**
         * @fn    Bind
         * @brief binds a vertex array object
         */

        void Bind() noexcept;

        /**
         * @fn    Unbind
         * @brief unbind a vertex array object
         */

        void Unbind() noexcept;

    private:
        unsigned m_ArrayID;             /**< identifier of Vertex Array object >*/
        std::vector<Buffer*> m_Buffers; /**< pointers to buffers added to Vertex Array >*/
    }; // END OF CLASS OpenGLVertexArray

} // END OF NAMESPACE Bald::Platform::Graphics
