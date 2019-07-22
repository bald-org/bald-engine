//
// Created by blinku on 08.05.19.
//

#pragma once

#include <memory>

namespace Bald::Graphics {

    class IndexBuffer {
    public:

        static std::unique_ptr<IndexBuffer> Create(unsigned short* data, unsigned count) noexcept;
        virtual ~IndexBuffer() = default;
        virtual void Bind() const noexcept = 0;
        virtual void Unbind() const noexcept = 0;
        [[nodiscard]] inline virtual unsigned GetCount() const noexcept = 0;

    }; // END OF CLASS IndexBuffer

} // END OF NAMESPACE Bald::Graphics
