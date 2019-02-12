//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once
#include "event.h"

namespace Bald::Events {
    struct WindowResizeEvent : public Event {
        inline constexpr WindowResizeEvent(unsigned int x, unsigned int y) noexcept : x(x), y(y) {}
        unsigned int x, y;
    };
}
