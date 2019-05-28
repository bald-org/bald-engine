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

    constexpr bool ConstexprStringCmp(const char* lhs, const char* rhs) {
        return *lhs == *rhs && (*lhs == '\0' || ConstexprStringCmp(lhs + 1, rhs + 1));
    }

} // END OF NAMESPACE Bald::Utils

#include "type_id.h"
#include "type_name.h"
#include "generate_body.h"