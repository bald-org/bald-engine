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
        /**  methods & functions  */

        /**
         * @fn                      Window
         * @param [std::string]     title
         * @param [int]             width
         * @param [int]             height
         * @brief                   constructor for the window
         */

        Window(const char* title = "Window", int width = 800, int height = 600, bool closed = false);

        /**
         * @fn                      ~Window
         * @brief                   destructor - destructs the window
         */

        ~Window();

        /**
         * @fn                      Update
         * @brief                   updates the window data
         */
        void Update() const;

        /**
         * @fn                      Closed
         * @brief                   updates the window data
         * @return [bool]           true  -> Window is closed
         *                          false -> Window is NOT closed
         */
        bool IsClosed() const;


    private:
        /**
         * @fn                      Init
         * @brief                   initializes the window
         * @return [bool]           true  -> Window has been initialized successfully
         *                          false -> Window couldn't have been initialized
         */
        bool Init() noexcept;

        // START OF ATTRIBUTES

    private:
        GLFWwindow *m_Window;

        const char* m_Title;

        int m_Width;
        int m_Height;

        bool m_Closed;
    };


}
