//
// Created by blinku on 22.07.19.
//

#pragma once

#include <vector>
#include "graphics/rendering/buffers/vertex_array.h"
#include "graphics/rendering/buffers/vertex_buffer.h"

namespace Bald::Platform::Graphics {

    /**
     * @class OpenGLVertexArray
     * @brief Simple OpenGL vertex array implementation.
     */

    class OpenGLVertexArray : public Bald::Graphics::VertexArray {
    public:

        /**
         * @fn OpenGLVertexArray
         * @brief Create OpenGL vertex array Object.
         */

        OpenGLVertexArray() noexcept;

        /**
         * @fn ~OpenGLVertexArray
         * @brief OpenGLVertexArray destructor.
         */

        ~OpenGLVertexArray() override;

        /**
         * @fn AddVertexBuffer
         * @brief Adds buffer to vertex array.
         * @param [Buffer*] buffer -> Pointer to dynamically created buffer.
         * @param [GLuint aka unsinged int] index -> Specifies the index of the generic vertex attribute to be enabled.
         */

        void AddVertexBuffer(Bald::Graphics::VertexBuffer* buffer, unsigned index) noexcept override;

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
        std::vector<Bald::Graphics::VertexBuffer*> m_Buffers; /**< pointers to buffers added to Vertex Array >*/
    }; // END OF CLASS OpenGLVertexArray

} // END OF NAMESPACE Bald::Platform::Graphics
