//
// Created by ajer on 15.02.19.
//

#include <iostream>
#include "window.h"
#include "input_manager.h"
#include "event_manager.h"
#include "key_events.h"
#include "window_events.h"

using namespace Bald;
using namespace Graphics;

int main() {

    Log::Init();

    Window window("BaldEngine!", 800, 600);

    EventManager::Subscribe<KeyTypedEvent>(HandleType::SYNC, []() { CORE_LOG_TRACE("Key Typed Event!"); });
    EventManager::Subscribe<KeyPressedEvent>(HandleType::SYNC, []() { CORE_LOG_TRACE("Key Pressed Event!"); });
    EventManager::Subscribe<KeyReleasedEvent>(HandleType::SYNC, []() { CORE_LOG_TRACE("Key Released Event!"); });
    EventManager::Subscribe<MouseMovedEvent>(HandleType::ASYNC, []() { CORE_LOG_TRACE("Mouse Moved Event!"); });
    EventManager::Subscribe<MouseScrolledEvent>(HandleType::ASYNC, []() { CORE_LOG_TRACE("Mouse Scrolled Event!"); });
    EventManager::Subscribe<MouseButtonPressedEvent>(HandleType::SYNC, []() { CORE_LOG_TRACE("Mouse Button Pressed Event!"); } );
    EventManager::Subscribe<WindowClosedEvent>(HandleType::SYNC, [&]() {
        CORE_LOG_TRACE("Window Closed Event!");
        glfwSetWindowShouldClose(window.GetWindow(), true);
    });

    while(!window.ShouldClose()) {

        // do stuff

        if (Input::InputManager::IsKeyPressed(GLFW_KEY_ESCAPE)) {
            EventManager::Emit<WindowClosedEvent>();
        }

        window.Update();
        window.Clear();
    }
}