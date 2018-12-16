//
// Created by ajer on 16.12.18.
//

#include "vec2.h"

namespace Bald::Math {


    [[nodiscard]] constexpr Vec2 &Vec2::operator+(const Vec2 &other) noexcept {

        this->m_x += other.m_x;
        this->m_y += other.m_y;

        return *this;
    }

    [[nodiscard]] constexpr Vec2 &Vec2::operator*(double multiplier) noexcept {

        if (multiplier != 0.0) {
            this->m_y *= multiplier;
            this->m_x *= multiplier;
        }

        return *this;
    }

    double Vec2::Len() const {
        double length = sqrt(pow(this->m_x, 2.0) + pow(this->m_y, 2.0));

        return length;
    }


    double Vec2::ScalarProduct(const Vec2 &other) const {
        double product = this->m_x * other.m_x + this->m_y * other.m_y;

        return product;
    }

}