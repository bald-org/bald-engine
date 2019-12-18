//
// Created by blinku on 06.05.19.
//

#pragma once

#include <memory>
#include "layer_stack.h"
#include "graphics/window.h"
#include "controllers/time_controller.hpp"

namespace Bald {

    /**
     * @class Application
     * @brief Simple application interface. This is the class that one should derive from
     *        when building an application using Bald Engine.
     */

    class Application {
    GENERATE_BODY(BASE)
    public:

        /**
         * @fn Application
         * @brief Application constructor
         */

        Application();

        /**
         * @fn ~Application
         * @brief Application destructor
         */

        virtual ~Application();

        /**
         * @fn PushLayer
         * @brief Templated method which pushes a layer onto the layer stack.
         *        It does it at the AFTER all OnUpdate/RunEvent calls.
         * @tparam [L] This template parameter must be a class derived from Layer class.
         * @tparam [... Args] This template parameter is optional. It is used to pass right arguments to the Layer's constructor.
         * @param [Args&& ...] args -> This parameter is optional. Variadic number of arguments for Layer's constructor.
         */

        template<typename L, typename ... Args>
        void PushLayer(Args&& ... args);

        /**
         * @fn PushOverlay
         * @brief Templated method which pushes an overlay onto the layer stack.
         *        It does it at the AFTER all OnUpdate/RunEvent calls.
         * @tparam [L] This template parameter must be a class derived from Layer class.
         * @tparam [... Args] This template parameter is optional. It is used to pass right arguments to the Layer's constructor.
         * @param [Args&& ...] args -> This parameter is optional. Variadic number of arguments for Layer's constructor.
         */

        template<typename L, typename ... Args>
        void PushOverlay(Args&& ... args);

        /**
         * @fn PopLayer
         * @brief Templated method which pops a layer from the layer stack.
         *        It does it at the AFTER all OnUpdate/RunEvent calls.
         * @tparam [L] This template parameter must be a class derived from Layer class.
         */

        template<typename L>
        void PopLayer();

        /**
         * @fn PopOverlay
         * @brief Templated method which pops an overlay from the layer stack.
         *        It does it at the AFTER all OnUpdate/RunEvent calls.
         * @tparam [L] This template parameter must be a class derived from Layer class.
         */

        template<typename L>
        void PopOverlay();

        /**
         * @fn PushLayerImmediately
         * @brief Templated method which pushes a layer onto the layer stack as soon as the method is called.
         * @tparam [L] This template parameter must be a class derived from Layer class.
         * @tparam [... Args] This template parameter is optional. It is used to pass right arguments to the Layer's constructor.
         * @param [Args&& ...] args -> This parameter is optional. Variadic number of arguments for Layer's constructor.
         */

        template<typename L, typename ... Args>
        void PushLayerImmediately(Args&& ... args);

        /**
         * @fn PushOverlayImmediately
         * @brief Templated method which pushes an overlay onto the layer stack as soon as the method is called.
         * @tparam [L] This template parameter must be a class derived from Layer class.
         * @tparam [... Args] This template parameter is optional. It is used to pass right arguments to the Layer's constructor.
         * @param [Args&& ...] args -> This parameter is optional. Variadic number of arguments for Layer's constructor.
         */

        template<typename L, typename ... Args>
        void PushOverlayImmediately(Args&& ... args);

        /**
         * @fn PopLayerImmediately
         * @brief Templated method which pops a layer from the layer stack as soon as the method is called.
         * @tparam [L] This template parameter must be a class derived from Layer class.
         */

        template<typename L>
        void PopLayerImmediately();

        /**
         * @fn PopOverlayImmediately
         * @brief Templated method which pops an overlay from the layer stack as soon as the method is called.
         * @tparam [L] This template parameter must be a class derived from Layer class.
         */

        template<typename L>
        void PopOverlayImmediately();

        /**
         * @fn GetWindow
         * @brief Window getter.
         * @return [std::unique_ptr<Graphics::Window>] Pointer to window instance
         */

        [[nodiscard]] inline std::weak_ptr<Graphics::Window> GetWindow() noexcept;

        /**
         * @fn Create
         * @brief Creates an application. This function should be implemented on the client's side.
         * @return [Application*] Pointer to application instance
         */

        [[nodiscard]] static Application* Create() noexcept;

        /**
         * @fn Create
         * @brief Creates an application. This function should be implemented on the client's side.
         * @return [Application*] Pointer to application instance
         */

        [[nodiscard]] inline static Application& GetApplication() noexcept;

        /**
         * @fn Run
         * @brief Main loop
         */

        void Run();

    private:

        /**
         * @fn Init
         * @brief Attempts to initialize the application and returns success result (true/false)
         * @return [bool] true -> application has been initialized successfully
         *                false -> application wasn't initialized
         */

        [[nodiscard]] bool Init() noexcept;

        /**
         * @fn Shutdown
         * @brief Destroys the application
         */

        void Shutdown();

    private:
        bool m_Running; /**< State of the application */
        std::unique_ptr<EventManager> m_EventManager; /** < Pointer to Main Event Manager >*/
        std::shared_ptr<Graphics::Window> m_Window; /**< Unique pointer to window provided by the Bald Engine. Currently our application  can use only one window */
        LayerStack m_LayerStack; /**< Main layer stack */
        Controllers::TimeController m_TimeController; /**< Primary controller that is responsible for handling delta time */

    private:
        static Application* m_Instance; /**< Application is a singleton, meaning only one instance of it can occur in a running program */

    }; // END OF CLASS Application

    template<typename L, typename ... Args>
    void Application::PushLayer(Args&& ... args) {
        m_LayerStack.PushLayer<L>(args ...);
    }

    template<typename L, typename ... Args>
    void Application::PushOverlay(Args&& ... args) {
        m_LayerStack.PushOverlay<L>(args ...);
    }

    template<class L>
    void Application::PopLayer() {
        m_LayerStack.PopLayer<L>();
    }

    template<class L>
    void Application::PopOverlay() {
        m_LayerStack.PopOverlay<L>();
    }

    template<typename L, typename ... Args>
    void Application::PushLayerImmediately(Args&& ... args) {
        m_LayerStack.PushLayerImmediately<L>(args ...);
    }

    template<typename L, typename ... Args>
    void Application::PushOverlayImmediately(Args&& ... args) {
        m_LayerStack.PushOverlayImmediately<L>(args ...);
    }

    template<class L>
    void Application::PopLayerImmediately() {
        m_LayerStack.PopLayerImmediately<L>();
    }

    template<class L>
    void Application::PopOverlayImmediately() {
        m_LayerStack.PopOverlayImmediately<L>();
    }

    inline std::weak_ptr<Graphics::Window> Application::GetWindow() noexcept {
        return m_Window;
    }

    inline Application& Application::GetApplication() noexcept {
        return *m_Instance;
    }

} // END OF NAMESPACE Bald


