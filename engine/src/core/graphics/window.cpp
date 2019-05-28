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
        m_Title(title),
        m_Width(width),
        m_Height(height),
        m_VSync(VSync) {
        [[maybe_unused]] bool state = Init();
        assert(state);
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

    void Window::WindowSetVSync(bool enabled) noexcept {
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

        if(!m_GLFWInitialized) {
            int success = glfwInit();

            if(!success) {
                CORE_LOG_ERROR("[Window] Failed to init GLFW!");
                exit(1);
            }

            m_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
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

            EventManager::Emit<WindowResizedEvent>(win.m_Width, win.m_Height);
        });

        glfwSetWindowCloseCallback(m_Window, []([[maybe_unused]] GLFWwindow* window) {
            EventManager::Emit<WindowClosedEvent>();
        });

        glfwSetKeyCallback(m_Window, Input::key_callback);

        // TODO: Not really sure how to decouple text handling from input handling right now.
        //       We do not need it now though. This callback will have to be set in the future: glfwSetCharCallback

        glfwSetMouseButtonCallback(m_Window, Input::mouse_button_callback);

        glfwSetCursorPosCallback(m_Window, Input::cursor_position_callback);

        glfwSetScrollCallback(m_Window, Input::scroll_callback);

        CORE_LOG_INFO("[Window] Initialization was successful");

        return true;
    }

    void Window::Shutdown() {
        CORE_LOG_INFO("[Window] Shutting down window...");

        glfwDestroyWindow(m_Window);

        CORE_LOG_INFO("[Window] Shutdown was successful");
    }

} // END OF NAMESPACE BALD::GRAPHICS