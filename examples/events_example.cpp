//
// Created by blinku on 02.04.19.
//

#include <iostream>
#include "input_manager.h"
#include "GLFW/glfw3.h"
#include "mouse_events.h"
#include "key_events.h"
#include "window_events.h"
#include "event_manager.h"
#include "interface_impl.h"

int main() {

    using namespace Bald;
    using namespace Input;

    Log::Init();
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(800, 600, "BaldEngine", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    EventManager::Subscribe<KeyPressedEvent>(HandleType::SYNC, [](const KeyPressedEvent&){ std::cout << "KeyPressedEvent!\n"; });
    //unsigned id = EventManager::Subscribe<KeyTypedEvent>(HandleType::SYNC, [](){ std::cout << "KeyTypedEvent!\n"; });
    EventManager::Subscribe<MouseMovedEvent>(HandleType::ASYNC, [](const MouseMovedEvent&){ std::cout << "KeyMovedEvent!\n"; });
    EventManager::Subscribe<KeyEvent>(HandleType::SYNC, [](const KeyEvent&){ std::cout << "KeyEvent!\n"; });
    while (!glfwWindowShouldClose(window)) {

        InputManager::Update();
        EventManager::Flush();

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

//    EventManager::Unsubscibe<KeyTypedEvent>(id);
    EventManager::Emit<KeyTypedEvent>(GLFW_KEY_ESCAPE);
    EventManager::Flush();

    EventManager::Subscribe<KeyTypedEvent>( HandleType::SYNC, [](const KeyTypedEvent&){ std::cout << "After Unsubscribe!\n"; });
    EventManager::Emit<KeyTypedEvent>(GLFW_KEY_ESCAPE);

    EventManager::Flush();
    EventManager::CleanUp();

    glfwDestroyWindow(window);

    return 0;
}
