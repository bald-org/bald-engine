//
// Created by blinku on 09.02.19.
//

#pragma once

#include <cmath>

namespace Bald::Utils {

    constexpr float ToRadians(float angleInDegrees) {
        return angleInDegrees / 180.0f * static_cast<float>(M_PI);
    }

    constexpr float ToDegrees(float angleInRadians) {
        return angleInRadians / static_cast<float>(M_PI) * 180.0f;
    }

} // END OF NAMESPACE Bald::Utils
