//
// Created by blinku on 07.08.2019.
//

#pragma once

#include <memory>
#include "batch_2d.h"

namespace Bald::Graphics {

    class Sprite;
    class VertexArray;
    class VertexBuffer;
    class IndexBuffer;
    class Shader;
    class Camera2D;

    struct Renderer2DData {
        static inline std::shared_ptr<Batch2D> m_Batch = nullptr;
        static inline const Camera2D* m_Camera = nullptr;
    };

    class Renderer2D {
    public:
        Renderer2D() = delete;
        ~Renderer2D() = delete;

        static void Init() noexcept;
        static void Shutdown() noexcept;

        static void Begin(const Camera2D& camera) noexcept;
        static void Submit(const Sprite& sprite) noexcept;
        static void End() noexcept;
    private:
        static void Draw() noexcept;
    }; // END OF CLASS Renderer2D

} // END OF NAMESPACE Bald::Graphics
