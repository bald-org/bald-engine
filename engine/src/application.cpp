//
// Created by blinku on 06.05.19.
//

#include "application.h"
#include "input_manager.h"
#include "event_manager.h"
#include "window_events.h"
#include "pch.h"

namespace Bald {

    const Application* Application::m_Instance{nullptr};

    Application::Application() : m_Running(true) {
        assert(Init());
    }

    Application::~Application() {
        Shutdown();
    }

    void Application::Run() {

        // TODO: This subscribes are temporary, because we still have no layers ~Blinku
        EventManager::Subscribe<KeyTypedEvent>(HandleType::SYNC, []() { CORE_LOG_TRACE("Key Typed Event!"); });
        EventManager::Subscribe<KeyPressedEvent>(HandleType::SYNC, []() { CORE_LOG_TRACE("Key Pressed Event!"); });
        EventManager::Subscribe<KeyReleasedEvent>(HandleType::SYNC, []() { CORE_LOG_TRACE("Key Released Event!"); });
        EventManager::Subscribe<MouseMovedEvent>(HandleType::ASYNC, []() { CORE_LOG_TRACE("Mouse Moved Event!"); });
        EventManager::Subscribe<MouseScrolledEvent>(HandleType::ASYNC, []() { CORE_LOG_TRACE("Mouse Scrolled Event!"); });
        EventManager::Subscribe<MouseButtonPressedEvent>(HandleType::SYNC, []() { CORE_LOG_TRACE("Mouse Button Pressed Event!"); } );
        EventManager::Subscribe<WindowClosedEvent>(HandleType::SYNC, [&]() {
            CORE_LOG_TRACE("Window Closed Event!");
            glfwSetWindowShouldClose(m_Window->GetWindow(), true);
            m_Running = false;
        });

        while(m_Running) {

            m_Window->Clear();

            if (Input::InputManager::IsKeyPressed(GLFW_KEY_ESCAPE)) {
                EventManager::Emit<WindowClosedEvent>();
            }

            Input::InputManager::Update(); // TODO: This should probably be called on layer update ~Blinku
            EventManager::Flush(); // TODO: This should probably be called on layer update ~Blinku

            m_Window->Update();

        }
    }

    bool Application::Init() noexcept {
        Log::Init();

        CORE_LOG_INFO("[Application] Initializing application...");

        if(m_Instance) {
            CORE_LOG_ERROR("[Application] Application is a singleton, meaning it can only be created once in the entire program");
            return false;
        }

        m_Instance = this;

        m_Window = std::make_unique<Graphics::Window>("Bald Engine");

        CORE_LOG_INFO("[Application] Initialization was successful");

        return true;
    }

    void Application::Shutdown() const {
        CORE_LOG_INFO("[Application] Shutting down application...");

        EventManager::CleanUp(); // TODO: Maybe after layer update? We will have to discuss this

        CORE_LOG_INFO("[Application] Shutdown was successful");
    }

} // END OF NAMESPACE BALD


