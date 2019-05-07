//
// Created by blinku on 06.05.19.
//

#pragma once

#include <memory>
#include "window.h"

namespace Bald {

    class Application {
    public:
        Application();
        virtual ~Application();

        [[nodiscard]] static Application* Create() noexcept;

        void Run();

    private:
        std::unique_ptr<Graphics::Window> m_Window;
        bool m_Running;
    private:
        static Application* m_Instance;
    }; // END OF APPLICATION CLASS

} // END OF NAMESPACE BALD


