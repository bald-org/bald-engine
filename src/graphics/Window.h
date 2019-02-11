//
// Created by ajer on 11.02.19.
//

#pragma once

class GLFWwindow;

namespace Bald::Graphics {

    /**
     * @class Window
     * @brief Implementation of simple Window
     */
    class Window {
    public:
        /** ========== METHODS ========== */

        /**
         * @fn                      Window
         * @param [std::string]     title
         * @param [int]             width
         * @param [int]             height
         * @param [bool             closed - is window closed
         * @param [bool]            vsync
         * @brief                   constructor for the window
         */
        explicit Window(const char* title = "Window", int width = 800, int height = 600,
                        bool closed = true, bool VSync = false);

        /**
         * @fn                      ~Window
         * @brief                   destructor - terminates the m_Window
         */
        ~Window() noexcept { Shutdown(); }


        /**
         * @fn                      Update
         * @brief                   updates the window data i.a. poll events & swap buffers
         */
        void Update() noexcept;

        /**
         * @fn                      IsClosed
         * @brief                   returns the m_Closed component
         * @return [bool]           true  -> Window is     closed
         *                          false -> Window is NOT closed
         */
        [[nodiscard]] inline bool IsClosed() const noexcept { return m_Closed; }

        /**
         * @fn                      DestroyWindow
         * @brief                   destroys the Window
         */
        void DestroyWindow() noexcept;

        /**
         * @fn                      ClearWindow
         * @brief                   clears buffer bit
         */
        void ClearWindow() const noexcept;

        /**
         * @fn                      Shutdown
         * @brief                   destroys the window
         */
        void Shutdown();


        /**
         * @fn                      SetVSync
         * @param [bool]            enabled
         * @brief                   sets VSync
         */
        void WindowSetVSync(bool enabled) noexcept;


        /**
         * @fn                      ShouldClose
         * @brief                   sets VSync
         * @return [int]            glfwWindowShouldClose(m_Window)
         */
        int ShouldClose() const noexcept;

        /** ========== GETTERS ========== */

        /**
         * @fn                      GetWindow
         * @brief                   returns m_Window component
         * @return [GLFWwindow*]    pointer to the m_Window
         */
        [[nodiscard]] inline GLFWwindow* GetWindow() const noexcept { return m_Window; }

        /**
         * @fn                      GetTitle
         * @brief                   returns m_Title component
         * @return [const char*]    pointer to the m_Title
         */
        [[nodiscard]] inline const char* GetTitle() const noexcept { return m_Title; }

        /**
         * @fn                      GetWidth
         * @brief                   returns the width of the Window
         * @return [int]            m_Width component
         */
        [[nodiscard]] inline int GetWidth() const noexcept { return m_Width; }

        /**
         * @fn                      GetHeight
         * @brief                   returns the height of the Window
         * @return [int]            m_Height component
         */
        [[nodiscard]] inline int GetHeight() const noexcept { return m_Height; }

        /**
         * @fn                      GetVSync
         * @brief                   returns the m_VSync
         * @return [int]            m_VSync component
         */
        [[nodiscard]] inline int GetVSync() const noexcept { return m_VSync; }

        /**
         * @fn                      GetAspectRatio
         * @brief                   returns aspect ratio: width / height
         * @return [float]
         */
        [[nodiscard]] inline float GetAspectRatio() const noexcept {
            return static_cast<float>(m_Width)/static_cast<float>(m_Height);
        }

    private:
        /**
         * @fn                      Init
         * @brief                   attempts to initialize the window and returns success result (true/false)
         * @return [bool]           true  -> Window has been initialized successfully
         *                          false -> Window couldn't have been initialized
         */
        bool Init() noexcept;

        // START OF ATTRIBUTES

    private:
        GLFWwindow* m_Window;
        const char* m_Title;
        int m_Width;        //
        int m_Height;       // should these two be of type GLInt ?
        bool m_Closed;
        bool m_VSync;
    }; // END OF WINDOW CLASS
} // END OF NAMESPACE BALD::GRAPHICS
