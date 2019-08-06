//
// Created by blinku on 22.07.19.
//

#pragma once

#include <vector>
#include "graphics/rendering/buffers/vertex_array.h"
#include "graphics/rendering/buffers/vertex_buffer.h"
#include "graphics/rendering/buffers/index_buffer.h"

namespace Bald::Platform::Graphics {

    /**
     * @class OpenGLVertexArray
     * @brief Simple OpenGL vertex array implementation.
     */

    class OpenGLVertexArray : public Bald::Graphics::VertexArray {
    friend class Bald::Graphics::VertexArray;
    private:

        /**
         * @fn OpenGLVertexArray
         * @brief Create OpenGL vertex array Object.
         */

        OpenGLVertexArray() noexcept;

    public:
        /**
         * @fn ~OpenGLVertexArray
         * @brief OpenGLVertexArray destructor.
         */

        ~OpenGLVertexArray() override;

        /**
         * @fn AddVertexBuffer
         * @brief Adds vertex buffer to vertex array.
         * @param [Bald::Graphics::VertexBuffer*] vertexBuffer -> Pointer to dynamically created vertex buffer.
         */

        void AddVertexBuffer(const std::shared_ptr<Bald::Graphics::VertexBuffer>& vertexBuffer) noexcept override;

        /**
         * @fn AddIndexBuffer
         * @brief Adds index buffer to vertex array.
         * @param [const std::shared_ptr<Bald::Graphics::IndexBuffer>&] indexBuffer -> Pointer to dynamically created index buffer.
         * @param [unsinged] index -> Specifies the index of the generic vertex attribute to be enabled.
         */

        void AddIndexBuffer(const std::shared_ptr<Bald::Graphics::IndexBuffer>& indexBuffer) noexcept override;

        /**
         * @fn GetIndexBuffer
         * @brief Index buffer getter.
         * @return [std::shared_ptr<Bald::Graphics::IndexBuffer>] Index buffer currently connected with this vertex array object.
         */

        [[nodiscard]] std::shared_ptr<Bald::Graphics::IndexBuffer> GetIndexBuffer() noexcept override;

        /**
         * @fn Bind
         * @brief Binds a vertex array object.
         */

        void Bind() const noexcept override;

        /**
         * @fn Unbind
         * @brief Unbind a vertex array object.
         */

        void Unbind() const noexcept override;

        /**
         * @fn GetID
         * @brief ID getter.
         * @return [int] Vertex array id.
         */

        [[nodiscard]] inline unsigned GetID() const noexcept override { return m_ArrayID; };

    private:
        unsigned m_ArrayID; /**< identifier of Vertex Array object >*/
        std::vector<std::shared_ptr<Bald::Graphics::VertexBuffer>> m_VertexBuffers; /**< pointers to vertex buffers added to Vertex Array >*/
        std::shared_ptr<Bald::Graphics::IndexBuffer> m_IndexBuffer; /**< pointer to index buffers added to Vertex Array >*/
    }; // END OF CLASS OpenGLVertexArray

} // END OF NAMESPACE Bald::Platform::Graphics
