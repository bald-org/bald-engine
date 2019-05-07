//
// Created by grzegorz on 23.12.18.
//

#include "input_manager.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <Log.h>

using namespace Bald;
using namespace Input;

void key_typed_call(const KeyTypedEvent&) {
    std::cout << "key typed callback called\n";
}

void mouse_button_pressed_call(const MouseButtonPressedEvent&) {
    std::cout << "mouse button pressed callback called\n";
}

void mouse_button_typed_call(const MouseButtonTypedEvent&) {
    std::cout << "mouse button typed callback called\n";
}

void key_pressed_call(const KeyPressedEvent&, int i) {
    std::cout << "key pressed callback called " << i << "\n";
}

int main() {
    Log::Init();
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    [[maybe_unused]] int i = 0;
    InputManager::SetKeyPressedCallback(key_pressed_call, std::reference_wrapper(i));
    i++;

    InputManager::SetKeyTypedCallback(key_typed_call);
    InputManager::SetMouseButtonPressedCallback(mouse_button_pressed_call);
    InputManager::SetMouseButtonTypedCallback(mouse_button_typed_call);

    while(!glfwWindowShouldClose(window)) {

        double x, y;
        InputManager::GetMousePos(x, y);

        if(InputManager::IsKeyPressed(GLFW_KEY_SPACE)) {
            std::cout << "SPACE PRESSED\n";
        }

        if(InputManager::IsKeyTyped(GLFW_KEY_S)) {
            std::cout << "S TYPED\n";
        }

        if(InputManager::IsMouseButtonPressed(GLFW_MOUSE_BUTTON_1)) {
            std::cout << "MOUSE BUTTON PRESSED (" << x << ", " << y << ")\n";
        }

        if(InputManager::IsMouseButtonTyped(GLFW_MOUSE_BUTTON_2)) {
            std::cout << "MOUSE BUTTON TYPED (" << x << ", " << y << ")\n";
        }

        if(InputManager::IsKeyPressed(GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(window, true);
        }


        InputManager::Update();
        EventManager::Flush();
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    InputManager::EmitKeyPressedEvent(GLFW_KEY_Q);
    InputManager::EmitKeyTypedEvent(GLFW_KEY_Q);
    InputManager::EmitMouseButtonPressedEvent(GLFW_MOUSE_BUTTON_1);
    InputManager::EmitMouseButtonPressedEvent(GLFW_MOUSE_BUTTON_3);
    InputManager::EmitMouseButtonTypedEvent(GLFW_MOUSE_BUTTON_4);

    EventManager::Flush();

    EventManager::CleanUp();
    glfwDestroyWindow(window);

    return 0;
}