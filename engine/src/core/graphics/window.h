//
// Created by ajer on 11.02.19.
//

#pragma once

#include "core.h"
#include "logger/logger.h"
#include "glad/glad.h"

struct GLFWwindow;

namespace Bald::Graphics {

    /**
     * @class Window
     * @brief Implementation of simple Window.
     */

    class Window {
    GENERATE_BODY(NORMAL)
    public:

        /**
         * @fn Window
         * @brief Window constructor.
         * @param [const char*] title.
         * @param [int] width.
         * @param [int] height.
         * @param [bool] vsync.
         */

        explicit Window(const char* title = "Window",
                        int width = 800,
                        int height = 600,
                        bool VSync = true);

        /**
         * @fn ~Window
         * @brief Destructor - terminates the m_Window.
         */

        ~Window() noexcept;


        /**
         * @fn Update
         * @brief Updates the window data i.a. poll events & swap buffers.
         */

        void Update() noexcept;


        /**
         * @fn Clear
         * @brief Clears buffer bit.
         */

        void Clear() const noexcept;


        /**
         * @fn SetVSync
         * @brief Enables/disables VSync.
         * @param bool true/false.
         */

        void SetVSync(bool enabled) noexcept;


        /**
         * @fn ShouldClose
         * @brief Checks whether or not window should be closed.
         * @return int glfwWindowShouldClose(m_Window).
         */

        [[nodiscard]] int ShouldClose() const noexcept;

        /**
         * @fn GetWindow
         * @brief GLFWwindow getter.
         * @return [GLFWwindow*] pointer to the m_Window.
         */

        [[nodiscard]] inline GLFWwindow* GetWindow() const noexcept { return m_Window; }

        /**
         * @fn GetTitle
         * @brief Title getter.
         * @return [const char*] pointer to the m_Title.
         */

        [[nodiscard]] inline const char* GetTitle() const noexcept { return m_Title; }

        /**
         * @fn GetWidth
         * @brief Width getter.
         * @return [int] m_Width component.
         */

        [[nodiscard]] inline int GetWidth() const noexcept { return m_Width; }

        /**
         * @fn GetHeight
         * @brief Height getter.
         * @return [int] m_Height component.
         */

        [[nodiscard]] inline int GetHeight() const noexcept { return m_Height; }

        /**
         * @fn GetVSync
         * @brief VSync Getter.
         * @return [int] m_VSync component.
         */

        [[nodiscard]] inline int GetVSync() const noexcept { return m_VSync; }

        /**
         * @fn GetAspectRatio
         * @brief Aspect ratio getter.
         * @return [float] Aspect ratio.
         */

        [[nodiscard]] inline float GetAspectRatio() const noexcept {
            return static_cast<float>(m_Width) / static_cast<float>(m_Height);
        }

    private:

        /**
         * @fn Init
         * @brief Attempts to initialize the window and returns success result (true/false).
         * @return [bool] true -> Window has been initialized successfully.
         *                false -> Window couldn't have been initialized.
         */

        [[nodiscard]] bool Init() noexcept;

       /**
        * @fn Shutdown
        * @brief Destroys the window.
        */

       void Shutdown();

    private:
        GLFWwindow* m_Window; /**< Pointer to window provided by GLFW */
        const char* m_Title;  /**< Window title */
        int m_Width;          /**< Current window width */
        int m_Height;         /**< Current window height */
        bool m_VSync;         /**< State of VSync */

    private:
        static bool m_GLFWInitialized; /**< State of GLFW initialization */
    }; // END OF WINDOW CLASS

} // END OF NAMESPACE BALD::GRAPHICS
