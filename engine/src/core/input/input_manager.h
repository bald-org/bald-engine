//
// Created by grzegorz on 17.12.18.
//

#pragma once

#include <array>

#include <GLFW/glfw3.h>

#include "events/event.h"
#include "events/event_manager.h"
#include "events/event_manager.h"
#include "events/key_events.h"
#include "events/mouse_events.h"

#include "core.h"
#include "pch.h"

namespace Bald::Input {

    constexpr unsigned MAX_KEYS = 1024;
    constexpr unsigned MAX_MOUSE_BUTTONS = 64;

    /**
     * @class InputManager
     * @brief Manages users input
     */

    class InputManager {
    GENERATE_BODY()

        friend inline void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

        friend inline void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

        friend inline void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

        friend inline void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

    public:

        /**
         * @fn    constructor
         * @brief deleted
         */

        InputManager() = delete;

        /**
         * @fn Init
         * @brief Initialize InputManager
         * @param [EventManager&] ev -> reference on main event manager
         */

        static void Init(EventManager& ev);

        /**
         * @fn    Update
         * @brief function updating information about input events should be called every frame
         */

        static void Update() noexcept; //TODO: have to be called in Window class Update

        /**
         * @fn                   IsKeyPressed
         * @brief                function that checks if key was pressed
         * @param keycode [int]  GLFW macro e.g. GLfW_KEY_SPACE
         * @return        [bool] true if key was pressed otherwise false
         */

        [[nodiscard]] inline static bool IsKeyPressed(unsigned keycode) noexcept;

        /**
         * @fn                   IsKeyTyped
         * @brief                function that checks if key was typed
         * @param keycode [int]  GLFW macro e.g. GLfW_KEY_SPACE
         * @return        [bool] true if key was typed otherwise false
         */

        [[nodiscard]] inline static bool IsKeyTyped(unsigned keycode) noexcept;

        /**
         * @fn                      IsMouseButtonPressed
         * @brief                   function that checks if mouse button was pressed
         * @param buttoncode [int]  GLFW macro e.g. GLFW_MOUSE_BUTTON_1
         * @return           [bool] true if button was pressed otherwise false
         */

        [[nodiscard]] inline static bool IsMouseButtonPressed(unsigned buttoncode) noexcept;

        /**
         * @fn                      IsMouseButtonTyped
         * @brief                   function that checks if mouse button was typed
         * @param buttoncode [int]  GLFW macro e.g. GLFW_MOUSE_BUTTON_1
         * @return           [bool] true if button was typed otherwise false
         */

        [[nodiscard]] inline static bool IsMouseButtonTyped(unsigned buttoncode) noexcept;

        /**
         * @fn                  GetMousePos
         * @brief               sets two variables on current mouse position
         * @param xpos [double] x-coordinate
         * @param ypos [double] y-coordinate
         */

        inline static void GetMousePos(double& xpos, double& ypos) noexcept;

        /**
         * @fn                  SetKeyPressedCallback
         * @brief               sets function which will be called on key pressed event
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
         * @param fun           function pointers
         * @param args          arguments for function
         */

        template<class F, class... Args>
        static void SetKeyReleasedCallback(F&& fun, Args&& ... args) noexcept;

        /**
         * @fn                     SetMouseMovedCallback
         * @brief                  sets function which will be called on mouse moved event
         * @param fun              function pointer
         * @param args             arguments for function
         */

        template<class F, class... Args>
        static void SetMouseMovedCallback(F&& fun, Args&& ... args) noexcept;

        /**
         * @fn                     SetMouseScrolledCallback
         * @brief                  sets function which will be called on mouse scrolled event
         * @param fun              function pointer
         * @param args             arguments for function
         */

        template<class F, class... Args>
        static void SetMouseScrolledCallback(F&& fun, Args&& ... args) noexcept;

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
         * @param fun              function pointer
         * @param args             arguments for function
         */

        template<class F, class... Args>
        static void SetMouseButtonTypedCallback(F&& fun, Args&& ... args) noexcept;

