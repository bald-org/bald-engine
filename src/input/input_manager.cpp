//
// Created by grzegorz on 17.12.18.
//

#include "input_manager.h"
#include "pch.h"

namespace Bald::Input{

    bool InputManager::m_Keys[MAX_KEYS];
    bool InputManager::m_KeysState[MAX_KEYS];
    bool InputManager::m_KeysTyped[MAX_KEYS];
    bool InputManager::m_MouseButtons[MAX_MOUSE_BUTTONS];
    bool InputManager::m_MouseButtonsState[MAX_MOUSE_BUTTONS];
    bool InputManager::m_MouseButtonsTyped[MAX_MOUSE_BUTTONS];

    void key_callback([[maybe_unused]] GLFWwindow *window, int key,[[maybe_unused]] int scancode, int action,[[maybe_unused]] int mods) {
        InputManager::m_Keys[key] = action != GLFW_RELEASE;
    }

    void mouse_button_callback([[maybe_unused]] GLFWwindow *window, int button, int action,[[maybe_unused]] int mods) {
        InputManager::m_MouseButtons[button] = action != GLFW_RELEASE;
    }

    void InputManager::Update() {

        for(int i = 0; i < MAX_KEYS; i++) m_KeysTyped[i] = !m_KeysState[i] && m_Keys[i];
        for(int i = 0; i < MAX_MOUSE_BUTTONS; i++) m_MouseButtonsTyped[i] = !m_MouseButtonsState[i] && m_MouseButtons[i];

        std::memcpy(m_KeysState, m_Keys, MAX_KEYS);
        std::memcpy(m_MouseButtonsState, m_MouseButtons, MAX_MOUSE_BUTTONS);
    }

}
