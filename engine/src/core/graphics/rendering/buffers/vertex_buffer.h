//
// Created by blinku on 08.05.19.
//

#pragma once

namespace Bald::Graphics {

    /**
     * @class Buffer
     * @brief Simple buffer abstraction.
     */

    class VertexBuffer {
    public:

        /**
         * @fn Create
         * @brief Creates vertex buffer based on currently chosen rendering API.
         * @param [float*] data -> Pointer to the memory containing data (eg. triangle vertices)
         * @param [int] count -> Number of data points.
         * @param [int] component_count -> Number of components in data.
         * @return [Buffer*] Pointer to the buffer object.
         */

        static VertexBuffer* Create(float* data, unsigned count, unsigned component_count);

        /**
         * @fn ~VertexBuffer
         * @brief Default virtual destructor.
         */

        virtual ~VertexBuffer() = default;

        /**
         * @fn Bind
         * @brief Binds the buffer.
         */

        virtual void Bind() const noexcept = 0;

        /**
         * @fn Unbind
         * @brief Unbinds the buffer.
         */

        virtual void Unbind() const noexcept = 0;

        /**
         * @fn GetComponentCount
         * @brief Component count getter.
         * @return [unsigned] Number of components in the buffer.
         */

        [[nodiscard]] virtual unsigned GetComponentCount() const noexcept = 0;

        /**
         * @fn GetID
         * @brief ID getter.
         * @return [unsigned] VertexBuffer id.
         */

        [[nodiscard]] virtual unsigned GetID() const noexcept = 0;

    }; // END OF CLASS VertexBuffer

} // END OF NAMESPACE Bald::Graphics