        /**
         * @fn                     SetMouseButtonReleasedCallback
         * @brief                  sets function which will be called on mouse button released event
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

        static void EmitKeyPressedEvent(unsigned keycode) noexcept;

        /**
         * @fn                  EmitKeyTypedEvent
         * @brief               Emits KeyTypedEvent
         * @param keycode [int] GLFW key id
         */

        static void EmitKeyTypedEvent(unsigned keycode) noexcept;

        /**
         * @fn                  EmitKeyReleasedEvent
         * @brief               Emits KeyRelasedEvent
         * @param keycode [int] GLFW key id
         */

        static void EmitKeyReleasedEvent(unsigned keycode) noexcept;

        /**
         * @fn                     EmitMouseButtonTypedEvent
         * @brief                  Emits MouseButtonTypedEvent
         * @param buttoncode [int] GLFW key id
         */

        static void EmitMouseButtonTypedEvent(unsigned buttoncode) noexcept;

        /**
         * @fn                  EmitMouseButtonPressedEvent
         * @brief               Emits MouseButtonPressedEvent
         * @param keycode [int] GLFW key id
         */

        static void EmitMouseButtonPressedEvent(unsigned buttoncode) noexcept;

        /**
         * @fn                  EmitMouseButtonReleasedEvent
         * @brief               Emits MouseButtonReleasedEvent
         * @param keycode [int] GLFW key id
         */

        static void EmitMouseButtonReleasedEvent(unsigned buttoncode) noexcept;

    private:
        static EventManager* m_EventManager;
        static std::pair<double, double> m_MousePos;                      /**< current mouse x, y - coordinate*/
        static std::pair<double, double> m_MouseOff;                      /**< current scroll x, y - offset*/
        static std::array<bool, MAX_KEYS> m_Keys;                         /**< current keys states*/
        static std::array<bool, MAX_KEYS> m_KeysState;                                /**< keys states in previous frame*/
        static std::array<bool, MAX_KEYS> m_KeysTyped;                                /**< keys witch were typed*/
        static std::array<bool, MAX_MOUSE_BUTTONS> m_MouseButtons;                    /**< current mouse buttons states*/
        static std::array<bool, MAX_MOUSE_BUTTONS> m_MouseButtonsState;               /**< mouse buttons states in previous frame*/
        static std::array<bool, MAX_MOUSE_BUTTONS> m_MouseButtonsTyped;               /**< mouse buttons witch were typed*/
    };

    inline void key_callback([[maybe_unused]] GLFWwindow* window, int key, [[maybe_unused]] int scancode, int action, [[maybe_unused]] int mods) {
        Bald::Input::InputManager::m_Keys[static_cast<unsigned >(key)] = action != GLFW_RELEASE;

        switch (action) {
            case GLFW_PRESS: {
                InputManager::EmitKeyPressedEvent(static_cast<unsigned>(key));
                InputManager::EmitKeyTypedEvent(static_cast<unsigned>(key));
                break;
            }
            case GLFW_RELEASE: {
                InputManager::EmitKeyReleasedEvent(static_cast<unsigned>(key));
                break;
            }
            case GLFW_REPEAT: {
                InputManager::EmitKeyPressedEvent(static_cast<unsigned>(key));
                break;
            }
            default: {
                CORE_LOG_WARN("[InputManager] Wrong state provided");
            }
        }
    }

    inline void
    mouse_button_callback([[maybe_unused]] GLFWwindow* window, int button, int action, [[maybe_unused]] int mods) {
        Bald::Input::InputManager::m_MouseButtons[static_cast<unsigned >(button)] = action != GLFW_RELEASE;

        switch (action) {
            case GLFW_PRESS: {
                InputManager::EmitMouseButtonTypedEvent(static_cast<unsigned>(button));
                break;
            }
            case GLFW_RELEASE: {
                InputManager::EmitMouseButtonReleasedEvent(static_cast<unsigned>(button));
                break;
            }
            case GLFW_REPEAT: {
                InputManager::EmitMouseButtonPressedEvent(static_cast<unsigned>(button));
                break;
            }
            default: {
                CORE_LOG_WARN("[InputManager] Wrong state provided");
            }
        }
    }

