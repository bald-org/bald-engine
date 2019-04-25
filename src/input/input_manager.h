//
// Created by grzegorz on 17.12.18.
//

#pragma once

#include "events/event.h"
#include "events/event_manager.h"
#include "GLFW/glfw3.h"
#include "pch.h"

#include "event_manager.h"
#include "key_events.h"
#include "mouse_events.h"

#define MAX_KEYS          1024
#define MAX_MOUSE_BUTTONS 64

/**
 * @class InputManager
 * @brief manages user's input
 */


namespace Bald::Input {

    using callback = std::function<void()>;

    class InputManager {

        friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

        friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

        friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

    public:

        /**
         * @fn    constructor
         * @brief deleted
         */

        InputManager() = delete;

        /**
         * @fn    Update
         * @brief function updating information about input events should be called every frame
         */

        static void Update() noexcept; //TODO: have to be called in Window class Update

        /**
         * @fn                   isKeyPressed
         * @brief                function that checks if key was pressed
         * @param keycode [int]  GLFW macro e.g. GLfW_KEY_SPACE
         * @return        [bool] true if key was pressed otherwise false
         */

        [[nodiscard]] inline static bool IsKeyPressed(int keycode) noexcept;

        /**
         * @fn                   isKeyTyped
         * @brief                function that checks if key was typed
         * @param keycode [int]  GLFW macro e.g. GLfW_KEY_SPACE
         * @return        [bool] true if key was typed otherwise false
         */

        [[nodiscard]] inline static bool IsKeyTyped(int keycode) noexcept;

        /**
         * @fn                      isMouseButtonPressed
         * @brief                   function that checks if mouse button was pressed
         * @param buttoncode [int]  GLFW macro e.g. GLFW_MOUSE_BUTTON_1
         * @return           [bool] true if button was pressed otherwise false
         */

        [[nodiscard]] inline static bool IsMouseButtonPressed(int buttoncode) noexcept;

        /**
         * @fn                      isMouseButtonTyped
         * @brief                   function that checks if mouse button was typed
         * @param buttoncode [int]  GLFW macro e.g. GLFW_MOUSE_BUTTON_1
         * @return           [bool] true if button was typed otherwise false
         */

        [[nodiscard]] inline static bool IsMouseButtonTyped(int buttoncode) noexcept;

        /**
         * @fn                  getMousePos
         * @brief               sets two variables on current mouse position
         * @param xpos [double] x-coordinate
         * @param ypos [double] y-coordinate
         */

        inline static void GetMousePos(double& xpos, double& ypos) noexcept;

        /**
         * @fn                  SetKeyPressedCallback
         * @brief               sets function which will be called on key pressed event
         * @param keycode [int] GLFW key id
         * @param fun           function pointer
         * @param args          arguments for function
         */

        template<class F, class... Args>
        static void SetKeyPressedCallback(F&& fun, Args&& ... args) noexcept;

        /**
         * @fn                  SetKeyTypedCallback
         * @brief               sets function which will be called on key typed event
         * @param keycode [int] GLFW key id
         * @param fun           function pointers
         * @param args          arguments for function
         */

        template<class F, class... Args>
        static void SetKeyTypedCallback(F&& fun, Args&& ... args) noexcept;

        /**
         * @fn                  SetKeyReleasedCallback
         * @brief               sets function which will be called on key released event
         * @param keycode [int] GLFW key id
         * @param fun           function pointers
         * @param args          arguments for function
         */

        template<class F, class... Args>
        static void SetKeyReleasedCallback(F&& fun, Args&& ... args) noexcept;

        /**
         * @fn                     SetMouseButtonPressedCallback
         * @brief                  sets function which will be called on mouse button pressed event
         * @param buttoncode [int] GLFW mouse button id
         * @param fun              function pointer
         * @param args             arguments for function
         */

        template<class F, class... Args>
        static void SetMouseButtonPressedCallback(F&& fun, Args&& ... args) noexcept;

        /**
         * @fn                     SetMouseButtonTypedCallback
         * @brief                  sets function which will be called on mouse button Typed event
         * @param buttoncode [int] GLFW mouse button id
         * @param fun              function pointer
         * @param args             arguments for function
         */

        template<class F, class... Args>
        static void SetMouseButtonTypedCallback(F&& fun, Args&& ... args) noexcept;

        /**
         * @fn                     SetMouseButtonReleasedCallback
         * @brief                  sets function which will be called on mouse button released event
         * @param buttoncode [int] GLFW mouse button id
         * @param fun              function pointer
         * @param args             arguments for function
         */

        template<class F, class... Args>
        static void SetMouseButtonReleasedCallback(F&& fun, Args&& ... args) noexcept;

        /**
         * @fn                  EmitKeyPressedEvent
         * @brief               Emits KeyPressedEvent
         * @param keycode [int] GLFW key id
         */

        static void EmitKeyPressedEvent(int keycode) noexcept;

        /**
         * @fn                  EmitKeyTypedEvent
         * @brief               Emits KeyTypedEvent
         * @param keycode [int] GLFW key id
         */

        static void EmitKeyTypedEvent(int keycode) noexcept;

        /**
         * @fn                  EmitKeyReleasedEvent
         * @brief               Emits KeyRelasedEvent
         * @param keycode [int] GLFW key id
         */

        static void EmitKeyReleasedEvent(int keycode) noexcept;

