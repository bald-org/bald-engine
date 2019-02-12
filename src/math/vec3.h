//
// Created by ajer on 30.12.18.
//

#pragma once

#include <iostream>
#include "pch.h"

/**
 * @class Vec3
 * @brief vector 3 class
 */

namespace Bald::Math {
    class Vec3 {
    public:
        /**
         * @fn                          Vec3
         * @brief                       constructor
         * @param [float]               x variable
         * @param [float]               y variable
         * @param [float]               z variable
         */
        explicit constexpr Vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f)
                : m_X(x), m_Y(y), m_Z(z) {}

        /**
        * @fn                          MakeUnitVec
        * @brief                       creates unit vector with the length of 1.0f
        * @param [const Vec3&]         vec -> vector which will be used to create unit vector
        * @return [Vec3]               unit long vector
        */
        [[nodiscard]] static Vec3 MakeUnitVec(const Vec3& vec) noexcept;

        /**
         * @fn                          Normalize
         * @brief                       normalizes vector to the length of 1.0f
         *                              (divides each component by the length of the vector)
         * @return [Vec3&]              unit long vector
         */
        constexpr void Normalize() noexcept;

        /**
        * @fn                          MakeReverseVec
        * @brief                       creates reverse vector of a given vector
        * @param [const Vec3&]         vec -> vector which will be used to create reversed vector
        * @return [Vec3]               new, reversed vector
        */
        [[nodiscard]] static constexpr Vec3 MakeReverseVec(const Vec3& vec) noexcept;

        /**
         * @fn                         Reverse
         * @brief                      reverses the current vector
         * @return [void]
         */
        constexpr void Reverse() noexcept;

        /**
         * @fn                          DotProduct
         * @brief                       calculates dot product of two vectors
         * @param [const Vec3&]         vec1 vector
         * @param [const Vec3&]         vec2 vector
         * @return [float]              dot product of the vector passed in
         */
        [[nodiscard]] static constexpr float DotProduct(const Vec3& vec1, const Vec3& vec2) noexcept;

        /**
         * @fn                          CrossProduct
         * @brief                       calculates cross product of two vectors
         * @param [const Vec3&]         vec1 vector
         * @param [const Vec3&]         vec2 vector
         * @return [float]              cross of vectors passed in
         */
        [[nodiscard]] static constexpr Vec3 CrossProduct(const Vec3& vec1, const Vec3& vec2) noexcept;

        /**
         * @fn                          AngleBetween
         * @brief                       returns angle in RADIANS between two vectors
         * @param [const Vec3&]         vec1 vector
         * @param [const Vec3&]         vec2 vector
         * @return [float]              angle in radians
         */
        [[nodiscard]] static constexpr float AngleBetween(const Vec3& vec1, const Vec3& vec2) noexcept;

        /**
         * @fn                          Length
         * @brief                       calculates the length of the vector
         * @return [float]              length of the vector
         */
        [[nodiscard]] constexpr float Length() const noexcept;

        /**
         * @fn                          operator+
         * @brief                       adds another vector to the current vector
         * @param [const Vec3&]         other vector
         * @return [Vec3]               new vector
         */
        [[nodiscard]] constexpr Vec3 operator+(const Vec3& other) const noexcept;


        /**
         * @fn                          operator-
         * @brief                       subtracts another vector from the current vector
         * @param [const Vec3&]         other vector
         * @return [Vec3]               new vector
         */
        [[nodiscard]] constexpr Vec3 operator-(const Vec3& other) const noexcept;

        /**
         * @fn                          operator*
         * @brief                       multiplies current vector by the passed multiplier
         * @param [float]               multiplier
         * @return [Vec3]               new vector
         */
        [[nodiscard]] constexpr Vec3 operator*(float multiplier) const noexcept;

        /**
         * @fn                          operator+=
         * @brief                       adds another vector to the current vector
         * @param [const Vec3&]         other vector
         * @return [Vec3&]              current vector added with the passed vector
         */
        constexpr Vec3& operator+=(const Vec3& other) noexcept;

        /**
         * @fn                          operator-=
         * @brief                       adds reversed other vector to the current vector
         * @param [const Vec3&]         other vector
         * @return [Vec3&]              current vector subtracted with the passed vector
         */
        constexpr Vec3& operator-=(const Vec3& other) noexcept;

        /**
         * @fn                          operator*=
         * @brief                       multiplies current vector by the passed multiplier
         * @param [float]               multiplier
         * @return [Vec3&]              current vector multiplied by the passed multiplier
         */
        constexpr Vec3& operator*=(float multiplier) noexcept;

        /**
         * @fn                          operator*=
         * @brief                       multiplies current vector by the passed multiplier
         * @param [const Vec3&]         other vector
         * @return [Vec3&]              cross product of *this and other
         */
        constexpr Vec3& operator*=(const Vec3& other) noexcept;

        /**
         * @fn                          operator==
         * @brief                       checks if the two vectors are the same
         * @param [const Vec3&]          other vector
         * @return [bool]               true  - vectors are     the same
         *                              false - vectors are NOT the same
         */
        [[nodiscard]] constexpr bool operator==(const Vec3& other) const noexcept;

