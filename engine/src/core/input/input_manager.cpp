//
// Created by grzegorz on 17.12.18.
//

#include "input_manager.h"
#include "core/pch.h"

namespace Bald::Input {

    EventManager* InputManager::m_EventManager = nullptr;
    std::pair<double, double> InputManager::m_MousePos;
    std::pair<double, double> InputManager::m_MouseOff;
    std::array<bool, MAX_KEYS> InputManager::m_Keys;
    std::array<bool, MAX_KEYS> InputManager::m_KeysState;
    std::array<bool, MAX_KEYS> InputManager::m_KeysTyped;
    std::array<bool, MAX_MOUSE_BUTTONS> InputManager::m_MouseButtons;
    std::array<bool, MAX_MOUSE_BUTTONS> InputManager::m_MouseButtonsState;
    std::array<bool, MAX_MOUSE_BUTTONS> InputManager::m_MouseButtonsTyped;

    void InputManager::Init(EventManager& ev){
        m_EventManager = &ev;
        std::fill(m_Keys.begin(), m_Keys.end(), false);
        std::fill(m_KeysState.begin(), m_KeysState.end(), false);
        std::fill(m_KeysTyped.begin(), m_KeysTyped.end(), false);
        std::fill(m_MouseButtons.begin(), m_MouseButtons.end(), false);
        std::fill(m_MouseButtonsState.begin(), m_MouseButtonsState.end(), false);
        std::fill(m_MouseButtonsTyped.begin(), m_MouseButtonsTyped.end(), false);
    }

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

    void InputManager::EmitKeyPressedEvent(unsigned keycode) noexcept {
        if(keycode >= MAX_KEYS) CORE_LOG_WARN("[InputManager] Wrong key id");
        else Bald::EventManager::Emit<KeyPressedEvent>(keycode);
    }

    void InputManager::EmitKeyTypedEvent(unsigned keycode) noexcept {
        if(keycode >= MAX_KEYS) CORE_LOG_WARN("[InputManager] Wrong key id");
        else Bald::EventManager::Emit<KeyTypedEvent>(keycode);
    }

    void InputManager::EmitKeyReleasedEvent(unsigned keycode) noexcept {
        if(keycode >= MAX_KEYS) CORE_LOG_WARN("[InputManager] Wrong key id");
        else Bald::EventManager::Emit<KeyReleasedEvent>(keycode);
    }

    void InputManager::EmitMouseButtonPressedEvent(unsigned buttoncode) noexcept {
        if(buttoncode >= MAX_MOUSE_BUTTONS) CORE_LOG_WARN("[InputManager] Wrong mouse button id");
        else Bald::EventManager::Emit<MouseButtonPressedEvent>(buttoncode);
    }

    void InputManager::EmitMouseButtonTypedEvent(unsigned buttoncode) noexcept {
        if(buttoncode >= MAX_MOUSE_BUTTONS) CORE_LOG_WARN("[InputManager] Wrong mouse button id");
        else Bald::EventManager::Emit<MouseButtonTypedEvent>(buttoncode);
    }

    void InputManager::EmitMouseButtonReleasedEvent(unsigned buttoncode) noexcept {
        if(buttoncode >= MAX_MOUSE_BUTTONS) CORE_LOG_WARN("[InputManager] Wrong mouse button id");
        else Bald::EventManager::Emit<MouseButtonReleasedEvent>(buttoncode);
    }

} // END OF NAMESPACE Bald::Input
