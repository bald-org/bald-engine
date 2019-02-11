//
// Created by ajer on 11.02.19.
//

#include "Window.h"

namespace Bald::Graphics {

    constexpr void Window::Update(){
        if (!m_Closed) {
            glfwPollEvents();
            glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
            glViewport(0, 0, m_Width, m_Height);
            glfwSwapBuffers(m_Window);
        }
    }

    bool Window::Init() noexcept {

        if (!glfwInit()) {
            CORE_LOG_ERROR("[Window] Failed to init a Window!");
            return false;
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
}