    inline void cursor_position_callback([[maybe_unused]]GLFWwindow* window, double xpos, double ypos) {
        Bald::Input::InputManager::m_MousePos.first = xpos;
        Bald::Input::InputManager::m_MousePos.second = ypos;
        Bald::EventManager::Emit<MouseMovedEvent>(static_cast<int>(xpos), static_cast<int>(ypos));
    }

    inline void scroll_callback([[maybe_unused]] GLFWwindow* window, double xoffset, double yoffset) {
        Bald::Input::InputManager::m_MouseOff.first = xoffset;
        Bald::Input::InputManager::m_MouseOff.second = yoffset;
        Bald::EventManager::Emit<MouseScrolledEvent>(xoffset, yoffset);
    }

    bool InputManager::IsKeyPressed(unsigned keycode) noexcept {
        if (keycode >= MAX_KEYS) return false;
        return m_Keys[keycode];
    }

    bool InputManager::IsKeyTyped(unsigned keycode) noexcept {
        if (keycode >= MAX_KEYS) return false;
        return m_KeysTyped[keycode];
    }

    bool InputManager::IsMouseButtonPressed(unsigned buttoncode) noexcept {
        if (buttoncode >= MAX_MOUSE_BUTTONS) return false;
        return m_MouseButtons[buttoncode];
    }

    bool InputManager::IsMouseButtonTyped(unsigned buttoncode) noexcept {
        if (buttoncode >= MAX_MOUSE_BUTTONS) return false;
        return m_MouseButtonsTyped[buttoncode];
    }

    void InputManager::GetMousePos(double& xpos, double& ypos) noexcept {
        xpos = InputManager::m_MousePos.first;
        ypos = InputManager::m_MousePos.second;
    }

    template<class F, class... Args>
    void InputManager::SetKeyPressedCallback(F&& fun, Args&& ... args) noexcept {
        m_EventManager->Subscribe<KeyPressedEvent>(HandleType::SYNC, fun, args ...);
    }

    template<class F, class... Args>
    void InputManager::SetKeyTypedCallback(F&& fun, Args&& ... args) noexcept {
        m_EventManager->Subscribe<KeyTypedEvent>(HandleType::SYNC, fun, args ...);
    }

    template<class F, class... Args>
    void InputManager::SetKeyReleasedCallback(F&& fun, Args&& ... args) noexcept {
        m_EventManager->Subscribe<KeyReleasedEvent>(HandleType::SYNC, fun, args ...);
    }

    template<class F, class... Args>
    void InputManager::SetMouseMovedCallback(F&& fun, Args&& ... args) noexcept {
        m_EventManager->Subscribe<MouseMovedEvent>(HandleType::SYNC, fun, args ...);
    }

    template<class F, class... Args>
    void InputManager::SetMouseScrolledCallback(F&& fun, Args&& ... args) noexcept {
        m_EventManager->Subscribe<MouseScrolledEvent>(HandleType::SYNC, fun, args ...);
    }

    template<class F, class... Args>
    void InputManager::SetMouseButtonPressedCallback(F&& fun, Args&& ... args) noexcept {
        m_EventManager->Subscribe<MouseButtonPressedEvent>(HandleType::SYNC, fun, args ...);
    }

    template<class F, class... Args>
    void InputManager::SetMouseButtonTypedCallback(F&& fun, Args&& ... args) noexcept {
        m_EventManager->Subscribe<MouseButtonTypedEvent>(HandleType::SYNC, fun, args ...);
    }

    template<class F, class... Args>
    void InputManager::SetMouseButtonReleasedCallback(F&& fun, Args&& ... args) noexcept {
        m_EventManager->Subscribe<MouseButtonReleasedEvent>(HandleType::SYNC, fun, args ...);
    }

} // END OF NAMESPACE Bald::Input
