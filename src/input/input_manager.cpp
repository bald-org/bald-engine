//
// Created by grzegorz on 17.12.18.
//

#include "input_manager.h"
#include "pch.h"



namespace Bald::Input{

    double InputManager::m_MouseX = 0.0;
    double InputManager::m_MouseY = 0.0;
    bool InputManager::m_Keys[MAX_KEYS];
    bool InputManager::m_KeysState[MAX_KEYS];
    bool InputManager::m_KeysTyped[MAX_KEYS];
    bool InputManager::m_MouseButtons[MAX_MOUSE_BUTTONS];
    bool InputManager::m_MouseButtonsState[MAX_MOUSE_BUTTONS];
    bool InputManager::m_MouseButtonsTyped[MAX_MOUSE_BUTTONS];

    void InputManager::Update() {

        for(int i = 0; i < MAX_KEYS; i++) m_KeysTyped[i] = m_Keys[i] && !m_KeysState[i];
        for(int i = 0; i < MAX_MOUSE_BUTTONS; i++) m_MouseButtonsTyped[i] = !m_MouseButtonsState[i] && m_MouseButtons[i];

        std::memcpy(m_KeysState, m_Keys, MAX_KEYS);
        std::memcpy(m_MouseButtonsState, m_MouseButtons, MAX_MOUSE_BUTTONS);

    }

}
