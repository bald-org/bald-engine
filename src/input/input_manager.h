//
// Created by grzegorz on 17.12.18.
//

#pragma once

#include "GLFW/glfw3.h"
#include "pch.h"

#define MAX_KEYS          1024
#define MAX_MOUSE_BUTTONS 64

/**
 * @class InputManager
 * @brief manages user's input
 */


namespace Bald::Input {

    using callback = std::function<void()>;

    class InputManager {

        friend void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

        friend void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

        friend void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);

    public:

        /**
         * @fn    constructor
         * @brief deleted
         */

        InputManager() = delete;

        /**
         * @fn    Init
         * @brief Initializes InputManager
         */

        static void Init(); //TODO: have to be called in window Initialization

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

        [[nodiscard]] inline static bool isKeyPressed(int keycode) noexcept;

        /**
         * @fn                   isKeyTyped
         * @brief                function that checks if key was typed
         * @param keycode [int]  GLFW macro e.g. GLfW_KEY_SPACE
         * @return        [bool] true if key was typed otherwise false
         */

        [[nodiscard]] inline static bool isKeyTyped(int keycode) noexcept;

        /**
         * @fn                      isMouseButtonPressed
         * @brief                   function that checks if mouse button was pressed
         * @param buttoncode [int]  GLFW macro e.g. GLFW_MOUSE_BUTTON_1
         * @return           [bool] true if button was pressed otherwise false
         */

        [[nodiscard]] inline static bool isMouseButtonPressed(int buttoncode) noexcept;

        /**
         * @fn                      isMouseButtonTyped
         * @brief                   function that checks if mouse button was typed
         * @param buttoncode [int]  GLFW macro e.g. GLFW_MOUSE_BUTTON_1
         * @return           [bool] true if button was typed otherwise false
         */

        [[nodiscard]] inline static bool isMouseButtonTyped(int buttoncode) noexcept;

        /**
         * @fn                  getMousePos
         * @brief               sets two variables on current mouse position
         * @param xpos [double] x-coordinate
         * @param ypos [double] y-coordinate
         */

        inline static void getMousePos(double &xpos, double &ypos) noexcept;

        /**
         * @fn                  SetKeyPressedCallback
         * @brief               sets function which will be called on key pressed event
         * @param keycode [int] GLFW key id
         * @param fun           function pointer
         * @param args          arguments for function
         */

        template <class F, class... Args>
        static void SetKeyPressedCallback(int keycode, F&& fun, Args&... args) noexcept;

        /**
         * @fn                             GetKeyPressedCallback
         * @brief                          getter for function callback
         * @param keycode [int]            GLFW key id
         * @return [std::function<void()>] callback
         */

        static inline callback GetKeyPressedCallback(int keycode) noexcept;

        /**
         * @fn                             RemoveKeyPressedCallback
         * @brief                          removes all previously set callbacks
         * @param keycode [int]            GLFW key id
         * @return [std::function<void()>] previously set callbacks
         */

        static callback RemoveKeyPressedCallback(int keycode) noexcept;

        /**
         * @fn                  EmitKeyPressedEvent
         * @brief               simulate Key pressed event
         * @param keycode [int] GLFW key id
         */

        static void EmitKeyPressedEvent(int keycode) noexcept;

        /**
         * @fn                  SetKeyTypedCallback
         * @brief               sets function which will be called on key typed event
         * @param keycode [int] GLFW key id
         * @param fun           function pointers
         * @param args          arguments for function
         */

        template<class F, class... Args>
        static void SetKeyTypedCallback(int keycode, F&& fun, Args&... args) noexcept;

        /**
         * @fn                             GetKeyTypedCallback
         * @brief                          getter for function callback
         * @param keycode [int]            GLFW key id
         * @return [std::function<void()>] callback
         */

        static inline callback GetKeyTypedCallback(int keycode) noexcept;

        /**
         * @fn                             RemoveKeyTypedCallback
         * @brief                          removes all previously set callbacks
         * @param keycode [int]            GLFW key id
         * @return [std::function<void()>] previously set callbacks
         */

        static callback RemoveKeyTypedCallback(int keycode) noexcept;

        /**
         * @fn                  EmitKeyTypedEvent
         * @brief               simulate Key typed event
         * @param keycode [int] GLFW key id
         */

        static void EmitKeyTypedEvent(int keycode) noexcept;

        /**
         * @fn                     SetMouseButtonPressedCallback
         * @brief                  sets function which will be called on mouse button pressed event
         * @param buttoncode [int] GLFW mouse button id
         * @param fun              function pointer
         * @param args             arguments for function
         */

        template<class F, class... Args>
        static void SetMouseButtonPressedCallback(int buttoncode, F&& fun, Args&... args) noexcept;

        /**
         * @fn                             GetMouseButtonPressedCallback
         * @brief                          getter for function callback
         * @param keycode [int]            GLFW key id
         * @return [std::function<void()>] callback
         */

        static inline callback GetMouseButtonPressedCallback(int buttoncode) noexcept;

        /**
         * @fn                             RemoveMouseButtonPressedCallback
         * @brief                          removes all previously set callbacks
         * @param keycode [int]            GLFW key id
         * @return [std::function<void()>] previously set callbacks
         */

        static callback RemoveMouseButtonPressedCallback(int buttoncode) noexcept;

        /**
         * @fn                  EmitMouseButtonPressedEvent
         * @brief               simulate Mouse Button Pressed event
         * @param keycode [int] GLFW key id
         */

        static void EmitMouseButtonPressedEvent(int buttoncode) noexcept;

