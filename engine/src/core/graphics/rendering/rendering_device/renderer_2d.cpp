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

    void Renderer2D::Init() noexcept {
        float vertices[] = {
            //layout(location = 0)      //layout(location = 1)      layout(location = 2)
            -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
            -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
            0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
            0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f
        };//

        unsigned indices[] = {
            0, 1, 2, // first triangle
            2, 3, 0  // second triangle
        };

        VertexBufferLayout layout = {
            {0, ShaderBuiltInType::Float, ShaderBuiltInTypeSize::Vec2, "in_Position"},
            {1, ShaderBuiltInType::Float, ShaderBuiltInTypeSize::Vec4, "in_Color"},
            {2, ShaderBuiltInType::Float, ShaderBuiltInTypeSize::Vec2, "in_TexCoord"}
        };

        Renderer2DData::m_QuadVBO = VertexBuffer::Create(vertices, sizeof(vertices));
        Renderer2DData::m_QuadVBO->SetLayout(layout);

        Renderer2DData::m_QuadIBO = IndexBuffer::Create(indices, sizeof(indices));

        Renderer2DData::m_QuadVAO = VertexArray::Create();
        Renderer2DData::m_QuadVAO->AddVertexBuffer(Renderer2DData::m_QuadVBO);
        Renderer2DData::m_QuadVAO->AddIndexBuffer(Renderer2DData::m_QuadIBO);

        Renderer2DData::m_QuadShader = Shader::Create("../engine/res/shaders/sprite.vert",
                                                      "../engine/res/shaders/sprite.frag");

        Renderer2DData::m_Batch = std::make_shared<Batch2D>();

    }

    void Renderer2D::Shutdown() noexcept {

    }

    void Renderer2D::Begin(const Camera2D& camera) noexcept {
        Renderer2DData::m_QuadShader->Bind();
        Renderer2DData::m_QuadShader->SetUniformMatrix4fv("u_ProjectionView", camera.GetProjectionViewMatrix());
        Renderer2DData::m_QuadShader->Unbind();

        Renderer2DData::m_Batch->Map();
    }

    void Renderer2D::Submit(const Sprite& sprite) noexcept {
        Renderer2DData::m_Batch->Submit(sprite);
    }

    void Renderer2D::Draw() noexcept {
        Renderer2DData::m_Batch->Unmap();

        Renderer2DData::m_QuadShader->Bind();
        Renderer2DData::m_QuadShader->SetUniformMatrix4fv("u_Model", glm::mat4(1.0f));

        Renderer2DData::m_Batch->Draw();

        Renderer2DData::m_QuadShader->Unbind();
    }

    void Renderer2D::End() noexcept {

    }

} // END OF NAMESPACE Bald::Graphics
