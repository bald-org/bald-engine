//
// Created by ajer on 11.02.19.
//


#include "window.h"
#include "input_manager.h"
#include "event_manager.h"
#include "window_events.h"

#include "GLFW/glfw3.h"

namespace Bald::Graphics {

    bool Window::m_GLFWInitialized = false;

    Window::Window(const char* title, int width, int height, bool VSync) :
        m_Window(nullptr),
        m_Title(title),
        m_Width(width),
        m_Height(height),
        m_VSync(VSync) {
        [[maybe_unused]] bool state = Init();
        BALD_ASSERT(state, "Window", "Failed to initialized application", state);
    }

    Window::~Window() noexcept {
        Shutdown();
    }

    void Window::Update() noexcept {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    // TODO: Once we start rendering we will have to deal with:
    //       glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
    //       glViewport(0, 0, m_Width, m_Height);

    void Window::SetVSync(bool enabled) noexcept {
        enabled ? glfwSwapInterval(1) : glfwSwapInterval(0);

        m_VSync = enabled;
    }

    void Window::Clear() const noexcept {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    int Window::ShouldClose() const noexcept {
        return glfwWindowShouldClose(m_Window);
    }

    bool Window::Init() noexcept {
        CORE_LOG_INFO("[Window] Initializing window...");

        glfwSetErrorCallback([](int error, const char* desc) {
            CORE_LOG_ERROR("[Window]" + std::to_string(error) + std::string(desc));
        });

        if(!m_GLFWInitialized) {
            int success = glfwInit();

            if(!success) {
                CORE_LOG_ERROR("[Window] Failed to init GLFW!");
                exit(1);
            }

            m_GLFWInitialized = true;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifndef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, this);
        if(!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
            CORE_LOG_ERROR("[Window] Failed to load GLAD!");
            exit(1);
        }

        if(!m_Window) {
            glfwDestroyWindow(m_Window);
            CORE_LOG_ERROR("[Window] Failed to create a Window!");
            return false;
        }

        glfwSetWindowSizeCallback(m_Window, []([[maybe_unused]] GLFWwindow* window, int width, int height) {
            Window& win = *static_cast<Window*>(glfwGetWindowUserPointer(window));

            win.m_Width = width;
            win.m_Height = height;

            glViewport(0, 0, win.m_Width, win.m_Height);

            EventManager::Emit<WindowResizedEvent>(win.m_Width, win.m_Height);
        });

        glfwSetWindowCloseCallback(m_Window, []([[maybe_unused]] GLFWwindow* window) {
            EventManager::Emit<WindowClosedEvent>();
        });

        glfwSetKeyCallback(m_Window, Input::key_callback);

        glfwSetCharCallback(m_Window, Input::char_callback);

        glfwSetMouseButtonCallback(m_Window, Input::mouse_button_callback);

        glfwSetCursorPosCallback(m_Window, Input::cursor_position_callback);

        glfwSetScrollCallback(m_Window, Input::scroll_callback);


        m_VSync ? glfwSwapInterval(1) : glfwSwapInterval(0);

        CORE_LOG_INFO("[Window] Initialization was successful");

        return true;
    }

    void Window::Shutdown() {
        CORE_LOG_INFO("[Window] Shutting down window...");

        glfwDestroyWindow(m_Window);

        CORE_LOG_INFO("[Window] Shutdown was successful");
    }

} // END OF NAMESPACE BALD::GRAPHICS