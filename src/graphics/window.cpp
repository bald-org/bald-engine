//
// Created by ajer on 11.02.19.
//

#include "window.h"
#include "input_manager.h"
#include "event_manager.h"
#include "window_events.h"

namespace Bald::Graphics {

    Window::Window(const char* title, int width, int height, bool VSync) :
        m_Title(title),
        m_Width(width),
        m_Height(height),
        m_VSync(VSync) {
        assert(Init());
    }

    Window::~Window() noexcept {
        Shutdown();
    }

    void Window::Update() noexcept {
        Input::InputManager::Update(); // TODO: This should probably be called somewhere else ~Blinku
        EventManager::Flush(); // TODO: This should probably be called somewhere else ~Blinku

        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    /** TODO: Callbacks
     * glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
     * glViewport(0, 0, m_Width, m_Height);
     */

    void Window::WindowSetVSync(bool enabled) noexcept {
        if(enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_VSync = enabled;
    }

    void Window::Clear() const noexcept { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }

    int Window::ShouldClose() const noexcept {
        return glfwWindowShouldClose(m_Window);
    }

    bool Window::Init() noexcept {

        glfwInit();

        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        if(!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
            CORE_LOG_ERROR("[Window] Failed to load GLAD!");
            exit(1);
        }

        if(!glfwInit()) {
            CORE_LOG_ERROR("[Window] Failed to init GLFW!");
            exit(1);
        }


        if(!m_Window) {
            glfwTerminate();
            CORE_LOG_ERROR("[Window] Failed to create a Window!");
            return false;
        }

        glfwSetWindowSizeCallback(m_Window, []([[maybe_unused]] GLFWwindow* window, int width, int height) {
            Window& win = *static_cast<Window*>(glfwGetWindowUserPointer(window));

            win.m_Width = width;
            win.m_Height = height;

            EventManager::Emit<WindowResizedEvent>(win.m_Width, win.m_Height);
        });

        glfwSetWindowCloseCallback(m_Window, []([[maybe_unused]] GLFWwindow* window) {
            EventManager::Emit<WindowClosedEvent>();
        });

        glfwSetKeyCallback(m_Window, Input::key_callback);

        glfwSetMouseButtonCallback(m_Window, Input::mouse_button_callback);

        glfwSetCursorPosCallback(m_Window, Input::cursor_position_callback);

        // TODO: Set glfwSetScrollCallback, glfwSetCharCallback

        return true;
    }

    void Window::Shutdown() {
        EventManager::CleanUp(); // TODO: This should probably be called somewhere else ~Blinku
        glfwDestroyWindow(m_Window);
    }

}// END OF NAMESPACE BALD::GRAPHICS