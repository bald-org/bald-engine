//
// Created by blinku on 08.05.19.
//

#pragma once

#include <vector>
#include <memory>
#include "vertex_buffer_layout.h"

namespace Bald::Graphics {

    /**
     * @class Buffer
     * @brief Simple buffer abstraction.
     */

    class VertexBuffer {
    public:

        /**
         * @fn Create
         * @brief Creates vertex buffer based on currently chosen rendering API.
         * @param float* Pointer to the memory containing data (eg. triangle vertices)
         * @param unsigned Size of data array in bytes.
         * @return VertexBuffer* Pointer to the vertex buffer object.
         */

        static std::shared_ptr<VertexBuffer> Create(float* data, unsigned size);

        /**
         * @fn VertexBuffer
         * @brief Default constructor.
         */

        VertexBuffer() = default;

        /**
         * @fn VertexBuffer
         * @brief Deleted copy constructor.
         * @param const VertexBuffer&
         */

        VertexBuffer(const VertexBuffer&) = delete;

        /**
         * @fn operator=
         * @brief Deleted operator=.
         * @param const VertexBuffer&
         * @return VertexBuffer&
         */

        VertexBuffer& operator=(const VertexBuffer&) = delete;

        /**
         * @fn ~VertexBuffer
         * @brief Default virtual destructor.
         */

        virtual ~VertexBuffer() = default;

        /**
         * @fn SetLayout
         * @brief Sets vertex buffer layout.
         * @param const Bald::Graphics::VertexBufferLayout& Vertex buffer layout object.
         */

        void SetLayout(const VertexBufferLayout& layout) noexcept;

        /**
         * @fn GetLayout
         * @brief Vertex buffer layout getter
         * @return Bald::Graphics::VertexBufferLayout& Vertex buffer layout.
         */

        [[nodiscard]] inline const VertexBufferLayout& GetLayout() const noexcept { return m_Layout; }

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
         * @return unsigned VertexBuffer id.
         */

        [[nodiscard]] virtual unsigned GetID() const noexcept = 0;

    private:

        VertexBufferLayout m_Layout; /**< Buffer layout, it is uninitialized by default => You MUST set it via setter! */

    }; // END OF CLASS VertexBuffer

} // END OF NAMESPACE Bald::Graphics
