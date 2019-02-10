//
// Created by Piotr Moszkowicz on 2019-02-10.
//

#pragma once
#include <iostream>

namespace Bald::Events {
    class Event {
    public:
        Event() = default;
        virtual ~Event() = default;
        virtual void run() noexcept = 0;
    };
}