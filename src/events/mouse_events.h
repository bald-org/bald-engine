//
// Created by blinku on 02.04.19.
//

#pragma once

#include <utility>
#include "event.h"
#include "event_manager.h"

namespace Bald {

    class MouseEvent : public Event {
        friend class EventManager;

    public:
        void EmitConnectedEvents() const override {}
        [[nodiscard]] inline std::type_index Type() const override { return typeid(decltype(*this)); }
    }; // END OF CLASS MouseEvent

    class MouseMovedEvent : public MouseEvent {
        friend class EventManager;

    protected:
        explicit MouseMovedEvent(int xpos, int ypos)
            : m_MouseX(xpos), m_MouseY(ypos) {}

    public:
        void EmitConnectedEvents() const override { EventManager::Emit<MouseEvent>(); }
        [[nodiscard]] inline int GetX() const { return m_MouseX; }
        [[nodiscard]] inline int GetY() const { return m_MouseY; }
        [[nodiscard]] inline std::pair<int,int> GetMousePosition() const { return {m_MouseX, m_MouseY}; }

    private:
        int m_MouseX;
        int m_MouseY;
    }; // END OF CLASS MouseEvent

    class MouseButtonPressedEvent : public MouseEvent {
        friend class EventManager;

    protected:
        explicit MouseButtonPressedEvent(int keycode)
            : m_KeyCode{keycode} {}

    public:
        void EmitConnectedEvents() const override { EventManager::Emit<MouseEvent>(); }
        [[nodiscard]] inline int GetKeyCode() const { return m_KeyCode; }
        [[nodiscard]] inline std::type_index Type() const override { return typeid(decltype(*this)); }

    private:
        int m_KeyCode;
    }; // END OF CLASS MouseButtonPressedEvent

    class MouseButtonReleasedEvent : public MouseEvent {
        friend class EventManager;

    protected:
        explicit MouseButtonReleasedEvent(int keycode)
            : m_KeyCode{keycode} {}

    public:
        void EmitConnectedEvents() const override { EventManager::Emit<MouseEvent>(); }
        [[nodiscard]] inline int GetKeyCode() const { return m_KeyCode; }
        [[nodiscard]] inline std::type_index Type() const override { return typeid(decltype(*this)); }

    private:
        int m_KeyCode;
    }; // END OF CLASS MouseButtonReleasedEvent

    class MouseButtonTypedEvent : public MouseEvent {
        friend class EventManager;

    protected:
        explicit MouseButtonTypedEvent(int keycode)
            : m_KeyCode{keycode} {}

    public:
        void EmitConnectedEvents() const override { EventManager::Emit<MouseEvent>(); }
        [[nodiscard]] inline int GetKeyCode() const { return m_KeyCode; }
        [[nodiscard]] inline std::type_index Type() const override { return typeid(decltype(*this)); }

    private:
        int m_KeyCode;
    }; // END OF CLASS MouseButtonTypedEvent

} // END OF NAMESPACE Bald