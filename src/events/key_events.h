//
// Created by blinku on 02.04.19.
//

#pragma once

#include "event.h"
#include "event_manager.h"
#include "function_handler.h"
#include "async_function_handler.h"

namespace Bald {

    /**
     * @class KeyEvent
     * @brief Specific event implementation which also provides an API for even more specific keyboard events
     */

    class KeyEvent : public Event {
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */
        template<class E, class H>
        friend void Subscribe(const H& ev);

    protected:

        /**
        * @fn                   KeyEvent
        * @brief                Constructor
        * @param [unsigned]     keycode -> Specific key code. Right now this is GLFW's key id
        */

        explicit KeyEvent(int keycode)
                :
                m_KeyCode(keycode) { }

    public:

        /**
        * @fn                   EmitConnectedEvents
        * @brief                This method is left blank because KeyEvent does not emit any associated events
        */

        void EmitConnectedEvents() const override { }

        /**
        * @fn                           Type
        * @brief                        This method returns type index of this specific class. This is used for polymorphism
        * @return [std::type_index]     Type index
        */

        inline void run() const override {
            for (const auto& callback : callbacks) {
                callback.Run(*this);
            }
            for (const auto& callback : async_callbacks) {
                callback.Run(*this);
            }
        }

    public:
        /**
        * @fn                   GetKeyCode
        * @brief                Key code getter
        */

        [[nodiscard]] inline int GetKeyCode() const noexcept { return m_KeyCode; }

    protected:
        const int m_KeyCode; /* < We save key code simply as an integer */

    private:
        static std::vector<FunctionHandler < KeyEvent>> callbacks;
        static std::vector<AsyncFunctionHandler < KeyEvent>> async_callbacks;
    }; // END OF CLASS KeyEvent



    template <>
    void Subscribe<KeyEvent, FunctionHandler < KeyEvent> >(const FunctionHandler < KeyEvent>& ev ){
        KeyEvent::callbacks.push_back(ev);
    }

    template <>
    void Subscribe<KeyEvent, AsyncFunctionHandler < KeyEvent> >(const AsyncFunctionHandler < KeyEvent>& ev ){
        KeyEvent::async_callbacks.push_back(ev);
    }

    /**
     * @class KeyPressedEvent
     * @brief Specific event implementation for key pressed type event
     */

    class KeyPressedEvent : public KeyEvent {
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */
        template<class E, class H>
        friend void Subscribe(const H& ev);
    protected:

        /**
        * @fn                   KeyPressedEvent
        * @brief                Constructor
        * @param [unsigned]     keycode -> Specific key code. Right now this is GLFW's key id
        */

        explicit KeyPressedEvent(int keycode)
                :
                KeyEvent{keycode} { }

    public:

        /**
        * @fn                   EmitConnectedEvents
        * @brief                This method is emits additional KeyEvent
        */

        void EmitConnectedEvents() const override { EventManager::Emit<KeyEvent>(m_KeyCode); }

        /**
        * @fn                   Type
        * @brief                This method returns type index of this specific class. This is used for polymorphism
        * @return [std::type_index]     Type index
        */

        void run() const override {
            for (const auto& callback : callbacks) {
                callback.Run(*this);
            }
            for (const auto& callback : async_callbacks) {
                callback.Run(*this);
            }
        }
    private:
        static std::vector<FunctionHandler < KeyPressedEvent>> callbacks;
        static std::vector<AsyncFunctionHandler < KeyPressedEvent>> async_callbacks;
    }; // END OF CLASS KeyPressedEvent

    template <>
    void Subscribe<KeyPressedEvent, FunctionHandler < KeyPressedEvent> >(const FunctionHandler < KeyPressedEvent>& ev ){
        KeyPressedEvent::callbacks.push_back(ev);
    }

    template <>
    void Subscribe<KeyPressedEvent, AsyncFunctionHandler < KeyPressedEvent> >(const AsyncFunctionHandler < KeyPressedEvent>& ev ){
        KeyPressedEvent::async_callbacks.push_back(ev);
    }

