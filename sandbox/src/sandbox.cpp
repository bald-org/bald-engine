//
// Created by blinku on 07.05.19.
//

#include "bald.h"

using namespace Bald;


class GameLayer : public Bald::Layer {
GENERATE_BODY(DERIVED)

public:

    GameLayer() = default;

    ~GameLayer() override = default;

    void OnAttach() noexcept override {
        // TRIANGLE
        float vertices[] = {
            //layout(location = 0)        layout(location = 1)             layout(location = 2)
            -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f,
            0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,
            0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f
        };//

        unsigned indices[] = {
            0, 1, 2, // first triangle
            0, 2, 3  // second triangle
        };

        Bald::Graphics::VertexBufferLayout layout = {
            {0, Bald::Graphics::ShaderBuiltInType::Float, Bald::Graphics::ShaderBuiltInTypeSize::Vec3, "in_Position"},
            {1, Bald::Graphics::ShaderBuiltInType::Float, Bald::Graphics::ShaderBuiltInTypeSize::Vec4, "in_Color"},
            {2, Bald::Graphics::ShaderBuiltInType::Float, Bald::Graphics::ShaderBuiltInTypeSize::Vec2, "in_TexCoord"}
        };

        m_TriangleVBO = Bald::Graphics::VertexBuffer::Create(vertices, sizeof(vertices));
        m_TriangleVBO->SetLayout(layout);

        m_TriangleIBO = Bald::Graphics::IndexBuffer::Create(indices, sizeof(indices));

        m_TriangleVAO = Bald::Graphics::VertexArray::Create();
        m_TriangleVAO->AddVertexBuffer(m_TriangleVBO);
        m_TriangleVAO->AddIndexBuffer(m_TriangleIBO);

        m_Shader = Bald::Graphics::Shader::Create("../engine/res/shaders/basic.vert",
                                                  "../engine/res/shaders/basic.frag");

        m_Texture = Bald::Graphics::Texture::Create("../engine/res/textures/lena.jpg");
        // END OF TRIANGLE
    }

    void OnDetach() noexcept override {}

    void OnUpdate() noexcept override {
        // TRIANGLE
        m_Shader->Bind();
        m_Texture->Bind();
        m_TriangleVAO->Bind();
        glDrawElements(GL_TRIANGLES, static_cast<int32_t>(m_TriangleVAO->GetIndexBuffer()->GetCount()), GL_UNSIGNED_INT, nullptr);
        // END TRIANGLE
    }

    void OnRender() noexcept override {}

private:
    std::shared_ptr<Graphics::VertexArray> m_TriangleVAO = nullptr;
    std::shared_ptr<Graphics::VertexBuffer> m_TriangleVBO = nullptr;
    std::shared_ptr<Graphics::IndexBuffer> m_TriangleIBO = nullptr;
    std::shared_ptr<Graphics::Shader> m_Shader = nullptr;
    std::shared_ptr<Graphics::Texture> m_Texture = nullptr;
};

class Sandbox : public Bald::Application {
GENERATE_BODY(DERIVED)

public:

    Sandbox() {
        PushLayer<GameLayer>();
    }

    ~Sandbox() override = default;

};

Bald::Application* Bald::Application::Create() noexcept {
    return new Sandbox();
}
