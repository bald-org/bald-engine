//
// Created by blinku on 08.05.19.
//

#pragma once

#include "graphics/renderer/rendering_device/buffers/buffer.h"

namespace Bald::Platform::Graphics {

    /**
     * @class Buffer
     * @brief Simple OpenGL buffer abstraction.
     */

class OpenGLBuffer : public Bald::Graphics::Buffer {
    public:

        /**
         * @fn OpenGLBuffer
         * @brief Creates a buffer object and initializes its data.
         * @param [float*] data -> to initialize buffer
         * @param [int] count -> number of elements in data
         * @param [int] component_count -> number of components in data
         */

        OpenGLBuffer(float* data, int count, int component_count) noexcept;

        /**
         * @fn ~OpenGLBuffer
         * @brief Destructor of OpenGLBuffer.
         */

        ~OpenGLBuffer() override;

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
         * @fn GetComponentCount
         * @brief Returns number of components in buffer's data.
         * @return [unsigned int]
         */

        [[nodiscard]] inline int GetComponentCount() const noexcept override { return m_ComponentCount; }

    private:
        unsigned m_BufferID;
        int m_ComponentCount;
    }; // END OF CLASS OpenGLBuffer

} // END OF NAMESPACE Bald::Platform::Graphics
