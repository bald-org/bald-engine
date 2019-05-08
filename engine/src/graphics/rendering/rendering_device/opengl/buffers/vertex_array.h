//
// Created by blinku on 08.05.19.
//

#pragma once

#include <vector>

namespace Bald::Graphics {

    class Buffer;

    class VertexArray {
    public:

        /**
         * @fn    VertexArray
         * @brief Create Vertex Array Object
         */

        VertexArray() noexcept;

        /**
         * @fn    ~VertexArray
         * @brief VertexArray destructor
         */

        ~VertexArray();

        /**
         * @fn                              AddBuffer
         * @brief                           Adds buffer to vertex array
         * @param [Buffer*]                 buffer -> Pointer to dynamically created buffer
         * @param [GLuint aka unsinged int] index -> Specifies the index of the generic vertex attribute to be enabled
         */

        void AddBuffer(Buffer* buffer, unsigned index) noexcept;

        /**
         * @fn    Bind
         * @brief binds a vertex array object
         */

        void Bind() noexcept;

        /**
         * @fn    Unbind
         * @brief unbind a vertex array object
         */

        void Unbind() noexcept;

    private:
        unsigned m_ArrayID;             /**< identifier of Vertex Array object >*/
        std::vector<Buffer*> m_Buffers; /**< pointers to buffers added to Vertex Array >*/
    }; // END OF CLASS VertexArray

} // END OF NAMESPACE Bald::Graphics
