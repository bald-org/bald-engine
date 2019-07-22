//
// Created by blinku on 22.07.19.
//

#pragma once

#include "graphics/renderer/rendering_device/index_buffer.h"

namespace Bald::Platform::Graphics {

    /**
     * @class OpenGLIndexBuffer
     * @brief Simple OpenGL index buffer abstraction
     */

    class OpenGLIndexBuffer : Bald::Graphics::IndexBuffer {
    public:

        /**
         * @fn                      OpenGLIndexBuffer
         * @brief                   creates a index buffer object and initializes its data
         * @param [unsigned short*] data -> to initialize buffer
         * @param [unsigned]        count -> number of elements in data
         */

        OpenGLIndexBuffer(unsigned short* data, unsigned count) noexcept;

        /**
         * @fn ~OpenGLIndexBuffer
         * @brief destructor of OpenGLIndexBuffer
         */

        ~OpenGLIndexBuffer();

        /**
         * @fn    Bind
         * @brief binds a index buffer object
         */

        void Bind() const noexcept;

        /**
         * @fn    Unbind
         * @brief unbinds a index buffer object
         */

        void Unbind() const noexcept;

        /**
         * @fn     GetCount
         * @brief  returns number of elements in buffer's data
         * @return [unsigned int]
         */

        [[nodiscard]] inline unsigned GetCount() const noexcept;

    private:
        unsigned m_BufferID; /**< identifier of Index Buffer object >*/
        unsigned m_Count; /**< number of elements in buffer's data >*/
    }; // END OF CLASS OpenGLIndexBuffer

    unsigned IndexBuffer::GetCount() const noexcept { return m_Count; }

} // END OF NAMESPACE Bald::Platform::Graphics
