//
// Created by ajer on 16.12.18.
//

#pragma once

#include <iostream>
#include "pch.h"

/**
 * @class Vec2
 * @brief vector 2 class
 */

namespace Bald::Math {

    class Vec2 {
    public:
        /**
        * @fn                          Vec2
        * @brief                       constructor
        * @param [float]               x variable
        * @param [float]               y variable
        */
        explicit constexpr Vec2(float x = 0.0f, float y = 0.0f)
            : m_X(x), m_Y(y) {}

        /**
        * @fn                          MakeUnitVec
        * @brief                       creates unit vector with the length of 1.0f
        * @param [const Vec2&]         vec -> vector which will be used to create unit vector
        * @return [Vec2]               unit long vector
        */
        [[nodiscard]] static Vec2 MakeUnitVec(const Vec2& vec) noexcept;

        /**
         * @fn                          Normalize
         * @brief                       normalizes vector to the length of 1.0f
         *                              (divides each component by the length of the vector)
         * @return [Vec2&]              unit long vector
         */
        constexpr void Normalize() noexcept;

        /**
        * @fn                          MakeReverseVec
        * @brief                       creates reverse vector of a given vector
        * @param [const Vec2&]         vec -> vector which will be used to create reversed vector
        * @return [Vec2]               new, reversed vector
        */
        [[nodiscard]] static constexpr Vec2 MakeReverseVec(const Vec2& vec) noexcept;

        /**
         * @fn                         Reverse
         * @brief                      reverses the current vector
         * @return [void]
         */
        constexpr void Reverse() noexcept;

        /**
         * @fn                          DotProduct
         * @brief                       calculates dot product of two vectors
         * @param [const Vec2&]         vec1 vector
         * @param [const Vec2&]         vec2 vector
         * @return [float]              dot product of the vector passed in
         */
        [[nodiscard]] static constexpr float DotProduct(const Vec2& vec1, const Vec2& vec2) noexcept;

        /**
         * @fn                          AngleBetween
         * @brief                       returns angle in RADIANS between two vectors
         * @param [const Vec2&]         vec1 vector
         * @param [const Vec2&]         vec2 vector
         * @return [float]              angle in radians
         */
        [[nodiscard]] static constexpr float AngleBetween(const Vec2& vec1, const Vec2& vec2) noexcept;

        /**
         * @fn                          Length
         * @brief                       calculates the length of the vector
         * @return [float]              length of the vector
         */
        [[nodiscard]] constexpr float Length() const noexcept;

        /**
         * @fn                          operator+
         * @brief                       adds another vector to the current vector
         * @param [const Vec2&]         other vector
         * @return [Vec2]               new vector
         */
        [[nodiscard]] constexpr Vec2 operator+(const Vec2& other) const noexcept;


        /**
         * @fn                          operator-
         * @brief                       subtracts another vector from the current vector
         * @param [const Vec2&]         other vector
         * @return [Vec2]               new vector
         */
        [[nodiscard]] constexpr Vec2 operator-(const Vec2& other) const noexcept;

        /**
         * @fn                          operator*
         * @brief                       multiplies current vector by the passed multiplier
         * @param [float]               multiplier
         * @return [Vec2]               new vector
         */
        [[nodiscard]] constexpr Vec2 operator*(float multiplier) const noexcept;

        /**
         * @fn                          operator+=
         * @brief                       adds another vector to the current vector
         * @param [const Vec2&]         other vector
         * @return [Vec2&]              current vector added with the passed vector
         */
        constexpr Vec2& operator+=(const Vec2& other) noexcept;

        /**
         * @fn                          operator-=
         * @brief                       adds reversed other vector to the current vector
         * @param [const Vec2&]         other vector
         * @return [Vec2&]              current vector subtracted with the passed vector
         */
        constexpr Vec2& operator-=(const Vec2& other) noexcept;

        /**
         * @fn                          operator*=
         * @brief                       multiplies current vector by the passed multiplier
         * @param [const Vec23&]         other vector
         * @return [Vec2&]              current vector multiplied by the passed multiplier
         */
        constexpr Vec2& operator*=(float multiplier) noexcept;

