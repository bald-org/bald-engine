//
// Created by blinku on 08.05.19.
//

#pragma once

namespace Bald::Graphics {

    /**
     * @class IndexBuffer
     * @brief Simple index buffer abstraction.
     */

    class IndexBuffer {
    public:

        /**
        * @fn Create
        * @brief Creates data buffer based on currently chosen rendering API.
        * @param [unsigned*] data -> Pointer to the memory containing data (eg. triangle indices)
        * @param [unsigned] size -> Size of data array in bytes.
        * @return [IndexBuffer*] Pointer to the index buffer object.
        */

        static IndexBuffer* Create(unsigned* data, unsigned size);

        /**
         * @fn ~IndexBuffer
         * @brief Default virtual destructor.
         */

        virtual ~IndexBuffer() = default;

        /**
         * @fn Bind
         * @brief Binds the index buffer.
         */

        virtual void Bind() const noexcept = 0;

        /**
         * @fn Unbind
         * @brief Unbinds the index buffer.
         */

        virtual void Unbind() const noexcept = 0;

        /**
         * @fn GetComponentCount
         * @brief Component count getter.
         * @return [unsigned] Number of components in the buffer.
         */
        [[nodiscard]] virtual unsigned GetCount() const noexcept = 0;

        /**
         * @fn GetID
         * @brief ID getter.
         * @return [unsigned] Index buffer id.
         */

        [[nodiscard]] virtual unsigned GetID() const noexcept = 0;

    }; // END OF CLASS IndexBuffer

} // END OF NAMESPACE Bald::Graphics
