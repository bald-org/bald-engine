//
// Created by blinku on 02.04.19.
//

#pragma once

#include <utility>
#include "event.h"
#include "event_manager.h"

namespace Bald {

    /**
     * @class MouseEvent
     * @brief Specific event implementation which also provides an API for even more specific mouse events
     */

    class MouseEvent : public Event {
        //friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */

    public:

        /**
        * @fn                   EmitConnectedEvents
        * @brief                This method is left blank because MouseEvent does not emit any associated events
        */

        void EmitConnectedEvents() const override {}

        /**
        * @fn                   Type
        * @brief                This method returns type index of this specific class. This is used for polymorphism
        */

        static std::vector<FunctionHandler < MouseEvent>> callbacks;
        static std::vector<AsyncFunctionHandler < MouseEvent>> async_callbacks;
    }; // END OF CLASS MouseEvent

//    template <>
//    void Subscribe<KeyReleasedEvent, FunctionHandler < MouseEvent> >(const FunctionHandler < MouseEvent>& ev ){
//        MouseEvent::callbacks.push_back(ev);
//    }
//
//    template <>
//    void Subscribe<KeyReleasedEvent, AsyncFunctionHandler < MouseEvent> >(const AsyncFunctionHandler < MouseEvent>& ev ){
//        MouseEvent::async_callbacks.push_back(ev);
//    }

    /**
     * @class MouseMovedEvent
     * @brief Specific event implementation for mouse moved type event
     */

    class MouseMovedEvent : public MouseEvent {
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */

    public:

        /**
        * @fn                   MouseMovedEvent
        * @brief                Constructor
        * @param [int]          xpos -> specific mouse position
        * @param [int]          ypos -> specific mouse position
        */

        explicit MouseMovedEvent(int mouseX, int mouseY)
            : m_MousePos{mouseX, mouseY} {}

    public:

        /**
        * @fn                   EmitConnectedEvents
        * @brief                This method is emits additional MouseEvent
        */

        void EmitConnectedEvents() const override { EventManager::Emit<MouseEvent>(); }

        /**
        * @fn                           Type
        * @brief                        This method returns type index of this specific class. This is used for polymorphism
        * @return [std::type_index]     Type index
        */


    public:

        /**
        * @fn                   GetX
        * @brief                Mouse x coordinate getter
        * @return [int]         Mouse x coordinate
        */

        [[nodiscard]] inline int GetX() const noexcept { return m_MousePos.first; }

        /**
        * @fn                   GetY
        * @brief                Mouse y coordinate getter
        * @return [int]         Mouse y coordinate
        */

        [[nodiscard]] inline int GetY() const noexcept { return m_MousePos.second; }

        /**
        * @fn                               GetMousePosition
        * @brief                            Mouse x, y coordinates getter
        * @return [std::pair<int,int>]      x, y coordinates as pair
        */

        [[nodiscard]] inline const std::pair<int, int> GetMousePosition() const noexcept { return m_MousePos; }

    public:
        const std::pair<int, int> m_MousePos; /* < Mouse x, y coordinate */
        static std::vector<FunctionHandler < MouseMovedEvent>> callbacks;
        static std::vector<AsyncFunctionHandler < MouseMovedEvent>> async_callbacks;
    }; // END OF CLASS MouseMovedEvent

//    template <>
//    void Subscribe<MouseMovedEvent, FunctionHandler < MouseMovedEvent> >(const FunctionHandler < MouseMovedEvent>& ev ){
//        MouseMovedEvent::callbacks.push_back(ev);
//    }
//
//    template <>
//    void Subscribe<MouseMovedEvent, AsyncFunctionHandler < MouseMovedEvent> >(const AsyncFunctionHandler < MouseMovedEvent>& ev ){
//        MouseMovedEvent::async_callbacks.push_back(ev);
//    }

    /**
     * @class MouseScrolledEvent
     * @brief Specific event implementation for mouse offset type event
     */

