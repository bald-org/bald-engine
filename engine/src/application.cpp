//
// Created by blinku on 06.05.19.
//

#include "application.h"
#include "input_manager.h"
#include "event_manager.h"
#include "window_events.h"

namespace Bald {

    const Application* Application::m_Instance = nullptr;

    Application::Application() : m_Running(true) {
        assert(!m_Instance);

        m_Instance = this;

        Log::Init();

        m_Window = std::make_unique<Graphics::Window>("Bald Engine");
    }

    Application::~Application() {
        EventManager::CleanUp(); // TODO: Maybe after layer update? We will have to discuss this
    }

    void Application::Run() {

        while(m_Running) {

            m_Window->Clear();

            Input::InputManager::Update(); // TODO: This should probably be called on layer update ~Blinku
            EventManager::Flush(); // TODO: This should probably be called on layer update ~Blinku

            m_Window->Update();

        }
    }

} // END OF NAMESPACE BALD


