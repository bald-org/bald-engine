//
// Created by grzegorz on 07.05.19.
//

#include "window_events.h"

namespace Bald {
    std::vector<FunctionHandler < WindowEvent>> WindowEvent::callbacks;
    std::vector<AsyncFunctionHandler < WindowEvent>> WindowEvent::async_callbacks;

    std::vector<FunctionHandler < WindowResizedEvent>> WindowResizedEvent::callbacks;
    std::vector<AsyncFunctionHandler < WindowResizedEvent>> WindowResizedEvent::async_callbacks;

    std::vector<FunctionHandler < WindowClosedEvent>> callbacks;
    std::vector<AsyncFunctionHandler < WindowClosedEvent>> async_callbacks;
}