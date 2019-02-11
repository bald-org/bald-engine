//
// Created by Piotr Moszkowicz on 2019-02-11.
//

#include "events.h"
#include "pch.h"
#include <iostream>

using namespace Bald;
using namespace Events;

int main() {
    EventManager::bind<OnWindowResizeEvent>();
    EventManager::run();

    EventManager::unbind<OnWindowResizeEvent>();
    EventManager::run();

    EventManager::bind<OnWindowResizeEvent>();
    EventManager::flush();
    EventManager::run();

    return 0;
}