//
// Created by grzegorz on 17.12.18.
//

#include "input_manager.h"
#include "pch.h"

namespace Bald::Input {

    std::pair<double, double> InputManager::m_MousePos;
    std::pair<double, double> InputManager::m_MouseOff;
    bool InputManager::m_Keys[MAX_KEYS];
    bool InputManager::m_KeysState[MAX_KEYS];
    bool InputManager::m_KeysTyped[MAX_KEYS];
    bool InputManager::m_MouseButtons[MAX_MOUSE_BUTTONS];
    bool InputManager::m_MouseButtonsState[MAX_MOUSE_BUTTONS];
    bool InputManager::m_MouseButtonsTyped[MAX_MOUSE_BUTTONS];

    void InputManager::Update() noexcept {

        for(int i = 0; i < MAX_KEYS; i++) {
            m_KeysTyped[i] = !m_KeysState[i] && m_Keys[i];
        }

        for(int i = 0; i < MAX_MOUSE_BUTTONS; i++) {
            m_MouseButtonsTyped[i] = !m_MouseButtonsState[i] && m_MouseButtons[i];
        }

        std::memcpy(m_KeysState, m_Keys, MAX_KEYS * sizeof(m_Keys[0]));
        std::memcpy(m_MouseButtonsState, m_MouseButtons, MAX_MOUSE_BUTTONS * sizeof(m_MouseButtons[0]));
    }

    void InputManager::EmitKeyPressedEvent(int keycode) noexcept {
        if(keycode >= MAX_KEYS) CORE_LOG_WARN("[InputManager] Wrong key id");
        else Bald::EventManager::Emit<KeyPressedEvent>(keycode);
    }

    void InputManager::EmitKeyTypedEvent(int keycode) noexcept {
        if(keycode >= MAX_KEYS) CORE_LOG_WARN("[InputManager] Wrong key id");
        else Bald::EventManager::Emit<KeyTypedEvent>(keycode);
    }

    void InputManager::EmitKeyReleasedEvent(int keycode) noexcept {
        if(keycode >= MAX_KEYS) CORE_LOG_WARN("[InputManager] Wrong key id");
        else Bald::EventManager::Emit<KeyReleasedEvent>(keycode);
    }

    void InputManager::EmitMouseButtonPressedEvent(int buttoncode) noexcept {
        if(buttoncode >= MAX_MOUSE_BUTTONS) CORE_LOG_WARN("[InputManager] Wrong mouse button id");
        else Bald::EventManager::Emit<MouseButtonPressedEvent>(buttoncode);
    }

    void InputManager::EmitMouseButtonTypedEvent(int buttoncode) noexcept {
        if(buttoncode >= MAX_MOUSE_BUTTONS) CORE_LOG_WARN("[InputManager] Wrong mouse button id");
        else Bald::EventManager::Emit<MouseButtonTypedEvent>(buttoncode);
    }

    void InputManager::EmitMouseButtonReleasedEvent(int buttoncode) noexcept {
        if(buttoncode >= MAX_MOUSE_BUTTONS) CORE_LOG_WARN("[InputManager] Wrong mouse button id");
        else Bald::EventManager::Emit<MouseButtonReleasedEvent>(buttoncode);
    }

} // END OF NAMESPACE Bald::Input
