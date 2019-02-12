//
// Created by ajer on 11.02.19.
//

#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Bald::Graphics {

    Window::Window(GLFWwindow* glfwwindow, const char* title, int width, int height, bool VSync):
        m_Window(glfwwindow),
        m_Title(title),
        m_Width(width),
        m_Height(height),
        m_VSync(VSync)
    {
        Window::Init();
    }

    Window::~Window() noexcept {
        Shutdown();
    }

    void Window::Update() noexcept {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    /** TODO: Callbacks
     * glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
     * glViewport(0, 0, m_Width, m_Height);
     */

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


        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);

        if (!m_Window) {
            glfwTerminate();
            CORE_LOG_ERROR("[Window] Failed to create a Window!");
            return false;
        }

        glfwMakeContextCurrent(m_Window);


        return true;
    }

    void Window::Clear() const noexcept { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }


    void Window::Shutdown() {
        glfwDestroyWindow(m_Window);
    }


    int Window::ShouldClose() const noexcept {
        return glfwWindowShouldClose(m_Window);
    }

}// END OF NAMESPACE BALD::GRAPHICS