//
// Created by grzegorz on 18.09.19.
//
#pragma once

namespace Bald {
    template <typename T>
    struct unexpected {
        explicit unexpected(const T& val): value(val) { }
        T value;
    };
}




