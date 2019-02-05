//
// Created by grzegorz on 17.12.18.
//

#include "input_manager.h"
#include "pch.h"

namespace Bald::Input {

    double InputManager::m_MouseX = 0.0;
    double InputManager::m_MouseY = 0.0;
    bool InputManager::m_Keys[MAX_KEYS];
    bool InputManager::m_KeysState[MAX_KEYS];
    bool InputManager::m_KeysTyped[MAX_KEYS];
    bool InputManager::m_MouseButtons[MAX_MOUSE_BUTTONS];
    bool InputManager::m_MouseButtonsState[MAX_MOUSE_BUTTONS];
    bool InputManager::m_MouseButtonsTyped[MAX_MOUSE_BUTTONS];
    callback InputManager::m_KeyPressedCallbacks[MAX_KEYS];
    callback InputManager::m_KeyTypedCallbacks[MAX_KEYS];
    callback InputManager::m_MouseButtonPressedCallbacks[MAX_MOUSE_BUTTONS];
    callback InputManager::m_MouseButtonTypedCallbacks[MAX_MOUSE_BUTTONS];

    void InputManager::Init() {
        std::fill(m_KeyPressedCallbacks, m_KeyPressedCallbacks + MAX_KEYS - 1, []() {});
        std::memcpy(m_KeyTypedCallbacks, m_KeyPressedCallbacks, MAX_KEYS * sizeof(m_KeyPressedCallbacks[0]));
        std::fill(m_MouseButtonPressedCallbacks, m_MouseButtonPressedCallbacks + MAX_MOUSE_BUTTONS - 1, []() {});
        std::memcpy(m_MouseButtonTypedCallbacks, m_MouseButtonPressedCallbacks, MAX_MOUSE_BUTTONS * sizeof(m_MouseButtonPressedCallbacks[0]));
    }

    void InputManager::Update() noexcept {

        for (int i = 0; i < MAX_KEYS; i++) {
            m_KeysTyped[i] = !m_KeysState[i] && m_Keys[i];
            if (m_Keys[i]) m_KeyPressedCallbacks[i]();
            if (m_KeysTyped[i]) m_KeyTypedCallbacks[i]();
        }

        for (int i = 0; i < MAX_MOUSE_BUTTONS; i++) {
            m_MouseButtonsTyped[i] = !m_MouseButtonsState[i] && m_MouseButtons[i];
            if (m_MouseButtons[i]) m_MouseButtonPressedCallbacks[i]();
            if (m_MouseButtonsTyped[i]) m_MouseButtonTypedCallbacks[i]();
        }

        std::memcpy(m_KeysState, m_Keys, MAX_KEYS * sizeof(m_Keys[0]));
        std::memcpy(m_MouseButtonsState, m_MouseButtons, MAX_MOUSE_BUTTONS * sizeof(m_MouseButtons[0]));

    }

}
