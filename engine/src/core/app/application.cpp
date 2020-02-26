//
// Created by blinku on 06.05.19.
//

#include "application.hpp"
#include "input/input_manager.hpp"
#include "events/window_events.hpp"
#include "events/layer_events.hpp"
#include "debug/ui/imgui_layer.hpp"
#include "graphics/rendering/rendering_device/renderer_2d.hpp"
#include <GLFW/glfw3.h>

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
        Models::Timer timer;
        timer.Start();
#endif

        while(m_Running) {
            m_Window->Clear();

#ifdef TRAVIS
            if(timer.ElapsedSeconds() > 1.0f){
                Events::EventBus::Emit<Events::WindowClosedEvent>();
            }
#endif

            float deltaTime = m_TimeController.GetDeltaTimeInMicroseconds();
            for(size_t i = 0; i < m_LayerStack.GetSize(); ++i) {
                m_LayerStack[i]->OnUpdate(deltaTime);
            }

            Debug::ImGuiLayer::Begin();
            for(size_t i = 0; i < m_LayerStack.GetSize(); ++i) {
                m_LayerStack[i]->OnRender();
            }
            Debug::ImGuiLayer::End();

            Input::InputManager::Update();
            m_Window->Update();
        }
    }

    bool Application::Init() noexcept {
        CORE_LOG_INFO("[Application] Initializing application...");

        BALD_ASSERT(m_Instance == nullptr, "Application", "Instance of Application already initialized", m_Instance);

        m_Instance = this;

        m_Window = std::make_unique<Graphics::Window>("Bald Engine", 1280, 720, false);

        Events::EventBus::Subscribe<Events::WindowClosedEvent>([this](const Events::WindowClosedEvent&) {
            glfwSetWindowShouldClose(m_Window->GetWindow(), true);
            this->m_Running = false;
        });

        Events::EventBus::Subscribe<Events::LayerPushedEvent>([this](const Events::LayerPushedEvent&) {
            m_LayerStack.AttachLayers();
        });

        Events::EventBus::Subscribe<Events::LayerPoppedEvent>([this](const Events::LayerPoppedEvent&) {
            m_LayerStack.DetachLayers();
        });

        PushOverlayImmediately<Debug::ImGuiLayer>();

        Graphics::Renderer2D::Init();

        CORE_LOG_INFO("[Application] Initialization was successful");

        return true;
    }

    void Application::Shutdown() {
        CORE_LOG_INFO("[Application] Shutting down application...");
        Graphics::Renderer2D::Shutdown();
        CORE_LOG_INFO("[Application] Shutdown was successful");
    }

} // END OF NAMESPACE Bald