    class MouseScrolledEvent : public MouseEvent {
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */

    public:

        /**
        * @fn                   MouseScrolledEvent
        * @brief                Constructor
        * @param [double]       xoffset -> specific mouse offset
        * @param [double]       yoffset -> specific mouse offset
        */

        explicit MouseScrolledEvent(double xoffset, double yoffset)
            : m_MouseOff{xoffset, yoffset} {}

    public:

        /**
        * @fn                   EmitConnectedEvents
        * @brief                This method is emits additional MouseEvent
        */

        void EmitConnectedEvents() const override { EventManager::Emit<MouseEvent>(); }

        /**
        * @fn                           Type
        * @brief                        This method returns type index of this specific class. This is used for polymorphism
        * @return [std::type_index]     Type index
        */

    public:

        /**
        * @fn                   GetOffsetX
        * @brief                Mouse x offset getter
        * @return [double]      Mouse x offset
        */

        [[nodiscard]] inline double GetOffsetX() const noexcept { return m_MouseOff.first; }

        /**
        * @fn                   GetOffsetY
        * @brief                Mouse y offset getter
        * @return [double]      Mouse y offset
        */

        [[nodiscard]] inline double GetOffsetY() const noexcept { return m_MouseOff.second; }

        /**
        * @fn                                   GetMouseOffset
        * @brief                                Mouse x, y offset getter
        * @return [std::pair<double,double>]    x, y offset as pair
        */

        [[nodiscard]] inline std::pair<double, double> GetMouseOffset() const noexcept { return m_MouseOff; }

    public:
        const std::pair<double, double> m_MouseOff; /* < Mouse x, y offset */
        static std::vector<FunctionHandler < MouseScrolledEvent>> callbacks;
        static std::vector<AsyncFunctionHandler < MouseScrolledEvent>> async_callbacks;
    }; // END OF CLASS MouseScrolledEvent

//    template <>
//    void Subscribe<MouseScrolledEvent, FunctionHandler < MouseScrolledEvent> >(const FunctionHandler < MouseScrolledEvent>& ev ){
//        MouseScrolledEvent::callbacks.push_back(ev);
//    }
//
//    template <>
//    void Subscribe<MouseMovedEvent, AsyncFunctionHandler < MouseScrolledEvent> >(const AsyncFunctionHandler < MouseScrolledEvent>& ev ){
//        MouseScrolledEvent::async_callbacks.push_back(ev);
//    }

    /**
     * @class MouseButtonPressedEvent
     * @brief Specific event implementation for mouse button pressed type event
     */

    class MouseButtonPressedEvent : public MouseEvent {
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */

    public:

        /**
        * @fn                   MouseButtonPressedEvent
        * @brief                Constructor
        * @param [int]          keycode -> Specific key code. Right now this is GLFW's key id
        */

        explicit MouseButtonPressedEvent(int keycode)
            : m_KeyCode{keycode} {}

    public:

        /**
        * @fn                   EmitConnectedEvents
        * @brief                This method is emits additional MouseEvent
        */

        void EmitConnectedEvents() const override { EventManager::Emit<MouseEvent>(); }

        /**
        * @fn                           Type
        * @brief                        This method returns type index of this specific class. This is used for polymorphism
        * @return [std::type_index]     Type index
        */

    public:

        /**
        * @fn                   GetKeyCode
        * @brief                Key code getter
        * @return [int]         Key code
        */

        [[nodiscard]] inline int GetKeyCode() const noexcept { return m_KeyCode; }

