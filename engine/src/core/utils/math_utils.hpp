//
// Created by blinku on 09.02.19.
//

#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

namespace Bald::Utils {

    constexpr float ToRadians(float angleInDegrees) {
        return angleInDegrees / 180.0f * static_cast<float>(M_PI);
    }

    constexpr float ToDegrees(float angleInRadians) {
        return angleInRadians / static_cast<float>(M_PI) * 180.0f;
    }

} // END OF NAMESPACE Bald::Utils
