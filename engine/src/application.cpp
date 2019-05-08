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

        // TODO: This subscribes are temporary, because we still have no layers ~Blinku
        EventManager::Subscribe<KeyTypedEvent>(HandleType::SYNC, [](const KeyTypedEvent&) { CORE_LOG_TRACE("Key Typed Event!"); });
        EventManager::Subscribe<KeyPressedEvent>(HandleType::SYNC, [](const KeyPressedEvent&) { CORE_LOG_TRACE("Key Pressed Event!"); });
        EventManager::Subscribe<KeyReleasedEvent>(HandleType::SYNC, [](const KeyReleasedEvent&) { CORE_LOG_TRACE("Key Released Event!"); });
        EventManager::Subscribe<MouseMovedEvent>(HandleType::ASYNC, [](const MouseMovedEvent&) { CORE_LOG_TRACE("Mouse Moved Event!"); });
        EventManager::Subscribe<MouseScrolledEvent>(HandleType::ASYNC, [](const MouseScrolledEvent&) { CORE_LOG_TRACE("Mouse Scrolled Event!"); });
        EventManager::Subscribe<MouseButtonPressedEvent>(HandleType::SYNC, [](const MouseButtonPressedEvent&) { CORE_LOG_TRACE("Mouse Button Pressed Event!"); } );
        EventManager::Subscribe<WindowClosedEvent>(HandleType::SYNC, [&](const WindowClosedEvent&) {
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

} // END OF NAMESPACE BALD


