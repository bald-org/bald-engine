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
    friend class Bald::Graphics::VertexBuffer;
    private:

        /**
         * @fn OpenGLVertexBuffer
         * @brief Creates an OpenGL vertex buffer object and initializes it's data.
         * @param [float*] data -> Pointer to the memory containing data (eg. triangle vertices)
         * @param [unsigned] size -> Size of data array in bytes.
         */

        OpenGLVertexBuffer(float* data, unsigned count) noexcept;

    public:
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
         * @fn GetID
         * @brief ID getter.
         * @return [unsigned] Buffer id.
         */

        [[nodiscard]] inline unsigned GetID() const noexcept override { return m_BufferID; };

    private:
        unsigned m_BufferID;

    }; // END OF CLASS OpenGLVertexBuffer

} // END OF NAMESPACE Bald::Platform::Graphics
