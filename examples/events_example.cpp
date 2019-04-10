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

int main() {

    using namespace Bald;
    using namespace Input;

    glfwInit();

    GLFWwindow *window = glfwCreateWindow(800, 600, "BaldEngine", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    Log::Init();

    EventManager::Subscribe<KeyTypedEvent>(HandleType::SYNC, [](){ std::cout << "KeyTypedEvent!\n"; });
    while (!glfwWindowShouldClose(window)) {

        InputManager::Update();
        EventManager::Flush();

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    EventManager::CleanUp();

    glfwDestroyWindow(window);

    return 0;
}