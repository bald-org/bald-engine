//
// Created by ajer on 11.02.19.
//

#include "Window.h"



namespace Bald::Graphics {

    Window::Window(const char* title, int width, int height, bool VSync) :
            m_Title(title),
            m_Width(width),
            m_Height(height),
            m_VSync(VSync)
    {
            Init();
    }

    Window::~Window() noexcept {
        glfwDestroyWindow(m_Window);
        /** Shutdown(); */
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

        glfwInit();

        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
            CORE_LOG_ERROR("[Window] Failed to load GLAD!");
            exit(1);
        }

        if (!glfwInit()) {
            CORE_LOG_ERROR("[Window] Failed to init GLFW!");
            exit(1);
        }


        if (!m_Window) {
            glfwTerminate();
            CORE_LOG_ERROR("[Window] Failed to create a Window!");
            return false;
        }


        return true;
    }

    void Window::Clear() const noexcept { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }


    /**
     * void Window::Shutdown() {glfwDestroyWindow(m_Window);}
     *
     * not needed atm
     */


    int Window::ShouldClose() const noexcept {
        return glfwWindowShouldClose(m_Window);
    }

}// END OF NAMESPACE BALD::GRAPHICS