//
// Created by ajer on 15.02.19.
//

#include <iostream>
#include "window.h"
#include <input_manager.h>
#include "event_manager.h"
#include "key_events.h"
#include "window_events.h"

using namespace Bald;
using namespace Graphics;

int main() {

    Log::Init();

    Window window("BaldEngine!", 800, 600);

    EventManager::Subscribe<KeyTypedEvent>(HandleType::SYNC, []() { CORE_LOG_INFO("Key Typed Event!"); });
    EventManager::Subscribe<MouseMovedEvent>(HandleType::ASYNC, []() { CORE_LOG_INFO("Mouse Moved Event!"); });
    EventManager::Subscribe<MouseButtonPressedEvent>(HandleType::SYNC, []() { CORE_LOG_INFO("Mouse Button Pressed Event!"); } );
    EventManager::Subscribe<WindowClosedEvent>(HandleType::ASYNC, [&]() {
        glfwSetWindowShouldClose(window.GetWindow(), true);
    });

    while(!window.ShouldClose()) {

        // do stuff

        if (Input::InputManager::IsKeyTyped(GLFW_KEY_ESCAPE)) {
            EventManager::Emit<WindowClosedEvent>();
        }

        window.Update();
        window.Clear();
    }
}