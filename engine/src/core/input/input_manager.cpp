//
// Created by grzegorz on 17.12.18.
//

#include "input_manager.h"
#include "core/pch.h"

namespace Bald::Input {

    std::pair<double, double> InputManager::m_MousePos;
    std::pair<double, double> InputManager::m_MouseOff;
    std::array<bool, MAX_KEYS> InputManager::m_Keys;
    std::array<bool, MAX_KEYS> InputManager::m_KeysState;
    std::array<bool, MAX_KEYS> InputManager::m_KeysTyped;
    std::array<bool, MAX_MOUSE_BUTTONS> InputManager::m_MouseButtons;
    std::array<bool, MAX_MOUSE_BUTTONS> InputManager::m_MouseButtonsState;
    std::array<bool, MAX_MOUSE_BUTTONS> InputManager::m_MouseButtonsTyped;

    void InputManager::Update() noexcept {

        for(unsigned i = 0; i < MAX_KEYS; i++) {
            m_KeysTyped[i] = !m_KeysState[i] && m_Keys[i];
        }

        for(unsigned i = 0; i < MAX_MOUSE_BUTTONS; i++) {
            m_MouseButtonsTyped[i] = !m_MouseButtonsState[i] && m_MouseButtons[i];
        }

        std::memcpy(m_KeysState.begin(), m_Keys.begin(), MAX_KEYS * sizeof(m_Keys[0]));
        std::memcpy(m_MouseButtonsState.begin(), m_MouseButtons.begin(), MAX_MOUSE_BUTTONS * sizeof(m_MouseButtons[0]));
    }

    void InputManager::EmitKeyPressedEvent(unsigned keycode, bool isRepeated) noexcept {
        if(keycode >= MAX_KEYS) {
            CORE_LOG_WARN("[InputManager] Wrong key id");
            assert(keycode >= MAX_KEYS);
        }
        else Bald::EventManager::Emit<KeyPressedEvent>(keycode, isRepeated);
    }

    void InputManager::EmitKeyTypedEvent(unsigned keycode) noexcept {
        if(keycode >= MAX_KEYS) {
            CORE_LOG_WARN("[InputManager] Wrong key id");
            assert(keycode >= MAX_KEYS);
        }
        else Bald::EventManager::Emit<KeyTypedEvent>(keycode);
    }

    void InputManager::EmitKeyReleasedEvent(unsigned keycode) noexcept {
        if(keycode >= MAX_KEYS) {
            CORE_LOG_WARN("[InputManager] Wrong key id");
            assert(keycode >= MAX_KEYS);
        }
        else Bald::EventManager::Emit<KeyReleasedEvent>(keycode);
    }

    void InputManager::EmitMouseButtonPressedEvent(unsigned buttoncode, bool isRepeated) noexcept {
        if(buttoncode >= MAX_MOUSE_BUTTONS) {
            CORE_LOG_WARN("[InputManager] Wrong mouse button id");
            assert(buttoncode >= MAX_MOUSE_BUTTONS);
        }
        else Bald::EventManager::Emit<MouseButtonPressedEvent>(buttoncode, isRepeated);
    }

    void InputManager::EmitMouseButtonReleasedEvent(unsigned buttoncode) noexcept {
        if(buttoncode >= MAX_MOUSE_BUTTONS) {
            CORE_LOG_WARN("[InputManager] Wrong mouse button id");
            assert(buttoncode >= MAX_MOUSE_BUTTONS);
        }
        else Bald::EventManager::Emit<MouseButtonReleasedEvent>(buttoncode);
    }

} // END OF NAMESPACE Bald::Input
