//
// Created by grzegorz on 07.05.19.
//
#include "mouse_events.h"

namespace Bald {
    std::vector<FunctionHandler < MouseEvent>> MouseEvent::callbacks;
    std::vector<AsyncFunctionHandler < MouseEvent>> MouseEvent::async_callbacks;

    std::vector<FunctionHandler < MouseMovedEvent>> MouseMovedEvent::callbacks;
    std::vector<AsyncFunctionHandler < MouseMovedEvent>> MouseMovedEvent::async_callbacks;

    std::vector<FunctionHandler < MouseScrolledEvent>> MouseScrolledEvent::callbacks;
    std::vector<AsyncFunctionHandler < MouseScrolledEvent>> MouseScrolledEvent::async_callbacks;

    std::vector<FunctionHandler < MouseButtonPressedEvent>> MouseButtonPressedEvent::callbacks;
    std::vector<AsyncFunctionHandler < MouseButtonPressedEvent>> MouseButtonPressedEvent::async_callbacks;
}
