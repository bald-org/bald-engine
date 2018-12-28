//
// Created by grzegorz on 17.12.18.
//

#pragma once

#include "GLFW/glfw3.h"

#define MAX_KEYS 1024
#define MAX_MOUSE_BUTTONS 32

// TODO: Documentation and Logging errors


namespace Bald::Input {

    class InputManager {

        friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
        friend void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);

    public:

        /**
         * @fn constructor
         * @brief deleted
         */

        InputManager() = delete;

        /**
         * @fn Update
         * @brief function updating information about input events should be called every frame
         */

        static void Update(); //TODO: have to be called in Window class Update

        /**
         * @fn isKeyPressed
         * @brief function that checks if key was pressed
         * @param keycode GLFW macro e.g. GLfW_KEY_SPACE
         * @return true if key was pressed otherwise false
         */

        [[nodiscard]] inline static bool isKeyPressed(int keycode) noexcept;

        /**
         * @fn isKeyTyped
         * @brief function that checks if key was typed
         * @param keycode GLFW macro e.g. GLfW_KEY_SPACE
         * @return true if key was typed otherwise false
         */

        [[nodiscard]] inline static bool isKeyTyped(int keycode) noexcept;

        /**
         * @fn isMouseButtonPressed
         * @brief function that checks if mouse button was pressed
         * @param buttoncode GLFW macro e.g. GLFW_MOUSE_BUTTON_1
         * @return true if button was pressed otherwise false
         */

        [[nodiscard]] inline static bool isMouseButtonPressed(int buttoncode) noexcept;

        /**
         * @fn isMouseButtonTyped
         * @brief function that checks if mouse button was typed
         * @param buttoncode GLFW macro e.g. GLFW_MOUSE_BUTTON_1
         * @return true if button was typed otherwise false
         */

        [[nodiscard]] inline static bool isMouseButtonTyped(int buttoncode) noexcept;

        /**
         * @fn getMousePos
         * @brief sets two variables on current mouse position
         * @param xpos [double] x-coordinate
         * @param ypos [double] y-coordinate
         */

        inline static void getMousePos(double& xpos, double& ypos) noexcept;

    private:

        static double m_MouseX;                             /**< current mouse x - coordinate*/
        static double m_MouseY;                             /**< current mouse y - coordinate*/
        static bool m_Keys[MAX_KEYS];                       /**< current keys states*/
        static bool m_KeysState[MAX_KEYS];                  /**< keys states in previous frame*/
        static bool m_KeysTyped[MAX_KEYS];                  /**< keys witch were typed*/
        static bool m_MouseButtons[MAX_MOUSE_BUTTONS];      /**< current mouse buttons states*/
        static bool m_MouseButtonsState[MAX_MOUSE_BUTTONS]; /**< mouse buttons states in previous frame*/
        static bool m_MouseButtonsTyped[MAX_MOUSE_BUTTONS]; /**< mouse buttons witch were typed*/
    };

    bool InputManager::isKeyPressed(int keycode) noexcept {
        if(keycode >= MAX_KEYS) return false;
        return m_Keys[keycode];
    }

    bool InputManager::isKeyTyped(int keycode) noexcept {
        if(keycode >= MAX_KEYS) return false;
        return m_KeysTyped[keycode];
    }

    bool InputManager::isMouseButtonPressed(int buttoncode) noexcept {
        if(buttoncode >= MAX_MOUSE_BUTTONS) return false;
        return m_MouseButtons[buttoncode];
    }

    bool InputManager::isMouseButtonTyped(int buttoncode) noexcept {
        if(buttoncode >= MAX_MOUSE_BUTTONS) return false;
        return m_MouseButtonsTyped[buttoncode];
    }

    void InputManager::getMousePos(double &xpos, double &ypos) noexcept {
        xpos = InputManager::m_MouseX;
        ypos = InputManager::m_MouseY;
    }

    inline void key_callback([[maybe_unused]] GLFWwindow *window, int key,[[maybe_unused]] int scancode, int action,[[maybe_unused]] int mods) {
        Bald::Input::InputManager::m_Keys[key] = action != GLFW_RELEASE;
    }

    inline void mouse_button_callback([[maybe_unused]] GLFWwindow *window, int button, int action,[[maybe_unused]] int mods) {
        Bald::Input::InputManager::m_MouseButtons[button] = action != GLFW_RELEASE;
    }

    inline void cursor_position_callback([[maybe_unused]]GLFWwindow *window, double xpos, double ypos) {
        Bald::Input::InputManager::m_MouseX = xpos;
        Bald::Input::InputManager::m_MouseY = ypos;
    }

}
//BALD_ENGINE_INPUT_MANAGER_H
