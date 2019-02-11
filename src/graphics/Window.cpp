//
// Created by ajer on 11.02.19.
//

#include "Window.h"

namespace Bald::Graphics {

    Window::Window(const char* title, int width, int height, bool closed)
            : m_Title(title), m_Width(width), m_Height(height), m_Closed(closed) {
        Init();
    }

    Window::~Window() {
        glfwTerminate();
    }


    void Window::Update() const {
        if(!m_Closed){
            glfwPollEvents();
            glfwSwapBuffers(m_Window);
        }

    }


    bool Window::Init() noexcept {

        if (!glfwInit()) {
            CORE_LOG_ERROR("[Window.Init] Failed to init a Window!");

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


    bool Window::IsClosed() const {

        return glfwWindowShouldClose(m_Window);
    }


}