//
// Created by grzegorz on 17.12.18.
//

#pragma once

#include "GLFW/glfw3.h"

#define MAX_KEYS 1024
#define MAX_MOUSE_BUTTONS 32

// TODO: Documentation and Logging errors
// TODO: consider mouse storing mouse position in this class instead of in Window

namespace Bald::Input {

    class InputManager {
        friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    public:
        static void Update();
        [[nodiscard]] inline static bool isKeyPressed(int keycode) noexcept;
        [[nodiscard]] inline static bool isKeyTyped(int keycode) noexcept;
        [[nodiscard]] inline static bool isMouseButtonPressed(int buttoncode) noexcept;
        [[nodiscard]] inline static bool isMouseButtonTyped(int buttoncode) noexcept;
    private:
        static bool m_Keys[MAX_KEYS];
        static bool m_KeysState[MAX_KEYS];
        static bool m_KeysTyped[MAX_KEYS];
        static bool m_MouseButtons[MAX_MOUSE_BUTTONS];
        static bool m_MouseButtonsState[MAX_MOUSE_BUTTONS];
        static bool m_MouseButtonsTyped[MAX_MOUSE_BUTTONS];
    };

    bool InputManager::isKeyPressed(int keycode) noexcept {
        if(keycode >= MAX_KEYS) return false;
        return m_Keys[keycode];
    }

    bool InputManager::isKeyTyped(int keycode) noexcept {
        if(keycode >= MAX_KEYS) return false;
        return m_KeysTyped[keycode];
    }

    bool InputManager::isMouseButtonPressed(int buttoncode) noexcept {
        if(buttoncode >= MAX_MOUSE_BUTTONS) return false;
        return m_MouseButtons[buttoncode];
    }

    bool InputManager::isMouseButtonTyped(int buttoncode) noexcept {
        if(buttoncode >= MAX_MOUSE_BUTTONS) return false;
        return m_MouseButtonsTyped[buttoncode];
    }

}
//BALD_ENGINE_INPUT_MANAGER_H
