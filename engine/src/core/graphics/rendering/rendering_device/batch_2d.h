//
// Created by blinku on 23.11.2019.
//

#pragma once

#include <memory>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include "graphics/rendering/buffers/vertex_buffer_layout.h"
#include "graphics/rendering/buffers/vertex_array.h"
#include "graphics/rendering/buffers/vertex_buffer.h"
#include "graphics/rendering/buffers/index_buffer.h"
#include "graphics/rendering/shaders/shader.h"

namespace Bald::Graphics {
    class Sprite;

    class Camera2D;

    struct SpriteVertexData {
        glm::vec3 m_Position;
        glm::vec4 m_Color;
        glm::vec2 m_TextureCoord;
        float m_TextureId;
    };

    class Batch2D {
        using TEXTURE_ID = uint32_t;

    public:
        Batch2D();

        void Begin(const Camera2D& camera) noexcept;

        bool Submit(const Sprite& sprite);

        void End() const noexcept;

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
        std::shared_ptr<Shader> m_QuadShader;
        std::vector<TEXTURE_ID> m_Textures;
        std::vector<int32_t> m_TextureUnits;
    }; // END OF CLASS Batch
} // END OF NAMESPACE Bald::Graphics


