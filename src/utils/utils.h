//
// Created by blinku on 09.02.19.
//

#pragma once

namespace Bald::Utils {
    template<typename T>
    constexpr void ConstexprSwap(T& first, T& second) {
        T copy = first;
        first = second;
        second = copy;
    }
}
