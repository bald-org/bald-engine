//
// Created by blinku on 23.11.2019.
//

#pragma once

#include <memory>
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>

#include "graphics/rendering/buffers/vertex_buffer_layout.h"
#include "graphics/rendering/buffers/vertex_array.h"
#include "graphics/rendering/buffers/vertex_buffer.h"
#include "graphics/rendering/buffers/index_buffer.h"

namespace Bald::Graphics {
    class Sprite;

    struct SpriteVertexData {
        glm::vec2 m_Position;
        glm::vec4 m_Color;
        glm::vec2 m_TexCoord;
    };

    class Batch2D {
    public:
        Batch2D();

        void Map() noexcept;
        void Submit(const Sprite& sprite);
        void Unmap() const noexcept;
        void Draw() noexcept;


    private:
        SpriteVertexData* m_MappedBuffer = nullptr;
        uint32_t m_MaxVertices;
        uint32_t m_UsedVertices;
        uint32_t m_MaxIndices;
        uint32_t m_UsedIndices;
        std::shared_ptr<VertexArray> m_QuadVAO;
        std::shared_ptr<VertexBuffer> m_QuadVBO;
        std::shared_ptr<IndexBuffer> m_QuadIBO;
    }; // END OF CLASS Batch
} // END OF NAMESPACE Bald::Graphics


