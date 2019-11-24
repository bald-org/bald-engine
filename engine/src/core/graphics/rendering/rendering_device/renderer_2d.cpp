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

namespace Bald::Graphics {

    void Renderer2D::Init() noexcept {
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
