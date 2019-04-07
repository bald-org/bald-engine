//
// Created by blinku on 02.04.19.
//

#pragma once

#include "event.h"
#include "event_manager.h"

namespace Bald {

    class KeyEvent : public Event {
        friend class EventManager;

    protected:
        explicit KeyEvent(int keycode)
            : m_KeyCode{keycode} {}

    public:
        void EmitConnectedEvents() const override {}
        [[nodiscard]] inline int GetKeyCode() const { return m_KeyCode; }
        [[nodiscard]] inline std::type_index Type() const override { return typeid(decltype(*this)); }

    protected:
        int m_KeyCode;
    }; // END OF CLASS KeyEvent

    class KeyPressedEvent : public KeyEvent {
        friend class EventManager;

    protected:
        explicit KeyPressedEvent(int keycode)
            : KeyEvent{keycode} {}

    public:
        void EmitConnectedEvents() const override { EventManager::Emit<KeyEvent>(m_KeyCode); }
        [[nodiscard]] inline std::type_index Type() const override { return typeid(decltype(*this)); }

    }; // END OF CLASS KeyPressedEvent


    class KeyReleasedEvent : public KeyEvent {
        friend class EventManager;

    protected:
        explicit KeyReleasedEvent(int keycode)
            : KeyEvent{keycode} {}

    public:
        void EmitConnectedEvents() const override { EventManager::Emit<KeyEvent>(m_KeyCode); }
        [[nodiscard]] inline std::type_index Type() const override { return typeid(decltype(*this)); }

    }; // END OF CLASS KeyReleasedEvent

    class KeyTypedEvent : public KeyEvent {
        friend class EventManager;

    protected:
        explicit KeyTypedEvent(int keycode)
            : KeyEvent{keycode} {}

    public:
        void EmitConnectedEvents() const override { EventManager::Emit<KeyEvent>(m_KeyCode); }
        [[nodiscard]] inline std::type_index Type() const override { return typeid(decltype(*this)); }

    }; // END OF CLASS KeyTypedEvent

} // END OF NAMESPACE Bald
