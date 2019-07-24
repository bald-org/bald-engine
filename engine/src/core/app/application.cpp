//
// Created by blinku on 06.05.19.
//

#include "application.h"
#include "input/input_manager.h"
#include "events/window_events.h"
#include "events/layer_events.h"
#include "utils/timer.h"
#include "debug/ui/imgui_layer.h"

// TRIANGLE
#include "graphics/rendering/buffers/vertex_buffer_layout.h"
// END TRIANGLE

namespace Bald {

    Application* Application::m_Instance = nullptr;

    Application::Application() : m_Running(true) {
        [[maybe_unused]] bool state = Init();
        BALD_ASSERT(state, "Application", "Failed to initialized application", state);
    }

    Application::~Application() {
        Shutdown();
    }

    void Application::Run() {

#ifdef TRAVIS
        Utils::Timer timer;
        timer.Start();
#endif

        while(m_Running) {
            m_Window->Clear();

            // TRIANGLE
            m_RedShader->Bind();
            m_TriangleVAO->Bind();
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
            // END TRIANGLE

#ifdef TRAVIS
            if(timer.ElapsedSeconds() > 1.0){
                EventManager::Emit<WindowClosedEvent>();
            }
#endif

            Debug::ImGuiLayer::Begin();
            for(size_t i = 0; i < m_LayerStack.GetSize(); ++i) {
                m_LayerStack[i]->OnRender();
            }
            Debug::ImGuiLayer::End();

            for(size_t i = 0; i < m_LayerStack.GetSize(); ++i) {
                m_LayerStack[i]->OnUpdate();
            }

            for(size_t i = m_LayerStack.GetSize(); i != 0; --i) {
                m_LayerStack[i - 1]->RunEvents();
            }

            m_EventManager->Flush();
            EventManager::ClearEventQueue();

            Input::InputManager::Update();
            m_Window->Update();
        }
    }

    bool Application::Init() noexcept {
        CORE_LOG_INFO("[Application] Initializing application...");

        BALD_ASSERT(m_Instance == nullptr, "Application", "Instance of Application already initialized", m_Instance);

        m_Instance = this;

        m_EventManager = std::make_unique<EventManager>();
        m_Window = std::make_unique<Graphics::Window>("Bald Engine", 1280, 720);

        m_EventManager->Subscribe<WindowClosedEvent>(HandleType::SYNC, [this](const WindowClosedEvent&) {
            glfwSetWindowShouldClose(m_Window->GetWindow(), true);
            this->m_Running = false;
        });

        m_EventManager->Subscribe<LayerPushedEvent>(HandleType::SYNC, [this](const LayerPushedEvent&) {
            m_LayerStack.AttachLayers();
        });

        m_EventManager->Subscribe<LayerPoppedEvent>(HandleType::SYNC, [this](const LayerPoppedEvent&) {
            m_LayerStack.DetachLayers();
        });

        PushOverlayImmediately<Debug::ImGuiLayer>();

        CORE_LOG_INFO("[Application] Initialization was successful");

        // TRIANGLE
        float vertices[] = {
            //layout(location = 0)       layout(location = 1)
            -0.5f, -0.5f, 0.0f,          1.0f, 0.0f, 0.0f, 1.0f,
            -0.5f,  0.5f, 0.0f,          0.0f, 1.0f, 0.0f, 1.0f,
             0.5f,  0.5f, 0.0f,          0.0f, 0.0f, 1.0f, 1.0f,
             0.5f, -0.5f, 0.0f,          1.0f, 1.0f, 1.0f, 1.0f
        };

        unsigned indices[] = {
            0, 1, 2, // first triangle
            0, 2, 3  // second triangle
        };

        Graphics::VertexBufferLayout layout = {
            {0, Graphics::ShaderBuiltInType::Vec3f, "in_Position"},
            {1, Graphics::ShaderBuiltInType::Vec4f, "in_Color"}
        };

        m_TriangleVBO = Graphics::VertexBuffer::Create(vertices, sizeof(vertices));
        m_TriangleVBO->SetLayout(layout);

        m_TriangleIBO = Graphics::IndexBuffer::Create(indices, sizeof(indices));

        m_TriangleVAO = Graphics::VertexArray::Create();
        m_TriangleVAO->AddVertexBuffer(m_TriangleVBO);
        m_TriangleVAO->AddIndexBuffer(m_TriangleIBO);

        m_RedShader = Graphics::Shader::Create("../engine/res/shaders/basic.vert", "../engine/res/shaders/basic.frag");
        // END OF TRIANGLE

        return true;
    }

    void Application::Shutdown() {
        CORE_LOG_INFO("[Application] Shutting down application...");
        CORE_LOG_INFO("[Application] Shutdown was successful");
    }

} // END OF NAMESPACE Bald
