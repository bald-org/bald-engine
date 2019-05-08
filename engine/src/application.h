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
     *        when building an application using Bald Engine.
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
        void PushLayer();

        template<class L>
        void PushOverlay();

        template<class L>
        void PopLayer();

        template<class L>
        void PopOverlay();

        /**
         * @fn                      Create
         * @brief                   Creates an application. This function should be implemented on the client's side.
         * @return [Application*]   Pointer to application instance
         */

        [[nodiscard]] static Application* Create() noexcept;

        /**
         * @fn                      Run
         * @brief                   Main loop
         */

        void Run();

    private:

        bool Init();

        void Shutdown();

    private:
        std::unique_ptr<Graphics::Window> m_Window; /**< Unique pointer to window provided by the Bald Engine. Currently our application  can use only one window */
        LayerStack m_LayerStack; /**< Main layer stack */
        bool m_Running; /**< State of the application */

    private:
        static const Application* m_Instance; /**< Application is a singleton, meaning only one instance of it can occur in a running program */
    }; // END OF APPLICATION CLASS

    template<class L>
    void Application::PushLayer() {
        static_assert(std::is_base_of<Layer, L>::value, "Layer is not the base of L");
        m_LayerStack.PushLayer(new L{});
    }

    template<class L>
    void Application::PushOverlay() {
        static_assert(std::is_base_of<Layer, L>::value, "Overlay is not the base of L");
        m_LayerStack.PushOverlay(new L{});
    }

    template<class L>
    void Application::PopLayer() {
        static_assert(std::is_base_of<Layer, L>::value, "Layer is not the base of L");
        m_LayerStack.PopLayer(new L{});
    }

    template<class L>
    void Application::PopOverlay() {
        static_assert(std::is_base_of<Layer, L>::value, "Overlay is not the base of L");
        m_LayerStack.PopOverlay(new L{});
    }

} // END OF NAMESPACE BALD


