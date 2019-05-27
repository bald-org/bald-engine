//
// Created by blinku on 06.05.19.
//

#include "application.h"
#include "input_manager.h"
#include "window_events.h"
#include "layer_events.h"
#include "utils/timer.h"

namespace Bald {

    Application* Application::m_Instance = nullptr;

    Application::Application() : m_Running(true) {
        [[maybe_unused]] bool state = Init();
        assert(state);
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

#ifdef TRAVIS
            if(timer.ElapsedSeconds() > 1.0){
                EventManager::Emit<WindowClosedEvent>();
            }
#endif

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

    Application& Application::GetApplication() noexcept {
        return *m_Instance;
    }

    bool Application::Init() noexcept {
        CORE_LOG_INFO("[Application] Initializing application...");

        assert(!m_Instance);

        m_Instance = this;

        m_EventManager = std::make_unique<EventManager>();
        m_Window = std::make_unique<Graphics::Window>("Bald Engine");

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


        CORE_LOG_INFO("[Application] Initialization was successful");

        return true;
    }

    void Application::Shutdown() {
        CORE_LOG_INFO("[Application] Shutting down application...");
        CORE_LOG_INFO("[Application] Shutdown was successful");
    }

} // END OF NAMESPACE Bald
