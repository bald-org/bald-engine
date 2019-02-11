//
// Created by ajer on 11.02.19.
//

#include "Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Bald::Graphics {


    Window::Window(const char *title, int width, int height, bool closed, bool VSync)
            : m_Title(title), m_Width(width), m_Height(height), m_Closed(closed), m_VSync(VSync) {
        Window::Init();
    }

    void Window::Update() noexcept {
        if (!m_Closed) {
            glfwPollEvents();
            glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
            glViewport(0, 0, m_Width, m_Height);
            glfwSwapBuffers(m_Window);
        }
    }

    void Window::WindowSetVSync(bool enabled) noexcept {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_VSync = enabled;
    }


    bool Window::Init() noexcept {

        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
            CORE_LOG_ERROR("[Window] Failed to load GLAD!");
            exit(1);
        }

        if (!glfwInit()) {
            CORE_LOG_ERROR("[Window] Failed to init GLFW!");
            exit(1);
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

    void Window::ClearWindow() const noexcept { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }


    void Window::Shutdown() { glfwDestroyWindow(m_Window); }


    void Window::DestroyWindow() noexcept {
        m_Closed = true;
        glfwDestroyWindow(m_Window);
    }

    int Window::ShouldClose() const noexcept {
        return glfwWindowShouldClose(m_Window);
    }

}// END OF NAMESPACE BALD::GRAPHICS