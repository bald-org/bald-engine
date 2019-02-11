//
// Created by Piotr Moszkowicz on 2019-02-10.
//

#pragma once
#include "event.h"
#include "pch.h"

namespace Bald::Events {
    class OnWindowResizeEvent : public Event {
    public:
        constexpr OnWindowResizeEvent() = default;
        void run() noexcept override;
    };

    void OnWindowResizeEvent::run() noexcept {
        // CORE_LOG_INFO("OnWindowResizeEvent_Triggered");
        std::cout << "OnWindowResizeEvent_Triggered" << std::endl;
    }
}