        /**
         * @fn                          operator==
         * @brief                       checks if the two vectors are the same
         * @param [const Vec2&]          other vector
         * @return [bool]               true  - vectors are     the same
         *                              false - vectors are NOT the same
         */
        [[nodiscard]] constexpr bool operator==(const Vec2& other) const noexcept;

        /**
         * @fn                          operator!=
         * @brief                       checks if the two vectors are NOT the same
         * @param [const Vec2&]          other vector
         * @return [bool]               true  - vectors are NOT the same
         *                              false - vectors are     the same
         */
        [[nodiscard]] constexpr bool operator!=(const Vec2& other) const noexcept;

        /**
         * @fn                          operator[]
         * @brief                       returns number in vector at certain index
         * @param [int]                 index -> index of a number which you want to retrieve
         * @return [const float&]       float at given index
         */
        [[nodiscard]] constexpr const float& operator[](int index) const noexcept;

        /**
         * @fn                          operator<<
         * @brief                       prints the Vec2
         * @param [std::ostream&]       output stream
         * @param [const Vec2&]         vector object to be printed
         * @return [std::ostream&]      stream
         */
        [[nodiscard]] friend std::ostream &operator<<(std::ostream& out, const Vec2& vec) noexcept;

        /**
         * @fn                          GetX
         * @brief                       returns m_X component
         * @return [float]              m_X
         */
        [[nodiscard]] constexpr inline float GetX() const noexcept { return m_X; }

        /**
         * @fn                          GetY
         * @brief                       returns m_Y component
         * @return [float]              m_Y
         */
        [[nodiscard]] constexpr inline float GetY() const noexcept { return m_Y; }

    private:
        float m_X;
        float m_Y;
    }; // END OF CLASS Vec2

        constexpr void Vec2::Normalize() noexcept {
                float len = Length();
                if (len != 0) {
                        m_X /= len;
                        m_Y /= len;
                }
        }

        constexpr Vec2 Vec2::MakeReverseVec(const Vec2& vec) noexcept {
                return Vec2(-1.0f * vec.GetX(), -1.0f * vec.GetY());
        }

        constexpr void Vec2::Reverse() noexcept {
                m_X *= -1.0f;
                m_Y *= -1.0f;
        }

        constexpr float Vec2::DotProduct(const Vec2& vec1, const Vec2& vec2) noexcept {
                return vec1.GetX() * vec2.GetX() + vec1.GetY() * vec2.GetY();
        }

        constexpr float Vec2::AngleBetween(const Vec2& vec1, const Vec2& vec2) noexcept {
                float dot = DotProduct(vec1, vec2);
                float len = vec1.Length() * vec2.Length();
                return static_cast<float>(acos(dot / len));
        }

        constexpr float Vec2::Length() const noexcept {
                return static_cast<float>(sqrt(m_X * m_X + m_Y * m_Y));
        }

        constexpr Vec2 Vec2::operator+(const Vec2& other) const noexcept {
                return Vec2(m_X + other.m_X, m_Y + other.m_Y);
        }

        constexpr Vec2 Vec2::operator-(const Vec2& other) const noexcept {
                return Vec2(m_X - other.m_X, m_Y - other.m_Y);
        }

        constexpr Vec2 Vec2::operator*(float multiplier) const noexcept {
                return Vec2(multiplier * m_X, multiplier * m_Y);
        }

        constexpr Vec2& Vec2::operator+=(const Vec2& other) noexcept {
                m_X += other.m_X;
                m_Y += other.m_Y;
                return *this;
        }

        constexpr Vec2& Vec2::operator-=(const Vec2& other) noexcept {
                m_X -= other.m_X;
                m_Y -= other.m_Y;
                return *this;
        }

        constexpr Vec2& Vec2::operator*=(float multiplier) noexcept {
                m_X *= multiplier;
                m_Y *= multiplier;
                return *this;
        }

        constexpr bool Vec2::operator==(const Vec2& other) const noexcept {
                return m_X == other.m_X && m_Y == other.m_Y;
        }

        constexpr bool Vec2::operator!=(const Vec2& other) const noexcept {
                return !(*this == other);
        }

        constexpr const float& Vec2::operator[](int index) const noexcept {
            switch(index) {
                case 0:
                    return m_X;
                case 1:
                    return m_Y;
                default:
                    assert(false);
                    break;
            }
        }

}
// END OF NAMESPACE Bald::Math
