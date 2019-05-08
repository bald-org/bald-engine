//
// Created by blinku on 08.05.19.
//

#pragma once

namespace Bald {

    class Layer {
    public:
        Layer() = default;

        virtual ~Layer() = default;

        void Attach() noexcept;

        void Detach() noexcept;

        virtual void RunEvents();

        virtual void Update() = 0;

        [[nodiscard]] bool IsAttached() const noexcept;

    private:
        bool m_Attached = true;
    }; // END OF CLASS Layer

} // END OF NAMESPACE Bald
