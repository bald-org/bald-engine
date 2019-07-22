//
// Created by grzegorz on 16.12.18.
//

#include "core/pch.h"
#include "gtest/gtest.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

TEST(GLFW_GLAD, GLFW_GLAD_Initialization) {

    EXPECT_EQ(glfwInit(), GLFW_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);
    EXPECT_FALSE(window == NULL);

    EXPECT_EQ(gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)), true);

    glfwDestroyWindow(window);
}
