//
// Created by blinku on 22.07.19.
//

#pragma once

#include <graphics/rendering/buffers/index_buffer.h>

namespace Bald::Platform::Graphics {

    /**
     * @class OpenGLIndexBuffer
     * @brief Simple OpenGL index buffer implementation.
     */

    class OpenGLIndexBuffer : public Bald::Graphics::IndexBuffer {
    friend class ::Bald::Graphics::IndexBuffer;
    private:

        /**
         * @fn OpenGLIndexBuffer
         * @brief creates a index buffer object and initializes its data.
        * @param [unsigned*] data -> Pointer to the memory containing data (eg. triangle indices)
        * @param [unsigned] size -> Size of data array in bytes.
         */

        OpenGLIndexBuffer(unsigned* data, unsigned size) noexcept;

    public:
        /**
         * @fn ~OpenGLIndexBuffer
         * @brief Destructor of OpenGLIndexBuffer.
         */

        ~OpenGLIndexBuffer() override;

        /**
         * @fn Bind
         * @brief Binds a index buffer object.
         */

        void Bind() const noexcept override;

        /**
         * @fn Unbind
         * @brief Unbinds a index buffer object.
         */

        void Unbind() const noexcept override;

        /**
         * @fn GetCount        Bald::Graphics::VertexBufferLayout m_Layout;
         * @brief Returns number of elements in buffer's data.
         * @return [unsigned int]
         */

        [[nodiscard]] inline unsigned GetCount() const noexcept override { return static_cast<unsigned>(m_Size/sizeof(unsigned)); }

        /**
         * @fn GetID
         * @brief ID getter.
         * @return [unsigned] Index buffer id.
         */

        [[nodiscard]] inline unsigned GetID() const noexcept override { return m_BufferID; };

    private:
        unsigned m_BufferID; /**< identifier of Index Buffer object >*/
        unsigned m_Size; /**< Size of elements in buffer's data in bytes>*/
    }; // END OF CLASS OpenGLIndexBuffer

} // END OF NAMESPACE Bald::Platform::Graphics
