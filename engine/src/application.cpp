//
// Created by blinku on 06.05.19.
//

#include "application.h"

#include "input_manager.h"

#include "window_events.h"

namespace Bald {

    const Application* Application::m_Instance = nullptr;

    Application::Application() : m_Running(true) {
        bool state = Init();
        assert(state);
    }

    Application::~Application() {
        Shutdown();
    }

    void Application::Run() {

        while(m_Running) {

            m_Window->Clear();

            for(auto layer : m_LayerStack)
            {
                layer->Update();
                layer->RunEvents();
            }

            Input::InputManager::Update(); // TODO: Let's think whether or not this should be called during layer update! ~Blinku

            m_Window->Update();

        }
    }

    bool Application::Init() {
        assert(!m_Instance);

        m_Instance = this;

        Log::Init();

        m_Window = std::make_unique<Graphics::Window>("Bald Engine");

        EventManager::Subscribe<WindowClosedEvent>(HandleType::SYNC, [this]() {
            glfwSetWindowShouldClose(m_Window.get()->GetWindow(), true);
            this->m_Running = false;
        });
    }

    void Application::Shutdown() {
        for(auto layer : m_LayerStack) {
            delete layer;
        }

        EventManager::CleanUp(); // TODO: Maybe after layer update? We will have to discuss this
    }

} // END OF NAMESPACE BALD


