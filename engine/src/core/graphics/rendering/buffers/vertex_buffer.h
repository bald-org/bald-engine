//
// Created by blinku on 08.05.19.
//

#pragma once

#include <vector>

namespace Bald::Graphics {

    class VertexBufferLayout;

    /**
     * @class Buffer
     * @brief Simple buffer abstraction.
     */

    class VertexBuffer {
    public:

        /**
         * @fn Create
         * @brief Creates vertex buffer based on currently chosen rendering API.
         * @param [float*] data -> Pointer to the memory containing data (eg. triangle vertices)
         * @param [unsigned] size -> Size of data array in bytes.
         * @return [VertexBuffer*] Pointer to the vertex buffer object.
         */

        static VertexBuffer* Create(float* data, unsigned size);

        /**
         * @fn ~VertexBuffer
         * @brief Default virtual destructor.
         */

        virtual ~VertexBuffer() = default;

        /**
         * @fn SetLayout
         * @brief Sets vertex buffer layout.
         * @param [const Bald::Graphics::VertexBufferLayout&] Vertex buffer layout object.
         */

        virtual void SetLayout(const Bald::Graphics::VertexBufferLayout& layout) noexcept = 0;

        /**
         * @fn GetLayout
         * @brief Vertex buffer layout getter
         * @return [Bald::Graphics::VertexBufferLayout&] Vertex buffer layout.
         */

        virtual const Bald::Graphics::VertexBufferLayout& GetLayout() const noexcept = 0;

        /**
         * @fn Bind
         * @brief Binds the buffer.
         */

        virtual void Bind() const noexcept = 0;

        /**
         * @fn Unbind
         * @brief Unbinds the buffer.
         */

        virtual void Unbind() const noexcept = 0;

        /**
         * @fn GetID
         * @brief ID getter.
         * @return [unsigned] VertexBuffer id.
         */

        [[nodiscard]] virtual unsigned GetID() const noexcept = 0;

    }; // END OF CLASS VertexBuffer

} // END OF NAMESPACE Bald::Graphics
