//
// Created by blinku on 08.05.19.
//

#pragma once

#include <typeindex>

namespace Bald {

    class Layer {
    public:
        Layer() = default;

        virtual ~Layer() = default;

        virtual void OnAttach() noexcept = 0;

        virtual void OnDetach() noexcept = 0;

        virtual void Update() = 0;

        virtual void RunEvents();

        void Enable() noexcept;

        void Disable() noexcept;

        [[nodiscard]] inline bool IsEnabled() const noexcept;

        [[nodiscard]] virtual std::type_index GetType() const = 0;

    private:
        bool m_IsEnabled = true;
    }; // END OF CLASS Layer

    inline bool Layer::IsEnabled() const noexcept {
        return m_IsEnabled;
    }

} // END OF NAMESPACE Bald
