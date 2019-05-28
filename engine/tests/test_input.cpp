//
// Created by grzegorz on 17.12.18.
//

#include "core/pch.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "input_manager.h"


TEST(InputManager, initialization) {
    using namespace Bald;
    using namespace Input;

    EXPECT_FALSE(InputManager::IsKeyPressed(GLFW_KEY_SPACE));
    EXPECT_FALSE(InputManager::IsKeyTyped(GLFW_KEY_1));
    EXPECT_FALSE(InputManager::IsMouseButtonPressed(GLFW_MOUSE_BUTTON_1));
    EXPECT_FALSE(InputManager::IsMouseButtonTyped(GLFW_MOUSE_BUTTON_2));
}

TEST(InputManager, callback) {
    using namespace Bald;
    using namespace Input;

    glfwInit();

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);

    EXPECT_THAT(glfwSetMouseButtonCallback(window, mouse_button_callback), nullptr);
    EXPECT_THAT(glfwSetCursorPosCallback(window, cursor_position_callback), nullptr);
    EXPECT_THAT(glfwSetKeyCallback(window, key_callback), nullptr);


    glfwDestroyWindow(window);
}