        /**
         * @fn                     EmitMouseButtonTypedEvent
         * @brief                  Emits MouseButtonTypedEvent
         * @param buttoncode [int] GLFW key id
         */

        static void EmitMouseButtonTypedEvent(int buttoncode) noexcept;

        /**
         * @fn                  EmitMouseButtonPressedEvent
         * @brief               Emits MouseButtonPressedEvent
         * @param keycode [int] GLFW key id
         */

        static void EmitMouseButtonPressedEvent(int buttoncode) noexcept;

        /**
         * @fn                  EmitMouseButtonReleasedEvent
         * @brief               Emits MouseButtonReleasedEvent
         * @param keycode [int] GLFW key id
         */

        static void EmitMouseButtonReleasedEvent(int buttoncode) noexcept;

    private:
        static std::pair<double, double> m_MousePos;                      /**< current mouse x, y - coordinate*/
        static bool m_Keys[MAX_KEYS];                                     /**< current keys states*/
        static bool m_KeysState[MAX_KEYS];                                /**< keys states in previous frame*/
        static bool m_KeysTyped[MAX_KEYS];                                /**< keys witch were typed*/
        static bool m_MouseButtons[MAX_MOUSE_BUTTONS];                    /**< current mouse buttons states*/
        static bool m_MouseButtonsState[MAX_MOUSE_BUTTONS];               /**< mouse buttons states in previous frame*/
        static bool m_MouseButtonsTyped[MAX_MOUSE_BUTTONS];               /**< mouse buttons witch were typed*/
        static callback m_KeyPressedCallbacks[MAX_KEYS];                  /**< callbacks on key pressed event*/
        static callback m_KeyTypedCallbacks[MAX_KEYS];                    /**< callbacks on key typed event*/
        static callback m_MouseButtonPressedCallbacks[MAX_MOUSE_BUTTONS]; /**< callbacks on mouse button pressed event*/
        static callback m_MouseButtonTypedCallbacks[MAX_MOUSE_BUTTONS];   /**< callbacks on mouse button typed event*/
    };

    bool InputManager::IsKeyPressed(int keycode) noexcept {
        if(keycode >= MAX_KEYS) return false;
        return m_Keys[keycode];
    }

    bool InputManager::IsKeyTyped(int keycode) noexcept {
        if(keycode >= MAX_KEYS) return false;
        return m_KeysTyped[keycode];
    }

    bool InputManager::IsMouseButtonPressed(int buttoncode) noexcept {
        if(buttoncode >= MAX_MOUSE_BUTTONS) return false;
        return m_MouseButtons[buttoncode];
    }

    bool InputManager::IsMouseButtonTyped(int buttoncode) noexcept {
        if(buttoncode >= MAX_MOUSE_BUTTONS) return false;
        return m_MouseButtonsTyped[buttoncode];
    }

    void InputManager::GetMousePos(double& xpos, double& ypos) noexcept {
        xpos = InputManager::m_MousePos.first;
        ypos = InputManager::m_MousePos.second;
    }

    inline void key_callback([[maybe_unused]] GLFWwindow* window, int key, [[maybe_unused]] int scancode, int action, [[maybe_unused]] int mods) {
        Bald::Input::InputManager::m_Keys[key] = action != GLFW_RELEASE;
    }

    inline void
    mouse_button_callback([[maybe_unused]] GLFWwindow* window, int button, int action, [[maybe_unused]] int mods) {
        Bald::Input::InputManager::m_MouseButtons[button] = action != GLFW_RELEASE;
    }

    inline void cursor_position_callback([[maybe_unused]]GLFWwindow* window, double xpos, double ypos) {
        Bald::Input::InputManager::m_MousePos.first = xpos;
        Bald::Input::InputManager::m_MousePos.second = ypos;
        Bald::EventManager::Emit<MouseMovedEvent>(static_cast<int>(xpos), static_cast<int>(ypos));
    }

    template<class F, class... Args>
    void InputManager::SetKeyPressedCallback(F&& fun, Args&& ... args) noexcept {
        Bald::EventManager::Subscribe<KeyPressedEvent>(HandleType::SYNC, fun, args ...);
    }

    template<class F, class... Args>
    void InputManager::SetKeyTypedCallback(F&& fun, Args&& ... args) noexcept {
        Bald::EventManager::Subscribe<KeyTypedEvent>(HandleType::SYNC, fun, args ...);
    }

    template<class F, class... Args>
    void InputManager::SetKeyReleasedCallback(F&& fun, Args&& ... args) noexcept {
        Bald::EventManager::Subscribe<KeyReleasedEvent>(HandleType::SYNC, fun, args ...);
    }

    template<class F, class... Args>
    void InputManager::SetMouseButtonPressedCallback(F&& fun, Args&& ... args) noexcept {
        Bald::EventManager::Subscribe<MouseButtonPressedEvent>(HandleType::SYNC, fun, args ...);
    }

    template<class F, class... Args>
    void InputManager::SetMouseButtonTypedCallback(F&& fun, Args&& ... args) noexcept {
        Bald::EventManager::Subscribe<MouseButtonTypedEvent>(HandleType::SYNC, fun, args ...);
    }

    template<class F, class... Args>
    void InputManager::SetMouseButtonReleasedCallback(F&& fun, Args&& ... args) noexcept {
        Bald::EventManager::Subscribe<MouseButtonReleasedEvent>(HandleType::SYNC, fun, args ...);
    }

} // END OF NAMESPACE Bald::Input
