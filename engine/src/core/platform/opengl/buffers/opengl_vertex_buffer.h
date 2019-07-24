//
// Created by blinku on 08.05.19.
//

#pragma once

#include <vector>

#include "graphics/rendering/buffers/vertex_buffer_layout.h"
#include "graphics/rendering/buffers/vertex_buffer.h"

namespace Bald::Platform::Graphics {



    /**
     * @class OpenGLBuffer
     * @brief Simple OpenGL buffer implementation.
     */

    class OpenGLVertexBuffer : public Bald::Graphics::VertexBuffer {
    public:

        /**
         * @fn OpenGLVertexBuffer
         * @brief Creates an opengl vertex buffer object and initializes it's data.
         * @param [float*] data -> Pointer to the memory containing data (eg. triangle vertices)
         * @param [unsigned] size -> Size of data array in bytes.
         */

        OpenGLVertexBuffer(float* data, unsigned count) noexcept;

        /**
         * @fn ~OpenGLBuffer
         * @brief Destructor of OpenGLBuffer.
         */

        ~OpenGLVertexBuffer() override;

        /**
         * @fn SetLayout
         * @brief Sets vertex buffer layout.
         */

        void SetLayout(const Bald::Graphics::VertexBufferLayout& layout) noexcept override;

        /**
         * @fn GetLayout
         * @brief Vertex buffer layout getter
         * @return [Bald::Graphics::VertexBufferLayout&] Vertex buffer layout.
         */

        [[nodiscard]] inline const Bald::Graphics::VertexBufferLayout& GetLayout() const noexcept override { return m_Layout; }

        /**
         * @fn Bind
         * @brief Binds a buffer object.
         */

        void Bind() const noexcept override;

        /**
         * @fn Bind
         * @brief Unbinds a buffer object.
         */

        void Unbind() const noexcept override;

        /**
         * @fn GetID
         * @brief ID getter.
         * @return [unsigned] Buffer id.
         */

        [[nodiscard]] inline unsigned GetID() const noexcept override { return m_BufferID; };

    private:
        unsigned m_BufferID;
        Bald::Graphics::VertexBufferLayout m_Layout;
    }; // END OF CLASS OpenGLVertexBuffer

} // END OF NAMESPACE Bald::Platform::Graphics
