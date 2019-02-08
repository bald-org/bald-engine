//
// Created by blinku on 07.02.19.
//

#pragma once

namespace Bald::Math {
    template<typename T>
    constexpr void ConstexprSwap(T& first, T& second) {
        T copy = first;
        first = second;
        second = copy;
    }
}

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

