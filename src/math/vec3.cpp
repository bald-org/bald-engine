//
// Created by ajer on 30.12.18.
//

#include "vec3.h"


namespace Bald::Math {
    Vec3 Vec3::operator+(const Vec3 &other) const noexcept {
        return Vec3(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z);
    }


    Vec3 Vec3::operator-(const Vec3 &other) const noexcept {
        return Vec3(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z);
    }


    Vec3 Vec3::operator*(float multiplier) const noexcept {
        return Vec3(m_x * multiplier, m_y * multiplier, m_z * multiplier);
    }


    Vec3 &Vec3::operator+=(const Vec3 &other) noexcept {
        m_x += other.m_x;
        m_y += other.m_y;
        m_z += other.m_z;

        return *this;
    }


    Vec3 &Vec3::operator-=(const Vec3 &other) noexcept {
        *this += other.Reverse();

        return *this;
    }


    Vec3 &Vec3::operator*=(float multiplier) noexcept {
        m_x *= multiplier;
        m_y *= multiplier;
        m_z *= multiplier;

        return *this;
    }


    bool Vec3::operator==(const Vec3 &other) const noexcept {
        return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z;
    }


    bool Vec3::operator!=(const Vec3 &other) const noexcept {
        return !(m_x == other.m_x && m_y == other.m_y && m_z == other.m_z);
    }


    Vec3 Vec3::MakeUnitVec(const Vec3 &vec) noexcept {
        float len = vec.Len();
        return Vec3(vec.m_x / len, vec.m_y / len, vec.m_z / len);
    }


    Vec3 &Vec3::Normalize() noexcept {
        float len = Len();
        if (len != 0.0f) {
            m_x /= len;
            m_y /= len;
            m_z /= len;
        }
        return *this;
    }


    float Vec3::Len() const noexcept {
        return static_cast<float>(sqrt(m_x * m_x + m_y * m_y + m_z * m_z));
    }


    float Vec3::DotProduct(const Vec3 &other) const noexcept {
        return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
    }

    Vec3 Vec3::CrossProduct(const Vec3 &other) const noexcept {
        return Vec3(m_y * other.m_z - m_z * other.m_y,
                    m_z * other.m_x - m_x * other.m_z,
                    m_x * other.m_y - m_y * other.m_x
        );

    }


    Vec3 Vec3::Reverse() const noexcept {
        return Vec3(-1.0f * m_x, -1.0f * m_y, -1.0f * m_z);
    }


    std::ostream &operator<<(std::ostream &out, const Vec3 &vec) noexcept {
        out << "[" << vec.m_x << ", " << vec.m_y << ", " << vec.m_z << "]" << std::endl;
        return out;
    }


    float Vec3::AngleBetween(const Vec3 &other) const noexcept {
        float dot = DotProduct(other);
        float len = Len() * other.Len();
        float radians = static_cast<float> (acos(dot / len));

        return radians;
    }


} // END OF NAMESPACE BALD::MATH
