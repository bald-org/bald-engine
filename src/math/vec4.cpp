//
// Created by blinku on 07.02.19.
//

#include "vec4.h"

namespace Bald::Math {
    Vec4 Vec4::MakeUnitVec(const Vec4& vec) noexcept {
        float len = vec.Length();
        if(len != 0)
            return Vec4(vec.GetX() / len, vec.GetY() / len, vec.GetZ() / len, vec.GetW() / len);
        CORE_LOG_WARN("[Vec4] Cannot make unit vector from zero vector!");
        return Vec4(0.0f, 0.0f, 0.0f, 0.0f);
    }

    std::ostream& operator<<(std::ostream& out, const Vec4& vec) noexcept {
        out << "[" << vec.m_X << ", " << vec.m_Y << ", " << vec.m_Z << ", " << vec.m_W << "]\n";
        return out;
    }

}