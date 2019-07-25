//
// Created by blinku on 25.07.2019.
//

#pragma once

namespace Bald::Utils {

    enum class BuiltInTypeSize : uint32_t {
        Bool            = sizeof(bool),
        Char            = sizeof(char),
        Int             = sizeof(int),
        ShortInt        = sizeof(short int),
        LongInt         = sizeof(long int),
        UnsignedLongInt = sizeof(unsigned long int),
        Float           = sizeof(float),
        Double          = sizeof(double),
        WChar_T         = sizeof(wchar_t)
    };

}