        /**
         * @fn                     SetMouseButtonTypedCallback
         * @brief                  sets function which will be called on mouse button Typed event
         * @param buttoncode [int] GLFW mouse button id
         * @param fun              function pointer
         * @param args             arguments for function
         */

        template<class F, class... Args>
        static void SetMouseButtonTypedCallback(int buttoncode, F&& fun, Args&... args) noexcept;

        /**
         * @fn                             GetMouseButtonTypedCallback
         * @brief                          getter for function callback
         * @param keycode [int]            GLFw key id
         * @return [std::function<void()>] callback
         */

        static inline callback GetMouseButtonTypedCallback(int buttoncode) noexcept;

        /**
         * @fn                             RemoveMouseButtonTypedCallback
         * @brief                          removes all previously set callbacks
         * @param keycode [int]            GLFW key id
         * @return [std::function<void()>] previously set callbacks
         */

        static callback RemoveMouseButtonTypedCallback(int buttoncode) noexcept;

        /**
         * @fn                     EmitMouseButtonTypedEvent
         * @brief                  simulate Mouse Button Typed event
         * @param buttoncode [int] GLFW key id
         */

        static void EmitMouseButtonTypedEvent(int buttoncode) noexcept;


    private:

        static double m_MouseX;                                           /**< current mouse x - coordinate*/
        static double m_MouseY;                                           /**< current mouse y - coordinate*/
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

    bool InputManager::isKeyPressed(int keycode) noexcept {
        if (keycode >= MAX_KEYS) return false;
        return m_Keys[keycode];
    }

    bool InputManager::isKeyTyped(int keycode) noexcept {
        if (keycode >= MAX_KEYS) return false;
        return m_KeysTyped[keycode];
    }

    bool InputManager::isMouseButtonPressed(int buttoncode) noexcept {
        if (buttoncode >= MAX_MOUSE_BUTTONS) return false;
        return m_MouseButtons[buttoncode];
    }

    bool InputManager::isMouseButtonTyped(int buttoncode) noexcept {
        if (buttoncode >= MAX_MOUSE_BUTTONS) return false;
        return m_MouseButtonsTyped[buttoncode];
    }

    void InputManager::getMousePos(double &xpos, double &ypos) noexcept {
        xpos = InputManager::m_MouseX;
        ypos = InputManager::m_MouseY;
    }

    inline void key_callback([[maybe_unused]] GLFWwindow *window, int key, [[maybe_unused]] int scancode, int action,
                             [[maybe_unused]] int mods) {
        Bald::Input::InputManager::m_Keys[key] = action != GLFW_RELEASE;
    }

    inline void mouse_button_callback([[maybe_unused]] GLFWwindow *window, int button, int action, [[maybe_unused]] int mods) {
        Bald::Input::InputManager::m_MouseButtons[button] = action != GLFW_RELEASE;
    }

    inline void cursor_position_callback([[maybe_unused]]GLFWwindow *window, double xpos, double ypos) {
        Bald::Input::InputManager::m_MouseX = xpos;
        Bald::Input::InputManager::m_MouseY = ypos;
    }

    template<class F, class... Args>
    void InputManager::SetKeyPressedCallback(int keycode, F&& fun, Args&... args) noexcept {
        if (keycode >= MAX_KEYS) CORE_LOG_WARN("[InputManager] Wrong key id");
        else{
            auto prevfun = m_KeyPressedCallbacks[keycode];
            m_KeyPressedCallbacks[keycode] = [prevfun, fun, &args...](){
                prevfun();
                fun(args...);
            };
        }
    }

    callback InputManager::GetKeyPressedCallback(int keycode) noexcept{
        return m_KeyPressedCallbacks[keycode];
    }

    template<class F, class... Args>
    void InputManager::SetKeyTypedCallback(int keycode, F&& fun, Args&... args) noexcept{
        if (keycode >= MAX_KEYS) CORE_LOG_WARN("[InputManager] Wrong key id");
        else{
            auto prevfun = m_KeyTypedCallbacks[keycode];
            m_KeyTypedCallbacks[keycode] = [prevfun, fun, &args...](){
                prevfun();
                fun(args...);
            };
        }
    }

    callback InputManager::GetKeyTypedCallback(int keycode) noexcept{
        return m_KeyTypedCallbacks[keycode];
    }

    template<class F, class... Args>
    void InputManager::SetMouseButtonPressedCallback(int buttoncode, F&& fun, Args&... args) noexcept{
        if (buttoncode >= MAX_MOUSE_BUTTONS) CORE_LOG_WARN("[InputManager] Wrong mouse button id");
        else{
            auto prevfun = m_MouseButtonPressedCallbacks[buttoncode];
            m_MouseButtonPressedCallbacks[buttoncode] = [prevfun, fun, &args...](){
                prevfun();
                fun(args...);
            };
        }
    }

    callback InputManager::GetMouseButtonPressedCallback(int buttoncode) noexcept{
        return m_MouseButtonPressedCallbacks[buttoncode];
    }

    template<class F, class... Args>
    void InputManager::SetMouseButtonTypedCallback(int buttoncode, F&& fun, Args&... args) noexcept{
        if (buttoncode >= MAX_MOUSE_BUTTONS) CORE_LOG_WARN("[InputManager] Wrong mouse button id");
        else{
            auto prevfun = m_MouseButtonTypedCallbacks[buttoncode];
            m_MouseButtonTypedCallbacks[buttoncode] = [prevfun, fun, &args...](){
                prevfun();
                fun(args...);
            };
        }
    }

    callback InputManager::GetMouseButtonTypedCallback(int buttoncode) noexcept{
        return m_MouseButtonTypedCallbacks[buttoncode];
    }

}
//BALD_ENGINE_INPUT_MANAGER_H
