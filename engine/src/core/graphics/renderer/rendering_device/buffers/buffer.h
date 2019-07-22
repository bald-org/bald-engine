//
// Created by blinku on 08.05.19.
//

#pragma once

#include <memory>

namespace Bald::Graphics {

    /**
     * @class Buffer
     * @brief Simple buffer abstraction.
     */

    class Buffer {
    public:
        static Buffer* Create(float* data, int count, unsigned component_count) noexcept;
        virtual ~Buffer() = default;
        virtual void Bind() const noexcept = 0;
        virtual void Unbind() const noexcept = 0;
        [[nodiscard]] virtual int GetComponentCount() const noexcept = 0;
    }; // END OF CLASS Buffer

} // END OF NAMESPACE Bald::Graphics
