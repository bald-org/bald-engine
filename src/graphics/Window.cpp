//
// Created by ajer on 11.02.19.
//

#include "Window.h"

namespace Bald::Graphics {

    void Window::Update() noexcept {
        if (!m_Closed) {
            glfwPollEvents();
            glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
            glViewport(0, 0, m_Width, m_Height);
            glfwSwapBuffers(m_Window);
        }
    }

    bool Window::Init() noexcept {

        if (!m_Closed) {
            CORE_LOG_WARN("[Window] Window already opened!"); // or CORE_LOG_ERROR ?
            return false;
        }
        /**Not sure about this ^ */

        if (!glfwInit()) {
            CORE_LOG_ERROR("[Window] Failed to init a Window!");
            return false;

            /** how about RE-INIT attempt here? */

        }

        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

        if (!m_Window) {
            glfwTerminate();
            CORE_LOG_ERROR("[Window] Failed to create a Window!");
            return false;
        }

        m_Closed = false;
        glfwMakeContextCurrent(m_Window);

        return true;
    }

    void Window::DestroyWindow() noexcept {
        m_Closed = true;

        glfwDestroyWindow(m_Window);
    }
}