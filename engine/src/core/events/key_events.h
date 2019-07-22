//
// Created by blinku on 02.04.19.
//

#pragma once

#include "core.h"
#include "event.h"

namespace Bald {

    /**
     * @class KeyEvent
     * @brief Specific event implementation which also provides an API for even more specific keyboard events.
     */

    class KeyEvent : public Event {
        GENERATE_BODY(DERIVED)
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */

    protected:

        /**
        * @fn KeyEvent
        * @brief Constructor.
        * @param [unsigned] keycode -> Specific key code. Right now this is GLFW's key id.
        */

        explicit KeyEvent(unsigned keycode)
            : m_KeyCode{keycode} {}

    public:

        /**
        * @fn GetKeyCode
        * @brief Key code getter
        */

        [[nodiscard]] inline unsigned GetKeyCode() const noexcept { return m_KeyCode; }

    protected:
        const unsigned m_KeyCode; /* < We save key code simply as an integer */
    }; // END OF CLASS KeyEvent

    /**
     * @class KeyPressedEvent
     * @brief Specific event implementation for key pressed type event.
     */

    class KeyPressedEvent : public KeyEvent {
        GENERATE_BODY(DERIVED)
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */

    protected:

        /**
        * @fn KeyPressedEvent
        * @brief Constructor.
        * @param [unsigned] keycode -> Specific key code. Right now this is GLFW's key id.
        */

        explicit KeyPressedEvent(unsigned keycode, bool isRepeated = false)
            : KeyEvent{keycode}, m_IsRepeated{isRepeated} {}

    public:

        /**
        * @fn IsRepeated
        * @brief Getter which tells you whether or not the key press was a repeated one.
        * @return [bool] true -> key is in repeated state.
        *                false -> key is in non repeated state.
        */

        [[nodiscard]] bool IsRepeated() const noexcept { return m_IsRepeated; }

    private:
        const bool m_IsRepeated; /* < Bool which holds repeated state */
    }; // END OF CLASS KeyPressedEvent

    /**
     * @class KeyReleasedEvent
     * @brief Specific event implementation for key released type event.
     */

    class KeyReleasedEvent : public KeyEvent {
        GENERATE_BODY(DERIVED)
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */

    protected:

        /**
        * @fn KeyReleasedEvent
        * @brief Constructor.
        * @param [unsigned] keycode -> Specific key code. Right now this is GLFW's key id.
        */

        explicit KeyReleasedEvent(unsigned keycode)
            :
            KeyEvent{keycode} {}

    }; // END OF CLASS KeyReleasedEvent

    /**
     * @class KeyTypedEvent
     * @brief Specific event implementation for key typed type event.
     */

    class KeyTypedEvent : public KeyEvent {
        GENERATE_BODY(DERIVED)
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */

    protected:

        /**
        * @fn KeyTypedEvent
        * @brief Constructor.
        * @param [unsigned] keycode -> Specific key code. Right now this is GLFW's key id.
        */

        explicit KeyTypedEvent(unsigned keycode)
            :
            KeyEvent{keycode} {}

    }; // END OF CLASS KeyTypedEvent

} // END OF NAMESPACE Bald
