//
// Created by blinku on 02.04.19.
//

#pragma once

#include <utility>
#include "event.h"
#include "event_manager.h"

namespace Bald {

    /**
     * @class WindowEvent
     * @brief Specific event implementation which also provides an API for even more specific window events
     */

    class WindowEvent : public Event {
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */

    protected:

        /**
        * @fn                   WindowEvent
        * @brief                Default constructor.
        */

        WindowEvent() = default;

    public:

        /**
        * @fn                           GetType
        * @brief                        This method returns type index of this specific class. This is used for polymorphism
        * @return [unsigned]            Type index
        */

        [[nodiscard]] inline unsigned GetType() const override { return Utils::get_type_id(*this); }

    }; // END OF CLASS WindowEvent

    /**
     * @class WindowEvent
     * @brief Specific event implementation for window resized type event
     */

    class WindowResizedEvent : public WindowEvent {
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */

    protected:

        /**
        * @fn                   WindowResizedEvent
        * @brief                Constructor
        * @param [int]          width  -> Window's width
        * @param [int]          height -> Window's height
        */

        explicit WindowResizedEvent(int windowWidth, int windowHeight)
            : m_WindowSize{windowWidth, windowHeight} {}

    public:

        /**
        * @fn                           GetType
        * @brief                        This method returns type index of this specific class. This is used for polymorphism
        * @return [unsigned]            Type index
        */

        [[nodiscard]] inline unsigned GetType() const override { return Utils::get_type_id(*this); }

    public:

        /**
        * @fn                   GetWidth
        * @brief                Width getter
        * @return [int]         Window's width during event emission
        */

        [[nodiscard]] inline int GetWidth() const noexcept { return m_WindowSize.first; }

        /**
        * @fn                   GetHeight
        * @brief                Height getter
        * @return [int]         Window's height during event emission
        */

        [[nodiscard]] inline int GetHeight() const noexcept { return m_WindowSize.second; }

        /**
        * @fn                               GetSize
        * @brief                            Returns window's width and height as pair
        * @return [std::pair<int,int>]      width, height coordinates as pair
        */

        [[nodiscard]] inline std::pair<int, int> GetSize() const noexcept { return m_WindowSize; }

    private:
        const std::pair<int, int> m_WindowSize; /* < Window's width, height */
    }; // END OF CLASS WindowResizedEvent

    /**
     * @class WindowEvent
     * @brief Specific event implementation for window closed type event
     */

    class WindowClosedEvent : public WindowEvent {
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */

    public:

        /**
        * @fn                           GetType
        * @brief                        This method returns type index of this specific class. This is used for polymorphism
        * @return [unsigned]     Type index
        */

        [[nodiscard]] inline unsigned GetType() const override { return Utils::get_type_id(*this); }

    }; // END OF CLASS WindowClosedEvent

} // END OF NAMESPACE Bald
