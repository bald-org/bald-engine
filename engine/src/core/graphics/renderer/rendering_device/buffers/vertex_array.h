//
// Created by blinku on 08.05.19.
//

#pragma once

#include <memory>

namespace Bald::Graphics {

    class Buffer;

    /**
     * @class VertexArray
     * @brief Simple vertex array abstraction.
     */

    class VertexArray {
    public:

        /**
         * @fn VertexArray
         * @brief Creates Vertex Array Object.
         * @return [VertexArray*] Pointer to the vertex array object.
         */

        static VertexArray* Create() noexcept;

        /**
         * @fn ~VertexArray
         * @brief Default virtual destructor.
         */

        virtual ~VertexArray() = default;

        /**
         * @fn AddBuffer
         * @brief Adds buffer to vertex array.
         * @param [Buffer*] buffer -> Pointer to dynamically created buffer.
         * @param [unsinged] index -> Specifies the index of the generic vertex attribute to be enabled.
         */

        virtual void AddBuffer(Buffer* buffer, unsigned index) noexcept = 0;

        /**
         * @fn Bind
         * @brief Binds the vertex array object.
         */

        virtual void Bind() noexcept = 0;

        /**
         * @fn Unbind
         * @brief Unbind the vertex array object.
         */

        virtual void Unbind() noexcept = 0;
    }; // END OF CLASS VertexArray

} // END OF NAMESPACE Bald::Graphics
