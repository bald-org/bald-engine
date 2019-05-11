//
// Created by blinku on 06.05.19.
//

#pragma once

#include <memory>
#include "window.h"
#include "layer_stack.h"

namespace Bald {

    /**
     * @class Application
     * @brief Simple application interface. This is the class that one should derive from
     *        when building an application using Bald Engine
     */

    class Application {
    public:

        /**
         * @fn                      Application
         * @brief                   Application constructor
         */

        Application();

        /**
         * @fn                      ~Application
         * @brief                   Application destructor
         */

        virtual ~Application();

        template<class L>
        void PushLayerImmediately();

        template<class L>
        void PushOverlayImmediately();

        template<class L>
        void PopLayerImmediately();

        template<class L>
        void PopOverlayImmediately();

        /**
         * @fn                      Create
         * @brief                   Creates an application. This function should be implemented on the client's side.
         * @return [Application*]   Pointer to application instance
         */

        [[nodiscard]] static Application* Create() noexcept;

        /**
         * @fn                      Create
         * @brief                   Creates an application. This function should be implemented on the client's side.
         * @return [Application*]   Pointer to application instance
         */

        [[nodiscard]] static Application& GetApplication() noexcept;

        /**
         * @fn                      Run
         * @brief                   Main loop
         */

        void Run();

    private:

        /**
         * @fn                      Init
         * @brief                   Attempts to initialize the application and returns success result (true/false)
         * @return [bool]           true  -> application has been initialized successfully
         *                          false -> application couldn't have been initialized
         */

        [[nodiscard]] bool Init() noexcept;

        /**
         * @fn                      Shutdown
         * @brief                   Destroys the application
         */

        void Shutdown();

    private:
        bool m_Running; /**< State of the application */
        std::unique_ptr<EventManager> m_EventManager; /** < Pointer to Main Event Manager >*/
        std::unique_ptr<Graphics::Window> m_Window; /**< Unique pointer to window provided by the Bald Engine. Currently our application  can use only one window */
        LayerStack m_LayerStack; /**< Main layer stack */

    private:
        static Application* m_Instance; /**< Application is a singleton, meaning only one instance of it can occur in a running program */

    }; // END OF CLASS Application

    template<class L>
    void Application::PushLayerImmediately() {
        m_LayerStack.PushLayerImmediately<L>();
    }

    template<class L>
    void Application::PushOverlayImmediately() {
        m_LayerStack.PushOverlayImmediately<L>();
    }

    template<class L>
    void Application::PopLayerImmediately() {
        m_LayerStack.PopLayerImmediately<L>();
    }

    template<class L>
    void Application::PopOverlayImmediately() {
        m_LayerStack.PopOverlayImmediately<L>();
    }

} // END OF NAMESPACE Bald


