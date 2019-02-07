//
// Created by blinku on 07.02.19.
//

#include "vec2.h"

namespace Bald::Math {

    Vec2 Vec2::MakeUnitVec(const Vec2& vec) noexcept {
        float len = vec.Length();
        if(len != 0)
            return Vec2(vec.GetX() / len, vec.GetY() / len);
        CORE_LOG_WARN("[Vec2] Cannot make unit vector from zero vector!");
        return Vec2(0.0f, 0.0f);
    }

    std::ostream& operator<<(std::ostream& out, const Vec2& vec) noexcept {
        out << "[" << vec.m_X << ", " << vec.m_Y << "]\n";
        return out;
    }

}