    /**
     * @class KeyReleasedEvent
     * @brief Specific event implementation for key released type event
     */

    class KeyReleasedEvent : public KeyEvent {
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */
        template<class E, class H>
        friend void Subscribe(const H& ev);
    protected:

        /**
        * @fn                   KeyReleasedEvent
        * @brief                Constructor
        * @param [unsigned]     keycode -> Specific key code. Right now this is GLFW's key id
        */

        explicit KeyReleasedEvent(int keycode)
                :
                KeyEvent{keycode} { }

    public:

        /**
        * @fn                   EmitConnectedEvents
        * @brief                This method is emits additional KeyEvent
        */

        void EmitConnectedEvents() const override { EventManager::Emit<KeyEvent>(m_KeyCode); }

        /**
        * @fn                   Type
        * @brief                This method returns type index of this specific class. This is used for polymorphism
        * @return [std::type_index]     Type index
        */

        void run() const override {
            for (const auto& callback : callbacks) {
                callback.Run(*this);
            }
            for (const auto& callback : async_callbacks) {
                callback.Run(*this);
            }
        }

    private:
        static std::vector<FunctionHandler < KeyReleasedEvent>> callbacks;
        static std::vector<AsyncFunctionHandler < KeyReleasedEvent>> async_callbacks;
    }; // END OF CLASS KeyReleasedEvent

    template <>
    void Subscribe<KeyReleasedEvent, FunctionHandler < KeyReleasedEvent> >(const FunctionHandler < KeyReleasedEvent>& ev ){
        KeyReleasedEvent::callbacks.push_back(ev);
    }

    template <>
    void Subscribe<KeyReleasedEvent, AsyncFunctionHandler < KeyReleasedEvent> >(const AsyncFunctionHandler < KeyReleasedEvent>& ev ){
        KeyReleasedEvent::async_callbacks.push_back(ev);
    }

    /**
     * @class KeyTypedEvent
     * @brief Specific event implementation for key typed type event
     */

    class KeyTypedEvent : public KeyEvent {
        friend class EventManager; /* < EVERY event which is NOT an abstract class MUST be a friend of the EventManager! */
        template<class E, class H>
        friend void Subscribe(const H& ev);
    protected:

        /**
        * @fn                   KeyTypedEvent
        * @brief                Constructor
        * @param [unsigned]     keycode -> Specific key code. Right now this is GLFW's key id
        */

        explicit KeyTypedEvent(int keycode)
                :
                KeyEvent{keycode} { }

    public:

        /**
        * @fn                   EmitConnectedEvents
        * @brief                This method is emits additional KeyEvent
        */

        void EmitConnectedEvents() const override { EventManager::Emit<KeyEvent>(m_KeyCode); }

        /**
        * @fn                   Type
        * @brief                This method returns type index of this specific class. This is used for polymorphism
        * @return [std::type_index]     Type index
        */

        void run() const override {
            for (const auto& callback : callbacks) {
                callback.Run(*this);
            }
            for (const auto& callback : async_callbacks) {
                callback.Run(*this);
            }
        }

    private:
        static std::vector<FunctionHandler < KeyTypedEvent>> callbacks;
        static std::vector<AsyncFunctionHandler < KeyTypedEvent>> async_callbacks;

    }; // END OF CLASS KeyTypedEvent

    template <>
    void Subscribe<KeyTypedEvent, FunctionHandler < KeyTypedEvent> >(const FunctionHandler < KeyTypedEvent>& ev ){
        KeyTypedEvent::callbacks.push_back(ev);
    }

    template <>
    void Subscribe<KeyTypedEvent, AsyncFunctionHandler < KeyTypedEvent> >(const AsyncFunctionHandler < KeyTypedEvent>& ev ){
        KeyTypedEvent::async_callbacks.push_back(ev);
    }

} // END OF NAMESPACE Bald
