//
// Created by grzegorz on 17.12.18.
//

#include "pch.h"
#include "gtest/gtest.h"

#include "input_manager.h"

TEST(InputManager, initialization){
    using namespace Bald;
    using namespace Input;
    EXPECT_EQ(InputManager::isKeyPressed(GLFW_KEY_SPACE), false);
    EXPECT_EQ(InputManager::isKeyTyped(GLFW_KEY_1), false);
    EXPECT_EQ(InputManager::isMouseButtonPressed(GLFW_MOUSE_BUTTON_1), false);
    EXPECT_EQ(InputManager::isMouseButtonTyped(GLFW_MOUSE_BUTTON_2), false);
}

// TODO: test callbacks

