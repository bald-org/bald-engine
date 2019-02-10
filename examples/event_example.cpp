//
// Created by Piotr Moszkowicz on 2019-02-11.
//

#include "events.h"
#include <iostream>

using namespace Bald;
using namespace Events;

int main() {
    auto on_window_resize_event = new OnWindowResizeEvent();
    EventManager::bind(on_window_resize_event);
    EventManager::run();

    return 0;
};