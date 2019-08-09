//
// Created by blinku on 07.08.2019.
//

#include "renderer_2d.h"
#include "graphics/rendering/buffers/vertex_buffer_layout.h"
#include "graphics/rendering/buffers/vertex_array.h"
#include "graphics/rendering/buffers/vertex_buffer.h"
#include "graphics/rendering/buffers/index_buffer.h"
#include "graphics/rendering/shaders/shader.h"
#include "graphics/rendering/sprite.h"
#include "graphics/rendering/camera_2d.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Bald::Graphics {

    Renderer2D::Renderer2D() {
        float vertices[] = {
            //layout(location = 0)        layout(location = 1)             layout(location = 2)
            -0.5f, -0.5f,                 1.0f, 0.0f, 0.0f, 1.0f,          0.0f, 0.0f,
            -0.5f,  0.5f,                 0.0f, 1.0f, 0.0f, 1.0f,          0.0f, 1.0f,
             0.5f,  0.5f,                 0.0f, 0.0f, 1.0f, 1.0f,          1.0f, 1.0f,
             0.5f, -0.5f,                 1.0f, 1.0f, 1.0f, 1.0f,          1.0f, 0.0f
        };//

        unsigned indices[] = {
            0, 1, 2, // first triangle
            0, 2, 3  // second triangle
        };

        Bald::Graphics::VertexBufferLayout layout = {
            {0, Bald::Graphics::ShaderBuiltInType::Float, Bald::Graphics::ShaderBuiltInTypeSize::Vec2, "in_Position"},
            {1, Bald::Graphics::ShaderBuiltInType::Float, Bald::Graphics::ShaderBuiltInTypeSize::Vec4, "in_Color"},
            {2, Bald::Graphics::ShaderBuiltInType::Float, Bald::Graphics::ShaderBuiltInTypeSize::Vec2, "in_TexCoord"}
        };

        m_QuadVBO = VertexBuffer::Create(vertices, sizeof(vertices));
        m_QuadVBO->SetLayout(layout);

        m_QuadIBO = IndexBuffer::Create(indices, sizeof(indices));

        m_QuadVAO = VertexArray::Create();
        m_QuadVAO->AddVertexBuffer(m_QuadVBO);
        m_QuadVAO->AddIndexBuffer(m_QuadIBO);

        m_QuadShader = Shader::Create("../engine/res/shaders/sprite.vert", "../engine/res/shaders/sprite.frag");
    }

    void Renderer2D::Begin(const Camera2D& camera) noexcept {
        m_QuadShader->Bind();
        m_QuadShader->SetUniformMatrix4fv("u_ProjectionView", camera.GetProjectionViewMatrix());
    }

    void Renderer2D::Submit(const Sprite& sprite) noexcept {
        m_QuadShader->Bind();
        sprite.GetTexture()->Bind();
        m_QuadVAO->Bind();

        const glm::vec2& pos = sprite.GetPosition();
        const glm::vec2& scale = sprite.GetSize();
        glm::mat4 model = glm::translate(glm::mat4(1.0f), {pos.x, pos.y, 0.0f}) *
                          glm::scale(glm::mat4(1.0f), {scale.x, scale.y, 0.0f}) *
                          glm::rotate(glm::mat4(1.0f), glm::radians(sprite.GetRotation()), {0.0f, 0.0f, 1.0f});

        m_QuadShader->SetUniformMatrix4fv("u_Model", model);

        glDrawElements(GL_TRIANGLES, static_cast<int32_t>(m_QuadVAO->GetIndexBuffer()->GetCount()), GL_UNSIGNED_INT, nullptr);

        m_QuadShader->Unbind();
        sprite.GetTexture()->Unbind();
        m_QuadVAO->Unbind();
    }

    void Renderer2D::End() noexcept {

    }

} // END OF NAMESPACE Bald::Graphics
