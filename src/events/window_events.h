//
// Created by blinku on 02.04.19.
//

#pragma once

#include <utility>
#include "event.h"
#include "event_manager.h"

namespace Bald {

    class WindowEvent : public Event {
        friend class EventManager;

    public:
        void EmitConnectedEvents() const override {}

        [[nodiscard]] inline std::type_index Type() const override { return typeid(decltype(*this)); }
    }; // END OF CLASS WindowEvent

    class WindowResizedEvent : public WindowEvent {
        friend class EventManager;

    protected:
        explicit WindowResizedEvent(int width, int height)
            : m_Width(width), m_Height(height) {}

    public:
        void EmitConnectedEvents() const override { EventManager::Emit<WindowEvent>(); }

        inline std::type_index Type() const override { return typeid(decltype(*this)); }

    public:
        [[nodiscard]] inline int GetWidth() const noexcept { return m_Width; }

        [[nodiscard]] inline int GetHeight() const noexcept { return m_Height; }

        [[nodiscard]] inline std::pair<int, int> GetSize() const noexcept { return {m_Width, m_Height}; }

    private:
        int m_Width;
        int m_Height;
    }; // END OF CLASS WindowResizedEvent

    class WindowClosedEvent : public WindowEvent {
        friend class EventManager;

    public:
        void EmitConnectedEvents() const override { EventManager::Emit<WindowEvent>(); }

        inline std::type_index Type() const override { return typeid(decltype(*this)); }
    }; // END OF CLASS WindowClosedEvent

} // END OF NAMESPACE Bald
