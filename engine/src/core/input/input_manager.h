//
// Created by grzegorz on 17.12.18.
//

#pragma once

#include "events/event.h"
#include "events/event_manager.h"
#include "events/event_manager.h"
#include "events/key_events.h"
#include "events/mouse_events.h"
#include "key_codes.h"

#include "core.h"
#include "pch.h"

struct GLFWwindow;

namespace Bald::Input {

    constexpr unsigned MAX_KEYS = 1024;
    constexpr unsigned MAX_MOUSE_BUTTONS = 64;

    /**
     * @class InputManager
     * @brief Manages user's input.
     */

    class InputManager {
    GENERATE_BODY(NORMAL)

        friend inline void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

        friend inline void char_callback(GLFWwindow* window, unsigned character);

        friend inline void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

        friend inline void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

        friend inline void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

    public:

        /**
         * @fn InputManager
         * @brief Default constructor deleted.
         */

        InputManager() = delete;

        /**
         * @fn Init
         * @brief Initialize InputManager
         * @param [EventManager&] ev -> reference on main event manager
         */

        static void Init(EventManager& ev);

        /**
         * @fn Update
         * @brief function updating information about input events should be called every frame.
         */

        static void Update() noexcept; //TODO: have to be called in Window class Update

        /**
         * @fn IsKeyPressed
         * @brief function that checks if key was pressed.
         * @param keycode [int]  BALD macro e.g. BALD_KEY_SPACE.
         * @return [bool] true if key was pressed otherwise false.
         */

        [[nodiscard]] inline static bool IsKeyPressed(unsigned keycode) noexcept;

        /**
         * @fn IsKeyTyped
         * @brief function that checks if key was typed.
         * @param keycode [int]  BALD macro e.g. BALD_KEY_SPACE.
         * @return [bool] true if key was typed otherwise false.
         */

        [[nodiscard]] inline static bool IsKeyTyped(unsigned keycode) noexcept;

        /**
         * @fn IsMouseButtonPressed
         * @brief function that checks if mouse button was pressed.
         * @param buttoncode [int]  BALD macro e.g. BALD_MOUSE_BUTTON_1.
         * @return [bool] true if button was pressed otherwise false.
         */

        [[nodiscard]] inline static bool IsMouseButtonPressed(unsigned buttoncode) noexcept;

        /**
         * @fn IsMouseButtonTyped
         * @brief function that checks if mouse button was typed.
         * @param buttoncode [int]  BALD macro e.g. BALD_MOUSE_BUTTON_1.
         * @return [bool] true if button was typed otherwise false.
         */

        [[nodiscard]] inline static bool IsMouseButtonTyped(unsigned buttoncode) noexcept;

        /**
         * @fn GetMousePos
         * @brief Returns current mouse position.
         * @return [std::pair<double, double>] Current mouse position.
         */

        inline static std::pair<double, double> GetMousePos() noexcept;

        /**
         * @fn GetMouseScrollOffset
         * @brief Returns current mouse scroll offset.
         * @return [std::pair<double, double>] Current mouse scroll offset.
         */

        inline static std::pair<double, double> GetMouseScrollOffset() noexcept;

        /**
         * @fn EmitKeyPressedEvent
         * @brief Emits KeyPressedEvent.
         * @param [int] keycode -> BALD key id.
         */

        static void EmitKeyPressedEvent(unsigned keycode, bool isRepeated = false) noexcept;

        /**
         * @fn EmitKeyTypedEvent
         * @brief Emits KeyTypedEvent.
         * @param [int] keycode -> BALD key id.
         */

        static void EmitKeyTypedEvent(unsigned keycode) noexcept;

        /**
         * @fn EmitKeyReleasedEvent
         * @brief Emits KeyRelasedEvent.
         * @param [int] keycode -> BALD key id.
         */

        static void EmitKeyReleasedEvent(unsigned keycode) noexcept;

        /**
         * @fn EmitMouseButtonPressedEvent
         * @brief Emits MouseButtonPressedEvent.
         * @param [int] buttoncode -> BALD key id.
         * @param [bool] isRepeated -> true - Key is being pressed repeatedly.
         *                             false - Key is not being pressed repeatedly.
         */

        static void EmitMouseButtonPressedEvent(unsigned buttoncode, bool isRepeated = false) noexcept;

        /**
         * @fn EmitMouseButtonReleasedEvent
         * @brief Emits MouseButtonReleasedEvent.
         * @param [bool] isRepeated -> true - Key is being pressed repeatedly.
         *                             false - Key is not being pressed repeatedly.
         */

        static void EmitMouseButtonReleasedEvent(unsigned buttoncode) noexcept;

    private:
        static std::pair<double, double> m_MousePos; /**< current mouse x, y - coordinate*/
        static std::pair<double, double> m_MouseOff; /**< current scroll x, y - offset*/
        static std::array<bool, MAX_KEYS> m_Keys; /**< current keys states*/
        static std::array<bool, MAX_KEYS> m_KeysState; /**< keys states in previous frame*/
        static std::array<bool, MAX_KEYS> m_KeysTyped; /**< keys witch were typed*/
        static std::array<bool, MAX_MOUSE_BUTTONS> m_MouseButtons; /**< current mouse buttons states*/
        static std::array<bool, MAX_MOUSE_BUTTONS> m_MouseButtonsState; /**< mouse buttons states in previous frame*/
        static std::array<bool, MAX_MOUSE_BUTTONS> m_MouseButtonsTyped; /**< mouse buttons witch were typed*/
    };

    inline void key_callback([[maybe_unused]] GLFWwindow* window, int key, [[maybe_unused]] int scancode, int action, [[maybe_unused]] int mods) {
        Bald::Input::InputManager::m_Keys[static_cast<unsigned >(key)] = action != BALD_RELEASE;

        switch (action) {
            case BALD_PRESS: {
                InputManager::EmitKeyPressedEvent(static_cast<unsigned>(key));
                break;
            }
            case BALD_RELEASE: {
                InputManager::EmitKeyReleasedEvent(static_cast<unsigned>(key));
                break;
            }
            case BALD_REPEAT: {
                InputManager::EmitKeyPressedEvent(static_cast<unsigned>(key), true);
                break;
            }
            default: {
                CORE_LOG_WARN("[InputManager] Wrong state provided");
            }
        }
    }

    inline void char_callback([[maybe_unused]] GLFWwindow* window, unsigned character) {
        InputManager::EmitKeyTypedEvent(character);
    }

    inline void mouse_button_callback([[maybe_unused]] GLFWwindow* window, int button, int action, [[maybe_unused]] int mods) {
        Bald::Input::InputManager::m_MouseButtons[static_cast<unsigned >(button)] = action != BALD_RELEASE;

        switch (action) {
            case BALD_PRESS: {
                InputManager::EmitMouseButtonPressedEvent(static_cast<unsigned>(button));
                break;
            }
            case BALD_RELEASE: {
                InputManager::EmitMouseButtonReleasedEvent(static_cast<unsigned>(button));
                break;
            }
            case BALD_REPEAT: {
                InputManager::EmitMouseButtonPressedEvent(static_cast<unsigned>(button), true);
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

    std::pair<double, double> InputManager::GetMousePos() noexcept {
        return m_MousePos;
    }

    std::pair<double, double> InputManager::GetMouseScrollOffset() noexcept {
        return m_MouseOff;
    }
} // END OF NAMESPACE Bald::Input
