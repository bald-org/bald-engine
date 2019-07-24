//
// Created by blinku on 08.05.19.
//

#pragma once

namespace Bald::Graphics {

    class VertexBuffer;
    class IndexBuffer;

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

        static VertexArray* Create();

        /**
         * @fn ~VertexArray
         * @brief Default virtual destructor.
         */

        virtual ~VertexArray() = default;

        /**
         * @fn AddVertexBuffer
         * @brief Adds vertex buffer to vertex array.
         * @param [Bald::Graphics::VertexBuffer*] vertexBuffer -> Pointer to dynamically created vertex buffer.
         */

        virtual void AddVertexBuffer(Bald::Graphics::VertexBuffer* vertexBuffer) noexcept = 0;

        /**
         * @fn AddIndexBuffer
         * @brief Adds index buffer to vertex array.
         * @param [IndexBuffer*] indexBuffer -> Pointer to dynamically created index buffer.
         * @param [unsinged] index -> Specifies the index of the generic vertex attribute to be enabled.
         */

        virtual void AddIndexBuffer(Bald::Graphics::IndexBuffer* indexBuffer) noexcept = 0;

        /**
         * @fn Bind
         * @brief Binds the vertex array object.
         */

        virtual void Bind() const noexcept = 0;

        /**
         * @fn Unbind
         * @brief Unbind the vertex array object.
         */

        virtual void Unbind() const noexcept = 0;

        /**
         * @fn GetID
         * @brief ID getter.
         * @return [unsigned] Vertex array id.
         */

        [[nodiscard]] virtual unsigned GetID() const noexcept = 0;

    }; // END OF CLASS VertexArray

} // END OF NAMESPACE Bald::Graphics
