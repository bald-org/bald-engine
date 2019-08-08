//
// Created by blinku on 08.05.19.
//

#pragma once

#include <memory>

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
         * @return VertexArray* Pointer to the vertex array object.
         */

        static std::shared_ptr<VertexArray> Create();

        /**
         * @fn VertexArray
         * @brief Default constructor.
         */

        VertexArray() = default;

        /**
         * @fn VertexArray
         * @brief Deleted copy constructor.
         * @param const VertexArray&
         */

        VertexArray(const VertexArray&) = delete;

        /**
         * @fn operator=
         * @brief Deleted operator=.
         * @param const VertexArray&
         * @return VertexArray&
         */

        VertexArray& operator=(const VertexArray&) = delete;

        /**
         * @fn ~VertexArray
         * @brief Default virtual destructor.
         */

        virtual ~VertexArray() = default;

        /**
         * @fn AddVertexBuffer
         * @brief Adds vertex buffer to vertex array.
         * @param const std::shared_ptr<Bald::Graphics::VertexBuffer>& Pointer to dynamically created vertex buffer.
         */

        virtual void AddVertexBuffer(const std::shared_ptr<Bald::Graphics::VertexBuffer>& vertexBuffer) noexcept = 0;

        /**
         * @fn AddIndexBuffer
         * @brief Adds index buffer to vertex array.
         * @param const std::shared_ptr<Bald::Graphics::IndexBuffer>& Pointer to dynamically created index buffer.
         */

        virtual void AddIndexBuffer(const std::shared_ptr<Bald::Graphics::IndexBuffer>& indexBuffer) noexcept = 0;

        /**
         * @fn GetIndexBuffer
         * @brief Index buffer getter.
         * @return std::shared_ptr<Bald::Graphics::IndexBuffer> Index buffer currently connected with this vertex array object.
         */

        [[nodiscard]] virtual std::shared_ptr<Bald::Graphics::IndexBuffer> GetIndexBuffer() noexcept = 0;

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
