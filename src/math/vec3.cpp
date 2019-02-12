//
// Created by blinku on 07.02.19.
//

#include "vec3.h"

namespace Bald::Math {

    Vec3 Vec3::MakeUnitVec(const Vec3& vec) noexcept {
        float len = vec.Length();
        if(len != 0)
            return Vec3(vec.GetX() / len, vec.GetY() / len, vec.GetZ() / len);
        CORE_LOG_WARN("[Vec3] Cannot make unit vector from zero vector!");
        return Vec3(0.0f, 0.0f, 0.0f);
    }

    std::ostream& operator<<(std::ostream& out, const Vec3& vec) noexcept {
        out << "[" << vec.m_X << ", " << vec.m_Y << ", " << vec.m_Z << "]\n";
        return out;
    }

}