    public:
        const int m_KeyCode; /* < We save key code simply as an integer */
        static std::vector<FunctionHandler < MouseButtonPressedEvent>> callbacks;
        static std::vector<AsyncFunctionHandler < MouseButtonPressedEvent>> async_callbacks;
    }; // END OF CLASS MouseButtonPressedEvent

//    template <>
//    void Subscribe<MouseButtonPressedEvent, FunctionHandler < MouseButtonPressedEvent> >(const FunctionHandler < MouseButtonPressedEvent>& ev ){
//        MouseButtonPressedEvent::callbacks.push_back(ev);
//    }
//
//    template <>
//    void Subscribe<MouseButtonPressedEvent, AsyncFunctionHandler < MouseButtonPressedEvent> >(const AsyncFunctionHandler < MouseButtonPressedEvent>& ev ){
//        MouseButtonPressedEvent::async_callbacks.push_back(ev);
//    }


    /**
     * @class MouseButtonReleasedEvent
     * @brief Specific event implementation for mouse button released type event
     */

    class MouseButtonReleasedEvent : public MouseEvent {
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */

    public:

        /**
        * @fn                   MouseButtonReleasedEvent
        * @brief                Constructor
        * @param [int]          keycode -> Specific key code. Right now this is GLFW's key id
        */

        explicit MouseButtonReleasedEvent(int keycode)
            : m_KeyCode{keycode} {}

    public:

        /**
        * @fn                   EmitConnectedEvents
        * @brief                This method is emits additional MouseEvent
        */

        void EmitConnectedEvents() const override { EventManager::Emit<MouseEvent>(); }

        /**
        * @fn                           Type
        * @brief                        This method returns type index of this specific class. This is used for polymorphism
        * @return [std::type_index]     Type index
        */


    public:

        /**
        * @fn                   GetKeyCode
        * @brief                Key code getter
        * @return [int]         Key code
        */

        [[nodiscard]] inline int GetKeyCode() const noexcept { return m_KeyCode; }

    public:
        const int m_KeyCode; /* < We save key code simply as an integer */
        static std::vector<FunctionHandler < MouseButtonReleasedEvent>> callbacks;
        static std::vector<AsyncFunctionHandler < MouseButtonReleasedEvent>> async_callbacks;
    }; // END OF CLASS MouseButtonReleasedEvent

//    template <>
//    void Subscribe<MouseButtonReleasedEvent, FunctionHandler < MouseButtonReleasedEvent> >(const FunctionHandler < MouseButtonReleasedEvent>& ev ){
//        MouseButtonReleasedEvent::callbacks.push_back(ev);
//    }
//
//    template <>
//    void Subscribe<MouseButtonReleasedEvent, AsyncFunctionHandler < MouseButtonReleasedEvent> >(const AsyncFunctionHandler < MouseButtonReleasedEvent>& ev ){
//        MouseButtonReleasedEvent::async_callbacks.push_back(ev);
//    }

    /**
     * @class MouseButtonTypedEvent
     * @brief Specific event implementation for mouse button typed type event
     */

    class MouseButtonTypedEvent : public MouseEvent {
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */

    public:

        /**
        * @fn                   MouseButtonTypedEvent
        * @brief                Constructor
        * @param [int]          keycode -> Specific key code. Right now this is GLFW's key id
        */

        explicit MouseButtonTypedEvent(int keycode)
            : m_KeyCode{keycode} {}

    public:

        /**
        * @fn                   EmitConnectedEvents
        * @brief                This method is emits additional MouseEvent
        */

        void EmitConnectedEvents() const override { EventManager::Emit<MouseEvent>(); }

    public:

        /**
        * @fn                   GetKeyCode
        * @brief                Key code getter
        * @return [int]         Key code
        */

        [[nodiscard]] inline int GetKeyCode() const noexcept { return m_KeyCode; }

    public:
        const int m_KeyCode; /* < We save key code simply as an integer */
        static std::vector<FunctionHandler < MouseButtonTypedEvent>> callbacks;
        static std::vector<AsyncFunctionHandler < MouseButtonTypedEvent>> async_callbacks;
    }; // END OF CLASS MouseButtonTypedEvent

} // END OF NAMESPACE Bald