//
// Created by grzegorz on 16.12.18.
//

#include "pch.h"
#include "gtest/gtest.h"

#include "GLFW/glfw3.h"

TEST(GLFW, GLFW_Initialization){
    EXPECT_EQ(glfwInit(), GLFW_TRUE);
    glfwTerminate();
}