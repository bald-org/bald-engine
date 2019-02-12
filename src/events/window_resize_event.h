//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once
#include "event.h"

namespace Bald::Events {
    struct WindowResizeEvent : public Event {
        WindowResizeEvent(unsigned int x, unsigned int y) : x(x), y(y) {}
        unsigned int x, y;
    };
}
