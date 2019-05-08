//
// Created by blinku on 08.05.19.
//

#pragma once

namespace Bald::Graphics {

    /**
     * @class Buffer
     * @brief Simple OpenGL buffer abstraction
     */

    class Buffer {
    public:

        /**
         * @fn                      Buffer
         * @brief                   creates a buffer object and initializes its data
         * @param [float*]          data -> to initialize buffer
         * @param [unsigned int]    count -> number of elements in data
         * @param [unsigned int]    component_count -> number of components in data
         */

        Buffer(float* data, int count, unsigned component_count) noexcept;

        /**
         * @fn ~Buffer
         * @brief destructor of Buffer
         */

        ~Buffer();

        /**
         * @fn    Bind
         * @brief binds a buffer object
         */

        void Bind() const noexcept;

        /**
         * @fn    Bind
         * @brief unbinds a buffer object
         */

        void Unbind() const noexcept;

        /**
         * @fn     GetComponentCount
         * @brief  returns number of components in buffer's data
         * @return [unsigned int]
         */

        [[nodiscard]] inline unsigned GetComponentCount() const noexcept;

    private:
        unsigned m_BufferID;
        unsigned m_ComponentCount;
    };

    unsigned Buffer::GetComponentCount() const noexcept {
        return m_ComponentCount;
    } // END OF CLASS Buffer

} // END OF NAMESPACE Bald::Graphics
