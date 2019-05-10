//
// Created by blinku on 06.05.19.
//

#include "application.h"

#include "input_manager.h"

#include "window_events.h"

namespace Bald {

    const Application* Application::m_Instance = nullptr;

    Application::Application() : m_Running(true) {
        [[maybe_unused]] bool state = Init();
        assert(state);
    }

    Application::~Application() {
        Shutdown();
    }

    void Application::Run() {

        while(m_Running) {
            m_Window->Clear();

            for(auto it = m_LayerStack.begin(); it != m_LayerStack.end(); ++it) {
                (*it)->OnUpdate();
            }

            for(auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
                (*--it)->RunEvents();
            }

            m_EventManager->Flush();

            EventManager::ClearEventQueue();

            Input::InputManager::Update();

            m_Window->Update();
        }
    }

    bool Application::Init() noexcept {
        Log::Init();

        CORE_LOG_INFO("[Application] Initializing Application...");

        assert(!m_Instance);

        m_Instance = this;

        m_EventManager = std::make_unique<EventManager>();
        m_Window = std::make_unique<Graphics::Window>("Bald Engine");

        m_EventManager->Subscribe<WindowClosedEvent>(HandleType::SYNC, [this](const WindowClosedEvent&) {
            glfwSetWindowShouldClose(m_Window->GetWindow(), true);
            this->m_Running = false;
        });

        CORE_LOG_INFO("[Application] Initialization was successful");

        return true;
    }

    void Application::Shutdown() {
        CORE_LOG_INFO("[Application] Shutting down application...");

        for(Layer* layer : m_LayerStack) {
            delete layer;
        }

        CORE_LOG_INFO("[Application] Shutdown was successful");
    }

} // END OF NAMESPACE Bald



