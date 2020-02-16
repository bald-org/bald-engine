//
// Created by grzegorz on 17.12.18.
//

#include "input/input_manager.hpp"
#include "core/pch.hpp"
#include "debug/bald_assert.hpp"

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

        m_KeysState = m_Keys;
        m_MouseButtonsState = m_MouseButtons;
    }

    void InputManager::EmitKeyPressedEvent(unsigned keycode, bool isRepeated) noexcept {
        BALD_ASSERT(keycode < MAX_KEYS, "InputManager", "Wrong key id", keycode < MAX_KEYS);
        Events::EventBus::Emit<Events::KeyPressedEvent>(keycode, isRepeated);
    }

    void InputManager::EmitKeyTypedEvent(unsigned keycode) noexcept {
        BALD_ASSERT(keycode < MAX_KEYS, "InputManager", "Wrong key id", keycode < MAX_KEYS);
        Events::EventBus::Emit<Events::KeyTypedEvent>(keycode);
    }

    void InputManager::EmitKeyReleasedEvent(unsigned keycode) noexcept {
        BALD_ASSERT(keycode < MAX_KEYS, "InputManager", "Wrong key id", keycode < MAX_KEYS);
        Events::EventBus::Emit<Events::KeyReleasedEvent>(keycode);
    }

    void InputManager::EmitMouseButtonPressedEvent(unsigned buttoncode, bool isRepeated) noexcept {
        BALD_ASSERT(buttoncode < MAX_MOUSE_BUTTONS, "InputManager", "Wrong button id", buttoncode < MAX_MOUSE_BUTTONS);
        Events::EventBus::Emit<Events::MouseButtonPressedEvent>(buttoncode, isRepeated);
    }

    void InputManager::EmitMouseButtonReleasedEvent(unsigned buttoncode) noexcept {
        BALD_ASSERT(buttoncode < MAX_MOUSE_BUTTONS, "InputManager", "Wrong button id", buttoncode < MAX_MOUSE_BUTTONS);
        Events::EventBus::Emit<Events::MouseButtonReleasedEvent>(buttoncode);
    }

} // END OF NAMESPACE Bald::Input
