//
// Created by blinku on 23.11.2019.
//

#include "batch_2d.h"
#include "graphics/rendering/sprite.h"

namespace Bald::Graphics {
    static constexpr uint32_t MAX_SPRITES = 10000;
    static constexpr uint32_t SPRITE_VERTEX_DATA_SIZE = sizeof(SpriteVertexData);
    static constexpr uint32_t SPRITE_SIZE = 4 * SPRITE_VERTEX_DATA_SIZE;
    static constexpr uint32_t INDICES_SIZE = 6;
    static constexpr uint32_t MAX_VERTICES = SPRITE_SIZE * MAX_SPRITES;
    static constexpr uint32_t MAX_INDICES = INDICES_SIZE * MAX_SPRITES;

    Batch2D::Batch2D() :
        m_MaxVertices(MAX_VERTICES),
        m_UsedVertices(0),
        m_MaxIndices(MAX_INDICES),
        m_UsedIndices(0),
        m_QuadVAO(nullptr),
        m_QuadVBO(nullptr) {
        VertexBufferLayout layout = {
            {0, ShaderBuiltInType::Float, ShaderBuiltInTypeSize::Vec3, "in_Position"},
            {1, ShaderBuiltInType::Float, ShaderBuiltInTypeSize::Vec4, "in_Color"},
            {2, ShaderBuiltInType::Float, ShaderBuiltInTypeSize::Vec2, "in_TexCoord"}
        };

        m_QuadVBO = VertexBuffer::Create(nullptr, m_MaxVertices);
        m_QuadVBO->SetLayout(layout);

        std::array<uint32_t, MAX_INDICES> indices = {0};
        uint32_t offset = 0;
        for(uint32_t i = 0; i < MAX_INDICES; i += 6) {
            indices[i] = offset + 0;
            indices[i + 1] = offset + 1;
            indices[i + 2] = offset + 2;

            indices[i + 3] = offset + 0;
            indices[i + 4] = offset + 2;
            indices[i + 5] = offset + 3;

            offset += 4;
        }

        m_QuadIBO = IndexBuffer::Create(indices.data(), sizeof(indices));

        m_QuadVAO = VertexArray::Create();
        m_QuadVAO->AddVertexBuffer(m_QuadVBO);
        m_QuadVAO->AddIndexBuffer(m_QuadIBO);
    }

    void Batch2D::Submit(const Sprite& sprite) {
        if(m_UsedVertices + SPRITE_SIZE > MAX_VERTICES) return; // TODO: Error handling using expected!
        const auto& position = sprite.GetPosition();
        const auto& size = sprite.GetSize();
        const auto& color = sprite.GetColor();

        m_MappedBuffer->m_Position = {position.x, position.y, position.z};
        m_MappedBuffer->m_Color = color;
        m_MappedBuffer->m_TexCoord = {0.0f, 0.0f};
        ++m_MappedBuffer;

        m_MappedBuffer->m_Position = {position.x, position.y + size.y, position.z};
        m_MappedBuffer->m_Color = color;
        m_MappedBuffer->m_TexCoord = {0.0f, 1.0f};
        ++m_MappedBuffer;

        m_MappedBuffer->m_Position = {position.x + size.x, position.y + size.y, position.z};
        m_MappedBuffer->m_Color = color;
        m_MappedBuffer->m_TexCoord = {1.0f, 1.0f};
        ++m_MappedBuffer;

        m_MappedBuffer->m_Position = {position.x + size.x, position.y, position.z};
        m_MappedBuffer->m_Color = color;
        m_MappedBuffer->m_TexCoord = {1.0f, 0.0f};
        ++m_MappedBuffer;

        m_UsedVertices += SPRITE_SIZE;
        m_UsedIndices += INDICES_SIZE;
    }

    void Batch2D::Map() noexcept {
        m_QuadVBO->Bind();
        m_MappedBuffer = reinterpret_cast<SpriteVertexData*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
    }

    void Batch2D::Unmap() const noexcept {
        glUnmapBuffer(GL_ARRAY_BUFFER);
        m_QuadVBO->Unbind();
    }

    void Batch2D::Draw() noexcept {
        m_QuadVAO->Bind();
        glDrawElements(GL_TRIANGLES, static_cast<int32_t>(m_UsedIndices), GL_UNSIGNED_INT, nullptr);
        m_QuadVAO->Unbind();

        m_UsedVertices = 0;
        m_UsedIndices = 0;
    }
}
