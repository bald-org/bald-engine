//
// Created by blinku on 07.05.19.
//

#include "bald.h"

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

        Graphics::VertexBufferLayout layout = {
            {0, Graphics::ShaderBuiltInType::Float, Graphics::ShaderBuiltInTypeSize::Vec3, "in_Position"},
            {1, Graphics::ShaderBuiltInType::Float, Graphics::ShaderBuiltInTypeSize::Vec4, "in_Color"},
            {2, Graphics::ShaderBuiltInType::Float, Graphics::ShaderBuiltInTypeSize::Vec2, "in_TexCoord"}
        };

        m_TriangleVBO = Graphics::VertexBuffer::Create(vertices, sizeof(vertices));
        m_TriangleVBO->SetLayout(layout);

        m_TriangleIBO = Graphics::IndexBuffer::Create(indices, sizeof(indices));

        m_TriangleVAO = Graphics::VertexArray::Create();
        m_TriangleVAO->AddVertexBuffer(m_TriangleVBO);
        m_TriangleVAO->AddIndexBuffer(m_TriangleIBO);

        m_Shader = Graphics::Shader::Create("../engine/res/shaders/basic.vert",
                                                  "../engine/res/shaders/basic.frag");

        m_Texture = Graphics::Texture::Create("../engine/res/textures/lena.jpg");
        // END OF TRIANGLE
    }

    void OnDetach() noexcept override {}

    void OnUpdate() noexcept override {
        if(Bald::Input::InputManager::IsKeyPressed(BALD_KEY_A)) {
            m_Position.x -= m_CameraSpeed;
        } else if(Bald::Input::InputManager::IsKeyPressed(BALD_KEY_D)) {
            m_Position.x += m_CameraSpeed;
        }

        if(Bald::Input::InputManager::IsKeyPressed(BALD_KEY_W)) {
            m_Position.y += m_CameraSpeed;
        } else if(Bald::Input::InputManager::IsKeyPressed(BALD_KEY_S)) {
            m_Position.y -= m_CameraSpeed;
        }

        // TRIANGLE
        m_Camera.SetPosition(m_Position);
        m_Shader->SetUniformMatrix4fv("u_ProjectionView", m_Camera.GetProjectionViewMatrix());
        m_Shader->Bind();
        m_Texture->Bind();
        m_TriangleVAO->Bind();
        glDrawElements(GL_TRIANGLES, static_cast<int32_t>(m_TriangleVAO->GetIndexBuffer()->GetCount()), GL_UNSIGNED_INT,
                       nullptr);
        // END TRIANGLE
    }

    void OnRender() noexcept override {}

private:
private:
    std::shared_ptr<Graphics::VertexArray> m_TriangleVAO = nullptr;
    std::shared_ptr<Graphics::VertexBuffer> m_TriangleVBO = nullptr;
    std::shared_ptr<Graphics::IndexBuffer> m_TriangleIBO = nullptr;
    std::shared_ptr<Graphics::Shader> m_Shader = nullptr;
    std::shared_ptr<Graphics::Texture> m_Texture = nullptr;

    Graphics::Camera2D m_Camera;
    float m_CameraSpeed = 0.005f;
    glm::vec2 m_Position{0.0f};
};

class Sandbox : public Application {
GENERATE_BODY(DERIVED)

public:

    Sandbox() {
        PushLayer<GameLayer>();
    }

    ~Sandbox() override = default;

};

Application* Application::Create() noexcept {
    return new Sandbox();
}
