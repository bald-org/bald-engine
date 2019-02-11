//
// Created by ajer on 11.02.19.
//

#pragma once

#include <GLFW/glfw3.h>


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
         * @brief                   constructor for the window
         */
        explicit Window(const char *title = "Window", int width = 800, int height = 600,
                        bool closed = true)
                : m_Title(title), m_Width(width), m_Height(height), m_Closed(closed) {
            Window::Init();
        }

        /**
         * @fn                      ~Window
         * @brief                   destructor - terminates the m_Window
         */
        ~Window() noexcept { glfwTerminate(); } /** shouldn't be glfwDestroyWindow() ? */


        /**
         * @fn                      Update
         * @brief                   updates the window data i.a. poll events & swap buffers
         */
        void Update()noexcept;

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
        inline void ClearWindow() const noexcept { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }


        /** ========== GETTERS ========== */

        /**
         * @fn                      GetWindow
         * @brief                   returns m_Window component
         * @return [GLFWwindow*]    pointer to the m_Window
         */
        [[nodiscard]]  inline GLFWwindow *GetWindow() const noexcept { return m_Window; }

        /**
         * @fn                      GetTitle
         * @brief                   returns m_Title component
         * @return [const char*]    pointer to the m_Title
         */
        [[nodiscard]]  inline const char *GetTitle() const noexcept { return m_Title; }

        /**
         * @fn                      GetWidth
         * @brief                   returns the width of the Window
         * @return [int]            m_Width component
         */
        [[nodiscard]]  inline int GetWidth() const noexcept { return m_Width; }

        /**
         * @fn                      GetHeight
         * @brief                   returns the height of the Window
         * @return [int]            m_Height component
         */
        [[nodiscard]]  inline int GetHeight() const noexcept { return m_Height; }

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
    }; // END OF WINDOW CLASS
} // END OF NAMESPACE BALD::GRAPHICS
