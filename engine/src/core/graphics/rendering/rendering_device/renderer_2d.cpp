//
// Created by blinku on 07.08.2019.
//

#include "renderer_2d.h"
#include "graphics/rendering/buffers/vertex_array.h"
#include "graphics/rendering/sprite.h"
#include "graphics/rendering/camera_2d.h"

namespace Bald::Graphics {

    void Renderer2D::Init() noexcept {
        CORE_LOG_INFO("[Renderer2D] Initializing down renderer 2D...");
        Renderer2DStorage::m_Batch = std::make_unique<Batch2D>();
        CORE_LOG_INFO("[Renderer2D] Initialization was successful");
    }

    void Renderer2D::Shutdown() noexcept {
        CORE_LOG_INFO("[Renderer2D] Shutting down renderer 2D...");
        Renderer2DStorage::m_Batch.reset(nullptr);
        CORE_LOG_INFO("[Renderer2D] Shutdown was successful");
    }

    void Renderer2D::Begin(const Camera2D& camera) noexcept {
        Renderer2DStorage::m_Camera = &camera;
        Renderer2DStorage::m_Batch->Begin(camera);
    }

    void Renderer2D::Submit(const Sprite& sprite) noexcept {
        const bool success = Renderer2DStorage::m_Batch->Submit(sprite);
        if(!success) {
            Draw();
            Begin(*Renderer2DStorage::m_Camera);
            Submit(sprite);
        }
    }

    void Renderer2D::Draw() noexcept {
        Renderer2DStorage::m_Batch->End();
        Renderer2DStorage::m_Batch->Draw();
    }

    void Renderer2D::End() noexcept {
        Draw();
    }

} // END OF NAMESPACE Bald::Graphics
