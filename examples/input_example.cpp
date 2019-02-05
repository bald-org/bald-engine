//
// Created by grzegorz on 23.12.18.
//

#include "input_manager.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <Log.h>

using namespace Bald;
using namespace Input;

void key_pressed_call(int i){
    std::cout << "key pressed callback called " << i << "\n";
}

void key_typed_call(){
    std::cout << "key typed callback called\n";
}

void mouse_button_pressed_call(){
    std::cout << "mouse button pressed callback called\n";
}

void mouse_button_typed_call(){
    std::cout << "mouse button typed callback called\n";
}

int main() {
    glfwInit();

    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    InputManager::Init();
    Log::Init();

    InputManager::SetKeyPressedCallback(GLFW_KEY_A, key_pressed_call, 1);
    InputManager::SetKeyTypedCallback(GLFW_KEY_Q, key_typed_call);
    InputManager::SetMouseButtonPressedCallback(GLFW_MOUSE_BUTTON_3, mouse_button_pressed_call);
    InputManager::SetMouseButtonTypedCallback(GLFW_MOUSE_BUTTON_4, mouse_button_typed_call);

    while (!glfwWindowShouldClose(window)) {

        double x,y;
        InputManager::getMousePos(x, y);

        if (InputManager::isKeyPressed(GLFW_KEY_SPACE)) {
            std::cout << "SPACE PRESSED\n";
        }

        if (InputManager::isKeyTyped(GLFW_KEY_S)){
            std::cout << "S TYPED\n";
        }

        if (InputManager::isMouseButtonPressed(GLFW_MOUSE_BUTTON_1)){
            std::cout << "MOUSE BUTTON PRESSED (" << x << ", " << y << ")\n";
        }

        if (InputManager::isMouseButtonTyped(GLFW_MOUSE_BUTTON_2)){
            std::cout << "MOUSE BUTTON TYPED (" << x << ", " << y << ")\n";
        }

        glfwPollEvents();
        glfwSwapBuffers(window);
        InputManager::Update();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

}