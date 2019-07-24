//
// Created by blinku on 08.05.19.
//

#pragma once

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
         * @param [float*] data -> to initialize buffer.
         * @param [unsigned] count -> number of elements in data.
         * @param [unsigned] component_count -> number of components in data.
         */

        OpenGLVertexBuffer(float* data, unsigned count, unsigned component_count) noexcept;

        /**
         * @fn ~OpenGLBuffer
         * @brief Destructor of OpenGLBuffer.
         */

        ~OpenGLVertexBuffer() override;

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
    }; // END OF CLASS OpenGLVertexBuffer

} // END OF NAMESPACE Bald::Platform::Graphics
