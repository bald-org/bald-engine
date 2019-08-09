//
// Created by blinku on 07.08.2019.
//

#pragma once

#include <memory>

namespace Bald::Graphics {

    class Sprite;
    class VertexArray;
    class VertexBuffer;
    class IndexBuffer;
    class Shader;
    class Camera2D;

    class Renderer2D {
    public:
        Renderer2D();

        void Begin(const Camera2D& camera) noexcept;
        void Submit(const Sprite& sprite) noexcept;
        void End() noexcept;
    private:
        std::shared_ptr<VertexArray> m_QuadVAO = nullptr;
        std::shared_ptr<VertexBuffer> m_QuadVBO = nullptr;
        std::shared_ptr<IndexBuffer> m_QuadIBO = nullptr;
        std::shared_ptr<Shader> m_QuadShader = nullptr;

    }; // END OF CLASS Renderer2D

} // END OF NAMESPACE Bald::Graphics
