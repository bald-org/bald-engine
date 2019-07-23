//
// Created by blinku on 08.05.19.
//

#pragma once

#include "graphics/rendering/buffers/buffer.h"

namespace Bald::Platform::Graphics {

    /**
     * @class OpenGLBuffer
     * @brief Simple OpenGL buffer implementation.
     */

    class OpenGLBuffer : public Bald::Graphics::Buffer {
    public:

        /**
         * @fn OpenGLBuffer
         * @brief Creates a buffer object and initializes its data.
         * @param [float*] data -> to initialize buffer.
         * @param [unsigned] count -> number of elements in data.
         * @param [unsigned] component_count -> number of components in data.
         */

        OpenGLBuffer(float* data, unsigned count, unsigned component_count) noexcept;

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

        [[nodiscard]] inline unsigned GetComponentCount() const noexcept override { return m_ComponentCount; }

        /**
         * @fn GetID
         * @brief ID getter.
         * @return [unsigned] Buffer id.
         */

        [[nodiscard]] inline unsigned GetID() const noexcept override { return m_BufferID; };

    private:
        unsigned m_BufferID;
        unsigned m_ComponentCount;
    }; // END OF CLASS OpenGLBuffer

} // END OF NAMESPACE Bald::Platform::Graphics
