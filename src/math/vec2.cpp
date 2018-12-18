//
// Created by ajer on 16.12.18.
//

#include "vec2.h"

namespace Bald::Math {

    Vec2 Vec2::operator+(const Vec2& other)const noexcept{
        return Vec2(m_x + other.m_x, m_y + other.m_y);
    }


    Vec2 Vec2::operator-(const Vec2& other)const noexcept{
        return Vec2(m_x - other.m_x, m_y - other.m_y);
    }


    Vec2 Vec2::operator*(float multiplier) const noexcept{
        return Vec2(m_x * multiplier, m_y * multiplier);
    }


    Vec2& Vec2::operator+=(const Vec2& other)noexcept{
        m_x += other.m_x;
        m_y += other.m_y;

        return *this;
    }


    Vec2& Vec2::operator-=(const Vec2& other)noexcept{
        *this += other.Reverse();

        return *this;
    }


    Vec2& Vec2::operator*=(float multiplier)noexcept{
        m_x *= multiplier;
        m_y *= multiplier;

        return *this;
    }


    bool Vec2::operator==(const Vec2& other) const noexcept{
        return m_x == other.m_x && m_y == other.m_y;
    }


    bool Vec2::operator!=(const Vec2& other) const noexcept{
        return !(m_x == other.m_x && m_y == other.m_y);
    }


    Vec2 Vec2::MakeUnitVec(const Vec2& vec)noexcept{
        return Vec2(vec.m_x / vec.Len(),vec.m_y / vec.Len());
    }


    Vec2& Vec2::Normalize()noexcept{
        float len = Len();
        if(len != 0.0f){
            m_x /= len ;
            m_y /= len ;
        }
        return *this;
    }


    float Vec2::Len() const noexcept{
        return static_cast<float>(sqrt(pow(m_x, 2.0f) + pow(m_y, 2.0f)));
    }


    float Vec2::DotProduct(const Vec2 &other) const noexcept{
        return m_x * other.m_x + m_y * other.m_y;
    }


    Vec2 Vec2::Reverse()const noexcept{
        return Vec2(-1.0f * m_x, -1.0f * m_y);
    }


    std::ostream& operator<<(std::ostream& out, const Vec2& vec)noexcept{
        out << "[" << vec.m_x << ", " << vec.m_y << "]" << std::endl;
        return out;
    }


    float Vec2::AngleBetween(const Vec2& other)const noexcept{

        float dot = DotProduct(other);
        float len = Len() * other.Len();
        float radians = static_cast<float> (acos(dot/len));

        // degrees -> (radians * 180.0f ) / static_cast<float>(M_PI);
        return radians;
    }

}
// END OF NAMESPACE Bald::Math