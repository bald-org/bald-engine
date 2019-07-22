//
// Created by blinku on 08.05.19.
//

#pragma once

#include <memory>

namespace Bald::Graphics {

    class Buffer;

    class VertexArray {
    public:

        /**
         * @fn    VertexArray
         * @brief Create Vertex Array Object
         */

        static VertexArray* Create() noexcept;

        /**
         * @fn    ~VertexArray
         * @brief VertexArray destructor
         */

        virtual ~VertexArray() = default;

        /**
         * @fn                              AddBuffer
         * @brief                           Adds buffer to vertex array
         * @param [Buffer*]                 buffer -> Pointer to dynamically created buffer
         * @param [GLuint aka unsinged int] index -> Specifies the index of the generic vertex attribute to be enabled
         */

        virtual void AddBuffer(Buffer* buffer, unsigned index) noexcept = 0;

        /**
         * @fn    Bind
         * @brief binds a vertex array object
         */

        virtual void Bind() noexcept = 0;

        /**
         * @fn    Unbind
         * @brief unbind a vertex array object
         */

        virtual void Unbind() noexcept = 0;
    }; // END OF CLASS VertexArray

} // END OF NAMESPACE Bald::Graphics