        /**
         * @fn                          operator!=
         * @brief                       checks if the two vectors are NOT the same
         * @param [const Vec3&]          other vector
         * @return [bool]               true  - vectors are NOT the same
         *                              false - vectors are     the same
         */
        [[nodiscard]] constexpr bool operator!=(const Vec3& other) const noexcept;

        /**
         * @fn                          operator[]
         * @brief                       returns number in vector at certain index
         * @param [int]                 index -> index of a number which you want to retrieve
         * @return [const float&]       float at given index
         */
        [[nodiscard]] constexpr const float& operator[](int index) const noexcept;

        /**
         * @fn                          operator<<
         * @brief                       prints the Vec3
         * @param [std::ostream&]       output stream
         * @param [const Vec3&]         vector object to be printed
         * @return [std::ostream&]      stream
         */
        [[nodiscard]] friend std::ostream &operator<<(std::ostream& out, const Vec3& vec) noexcept;

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

        /**
         * @fn                          GetZ
         * @brief                       returns m_Z component
         * @return [float]              m_Z
         */
        [[nodiscard]] constexpr inline float GetZ() const noexcept { return m_Z; }

    private:
        float m_X;
        float m_Y;
        float m_Z;
    }; // END OF CLASS VEC3

        constexpr void Vec3::Normalize() noexcept {
                float len = Length();
                if (len != 0) {
                        m_X /= len;
                        m_Y /= len;
                        m_Z /= len;
                }
        }

        constexpr Vec3 Vec3::MakeReverseVec(const Vec3& vec) noexcept {
                return Vec3(-1.0f * vec.GetX(), -1.0f * vec.GetY(), -1.0f * vec.GetZ());
        }

        constexpr void Vec3::Reverse() noexcept {
                m_X *= -1.0f;
                m_Y *= -1.0f;
                m_Z *= -1.0f;
        }

        constexpr float Vec3::DotProduct(const Vec3& vec1, const Vec3& vec2) noexcept {
                return vec1.GetX() * vec2.GetX() + vec1.GetY() * vec2.GetY() + vec1.GetZ() * vec2.GetZ();
        }

        constexpr Vec3 Vec3::CrossProduct(const Vec3 &vec1, const Vec3 &vec2) noexcept {
                return Vec3(vec1.m_Y * vec2.m_Z - vec1.m_Z * vec2.m_Y,
                            vec1.m_Z * vec2.m_X - vec1.m_X * vec2.m_Z,
                            vec1.m_X * vec2.m_Y - vec1.m_Y * vec2.m_X);
        }

        constexpr Vec3& Vec3::operator*=(const Vec3& other) noexcept {
            *this = CrossProduct(*this, other);
            return *this;
        }

        constexpr float Vec3::AngleBetween(const Vec3& vec1, const Vec3& vec2) noexcept {
                float dot = DotProduct(vec1, vec2);
                float len = vec1.Length() * vec2.Length();
                return static_cast<float>(acos(dot / len));
        }

        constexpr float Vec3::Length() const noexcept {
                return static_cast<float>(sqrt(m_X * m_X + m_Y * m_Y + m_Z * m_Z));
        }

        constexpr Vec3 Vec3::operator+(const Vec3& other) const noexcept {
                return Vec3(m_X + other.m_X, m_Y + other.m_Y, m_Z + other.m_Z);
        }

        constexpr Vec3 Vec3::operator-(const Vec3& other) const noexcept {
                return Vec3(m_X - other.m_X, m_Y - other.m_Y, m_Z - other.m_Z);
        }

        constexpr Vec3 Vec3::operator*(float multiplier) const noexcept {
                return Vec3(multiplier * m_X, multiplier * m_Y, multiplier * m_Z);
        }

        constexpr Vec3& Vec3::operator+=(const Vec3& other) noexcept {
                m_X += other.m_X;
                m_Y += other.m_Y;
                m_Z += other.m_Z;
                return *this;
        }

        constexpr Vec3& Vec3::operator-=(const Vec3& other) noexcept {
                m_X -= other.m_X;
                m_Y -= other.m_Y;
                m_Z -= other.m_Z;
                return *this;
        }

        constexpr Vec3& Vec3::operator*=(float multiplier) noexcept {
                m_X *= multiplier;
                m_Y *= multiplier;
                m_Z *= multiplier;
                return *this;
        }

        constexpr bool Vec3::operator==(const Vec3& other) const noexcept {
                return m_X == other.m_X && m_Y == other.m_Y && m_Z == other.m_Z;
        }

        constexpr bool Vec3::operator!=(const Vec3& other) const noexcept {
                return !(*this == other);
        }

        constexpr const float& Vec3::operator[](int index) const noexcept {
            switch(index) {
                case 0:
                    return m_X;
                case 1:
                    return m_Y;
                case 2:
                    return m_Z;
                default:
                    assert(false);
                    break;
            }
        }

} // END OF NAMESPACE Bald::Math