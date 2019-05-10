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

            // TODO: Update layer stack here

            m_Window->Update();
            Input::InputManager::Update(); // TODO: This should probably be called on layer update ~Blinku
            EventManager::ClearEventQueue();
        }
    }

    bool Application::Init() noexcept {
        Log::Init();

        CORE_LOG_INFO("[Application] Initializing application...");

        assert(!m_Instance);

        m_Instance = this;

        m_EventManager = std::make_unique<EventManager>();
        m_Window = std::make_unique<Graphics::Window>("Bald Engine");

        CORE_LOG_INFO("[Application] Initialization was successful");

        return true;
    }

    void Application::Shutdown() {
        CORE_LOG_INFO("[Application] Shutting down application...");
        // Currently does nothing, later on will clear LayerStack.
        CORE_LOG_INFO("[Application] Shutdown was successful");
    }

} // END OF NAMESPACE BALD


