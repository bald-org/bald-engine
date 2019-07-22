//
// Created by blinku on 08.05.19.
//

#include "index_buffer.h"
#include "glad/glad.h"

namespace Bald::Graphics {

    std::unique_ptr<IndexBuffer> IndexBuffer::Create(unsigned short* data, unsigned count) noexcept {
        return std::make_unique<Bald::Platform::Graphics::OpenGLIndexBuffer>((data, count));
    }
} // END OF NAMESPACE Bald::Graphics