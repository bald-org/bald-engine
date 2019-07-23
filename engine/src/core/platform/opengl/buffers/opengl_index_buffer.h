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
    public:

        /**
         * @fn OpenGLIndexBuffer
         * @brief creates a index buffer object and initializes its data.
         * @param [unsigned short*] data -> to initialize buffer.
         * @param [unsigned] count -> number of elements in data.
         */

        OpenGLIndexBuffer(unsigned short* data, unsigned count) noexcept;

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
         * @fn GetCount
         * @brief Returns number of elements in buffer's data.
         * @return [unsigned int]
         */

        [[nodiscard]] inline unsigned GetCount() const noexcept override { return m_Count; }

        /**
         * @fn GetID
         * @brief ID getter.
         * @return [unsigned] Index buffer id.
         */

        [[nodiscard]] inline unsigned GetID() const noexcept override { return m_BufferID; };

    private:
        unsigned m_BufferID; /**< identifier of Index Buffer object >*/
        unsigned m_Count; /**< number of elements in buffer's data >*/
    }; // END OF CLASS OpenGLIndexBuffer

} // END OF NAMESPACE Bald::Platform::Graphics
