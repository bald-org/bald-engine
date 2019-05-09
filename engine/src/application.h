//
// Created by blinku on 06.05.19.
//

#pragma once

#include <memory>
#include "window.h"
#include "event_manager.h"

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

        virtual ~Application() = default;

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
        bool m_Running; /**< State of the application */
        std::unique_ptr<EventManager> m_EventManager; /** < pointer to Main Event Manager >*/
        std::unique_ptr<Graphics::Window> m_Window; /**< Unique pointer to window provided by the Bald Engine. Currently our application  can use only one window */
    private:
        static const Application* m_Instance; /**< Application is a singleton, meaning only one instance of it can occur in a running program */
    }; // END OF APPLICATION CLASS

} // END OF NAMESPACE BALD


