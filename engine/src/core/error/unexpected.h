//
// Created by grzegorz on 18.09.19.
//
#pragma once

namespace Bald {
    template <typename T>
    struct unexpected {
        constexpr explicit unexpected(const T& val): m_Value(val) { }
        constexpr operator T() const noexcept { return m_Value; }
        T m_Value;
    };
}




