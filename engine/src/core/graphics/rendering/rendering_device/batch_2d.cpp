//
// Created by blinku on 23.11.2019.
//

#include "batch_2d.h"
#include "graphics/rendering/camera_2d.h"
#include "graphics/rendering/sprite.h"
#include <cstring>

namespace Bald::Graphics {
    static constexpr uint32_t MAX_TEXTURES_PER_SHADER = 32;
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
            {2, ShaderBuiltInType::Float, ShaderBuiltInTypeSize::Vec2, "in_TextureCoord"},
            {3, ShaderBuiltInType::Float, ShaderBuiltInTypeSize::Vec1, "in_TextureId"}
        };

        m_QuadVBO = VertexBuffer::Create(nullptr, m_MaxVertices);
        m_QuadVBO->SetLayout(layout);

        std::array<uint32_t, MAX_INDICES> indices = {0};
        uint32_t offset = 0;
        for(std::size_t i = 0; i < MAX_INDICES; i += 6) {
            indices[i] = offset + 0;
            indices[i + 1] = offset + 1;
            indices[i + 2] = offset + 2;

            indices[i + 3] = offset + 0;
            indices[i + 4] = offset + 2;
            indices[i + 5] = offset + 3;

            offset += 4;
        }

        for(std::size_t i = 0; i < MAX_TEXTURES_PER_SHADER; i++) {
            m_TextureUnits.push_back(static_cast<int32_t>(i));
        }

        m_QuadIBO = IndexBuffer::Create(indices.data(), sizeof(indices));

        m_QuadVAO = VertexArray::Create();
        m_QuadVAO->AddVertexBuffer(m_QuadVBO);
        m_QuadVAO->AddIndexBuffer(m_QuadIBO);

        m_QuadShader = Shader::Create("../engine/res/shaders/sprite.vert",
                                      "../engine/res/shaders/sprite.frag");
    }

    Batch2D::~Batch2D() {
        if(m_MappedBuffer != nullptr) {
            m_QuadVBO->Bind();
            glUnmapBuffer(GL_ARRAY_BUFFER);
            m_QuadVBO->Unbind();
        }
    }

    bool Batch2D::Submit(const Sprite& sprite) {
        if(m_UsedVertices + SPRITE_SIZE > MAX_VERTICES) return false; // TODO: Error handling using expected!

        const auto textureID = static_cast<uint32_t>(sprite.GetTexture()->GetID());

        float textureSlot = 0.0f;
        if(textureID > 0) {
            bool found = false;
            for(std::size_t i = 0; i < m_Textures.size(); i++) {
                if(m_Textures[i] == textureID) {
                    found = true;
                    textureSlot = static_cast<float>(i);
                    break;
                }
            }

            if(!found) {
                if(m_Textures.size() >= MAX_TEXTURES_PER_SHADER) {
                    return false;
                }
                m_Textures.push_back(textureID);
                textureSlot = static_cast<float>(m_Textures.size() - 1);
            }
        }

        const glm::vec3& position = sprite.GetPosition();
        const glm::vec2& size = sprite.GetSize();
        const glm::vec4& color = sprite.GetColor();

        m_MappedBuffer->m_Position = {position.x, position.y, position.z};
        m_MappedBuffer->m_Color = color;
        m_MappedBuffer->m_TextureCoord = {0.0f, 0.0f};
        m_MappedBuffer->m_TextureId = textureSlot;
        ++m_MappedBuffer;

        m_MappedBuffer->m_Position = {position.x, position.y + size.y, position.z};
        m_MappedBuffer->m_Color = color;
        m_MappedBuffer->m_TextureCoord = {0.0f, 1.0f};
        m_MappedBuffer->m_TextureId = textureSlot;
        ++m_MappedBuffer;

        m_MappedBuffer->m_Position = {position.x + size.x, position.y + size.y, position.z};
        m_MappedBuffer->m_Color = color;
        m_MappedBuffer->m_TextureCoord = {1.0f, 1.0f};
        m_MappedBuffer->m_TextureId = textureSlot;
        ++m_MappedBuffer;

        m_MappedBuffer->m_Position = {position.x + size.x, position.y, position.z};
        m_MappedBuffer->m_Color = color;
        m_MappedBuffer->m_TextureCoord = {1.0f, 0.0f};
        m_MappedBuffer->m_TextureId = textureSlot;
        ++m_MappedBuffer;

        m_UsedVertices += SPRITE_SIZE;
        m_UsedIndices += INDICES_SIZE;

        return true;
    }

    void Batch2D::Begin(const Camera2D& camera) noexcept {
        m_QuadShader->Bind();
        m_QuadShader->SetUniformMatrix4fv("u_ProjectionView", camera.GetProjectionViewMatrix());
        m_QuadShader->Unbind();

        m_QuadVBO->Bind();
        m_MappedBuffer = reinterpret_cast<SpriteVertexData*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
    }

    void Batch2D::End() noexcept {
        glUnmapBuffer(GL_ARRAY_BUFFER);
        m_QuadVBO->Unbind();
        m_MappedBuffer = nullptr;
    }

    void Batch2D::Draw() noexcept {
        m_QuadVAO->Bind();
        m_QuadShader->Bind();
        m_QuadShader->SetUniformMatrix4fv("u_Model", glm::mat4(1.0f));
        for(uint32_t i = 0; i < m_Textures.size(); i++) {
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, m_Textures[i]);
        }

        m_QuadShader->SetUniform1iv("u_Textures", m_Textures.size(), m_TextureUnits.data());

        glDrawElements(GL_TRIANGLES, static_cast<int32_t>(m_UsedIndices), GL_UNSIGNED_INT, nullptr);

        m_QuadShader->Unbind();
        m_QuadVAO->Unbind();

        m_UsedVertices = 0;
        m_UsedIndices = 0;

        m_Textures.clear();
    }

}
