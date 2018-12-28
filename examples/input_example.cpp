//
// Created by grzegorz on 23.12.18.
//

#include "input_manager.h"
#include "GLFW/glfw3.h"
#include <iostream>

using namespace Bald;
using namespace Input;

int main() {
    glfwInit();

    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

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