//
// Created by blinku on 07.08.2019.
//

#include "renderer_2d.h"
#include "graphics/rendering/buffers/vertex_array.h"
#include "graphics/rendering/sprite.h"
#include "graphics/rendering/camera_2d.h"

namespace Bald::Graphics {

    void Renderer2D::Init() noexcept {
        Renderer2DData::m_Batch = std::make_shared<Batch2D>();
    }

    void Renderer2D::Shutdown() noexcept {}

    void Renderer2D::Begin(const Camera2D& camera) noexcept {
        Renderer2DData::m_Camera = &camera;
        Renderer2DData::m_Batch->Begin(camera);
    }

    void Renderer2D::Submit(const Sprite& sprite) noexcept {
        const bool success = Renderer2DData::m_Batch->Submit(sprite);
        if(!success) {
            Draw();
            Begin(*Renderer2DData::m_Camera);
            Submit(sprite);
        }
    }

    void Renderer2D::Draw() noexcept {
        Renderer2DData::m_Batch->End();
        Renderer2DData::m_Batch->Draw();
    }

    void Renderer2D::End() noexcept {
        Draw();
    }

} // END OF NAMESPACE Bald::Graphics
