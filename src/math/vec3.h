//
// Created by ajer on 30.12.18.
//

#pragma once

#include <iostream>

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
        [[nodiscard]] constexpr Vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f)
                : m_x(x), m_y(y), m_z(z) {}


        /**
         * @fn                          MakeUnitVec
         * @brief                       creates unit vector with the length of 1.0f
         * @param [const Vec3&]         vec -> current vector
         * @return [Vec3]               unit long vector
         */
        [[nodiscard]] static Vec3 MakeUnitVec(const Vec3 &vec) noexcept;


        /**
         * @fn                          Normalize
         * @brief                       normalizes vector to the length of 1.0f
         *                              (divides each component by the length of the vector)
         * @return [Vec3&]              unit long vector
         */
        [[nodiscard]] Vec3 &Normalize() noexcept;


        /**
         * @fn                          GetX
         * @brief                       returns m_x variable
         * @return [float]              m_x
         */
        [[nodiscard]] constexpr inline float GetX() const noexcept { return m_x; }


        /**
         * @fn                          GetY
         * @brief                       returns m_y variable
         * @return [float]              m_y
         */
        [[nodiscard]] constexpr inline float GetY() const noexcept { return m_y; }

        /**
         * @fn                          GetZ
         * @brief                       returns m_z variable
         * @return [float]              m_z
         */
        [[nodiscard]] constexpr inline float GetZ() const noexcept { return m_z; }

        /**
         * @fn                           Reverse
         * @brief                        reverses the vector
         * @return [Vec3&]               reversed new vector
         */
        [[nodiscard]] Vec3 Reverse() const noexcept;

        // OPERATORS

        /**
         * @fn                          operator<<
         * @brief                       prints the Vec3
         * @param [std::ostream&]       output stream
         * @param [const Vec3&]         vector object to be printed
         * @return [std::ostream&]      stream
         */
        [[nodiscard]] friend std::ostream &operator<<(std::ostream &out, const Vec3 &vec) noexcept;


        /**
         * @fn                          operator+
         * @brief                       adds another vector to the current vector
         * @param [const Vec3&]         other vector
         * @return [Vec3]               new vector
         */
        [[nodiscard]] Vec3 operator+(const Vec3 &other) const noexcept;


        /**
         * @fn                          operator-
         * @brief                       subtracts another vector from the current vector
         * @param [const Vec3&]         other vector
         * @return [Vec3]               new vector
         */
        [[nodiscard]] Vec3 operator-(const Vec3 &other) const noexcept;


        /**
         * @fn                          operator*
         * @brief                       multiplies current vector by the passed multiplier
         * @param [float]               multiplier
         * @return [Vec3]               new vector
         */
        [[nodiscard]] Vec3 operator*(float multiplier) const noexcept;


        /**
         * @fn                          operator+=
         * @brief                       adds another vector to the current vector
         * @param [const Vec3&]         other vector
         * @return [Vec3&]              current vector added with the passed vector
         */
        [[nodiscard]] Vec3 &operator+=(const Vec3 &other) noexcept;


        /**
         * @fn                          operator-=
         * @brief                       adds reversed other vector to the current vector
         * @param [const Vec3&]         other vector
         * @return [Vec3&]              current vector subtracted with the passed vector
         */
        [[nodiscard]] Vec3 &operator-=(const Vec3 &other) noexcept;


        /**
         * @fn                          operator*=
         * @brief                       multiplies current vector by the passed multiplier
         * @param [const Vec33&]         other vector
         * @return [Vec3&]              current vector multiplied by the passed multiplier
         */
        [[nodiscard]] Vec3 &operator*=(float multiplier) noexcept;


        /**
         * @fn                          operator==
         * @brief                       checks if the two vectors are the same
         * @param [const Vec3&]          other vector
         * @return [bool]               true  - vectors are     the same
         *                              false - vectors are NOT the same
         */
        [[nodiscard]] bool operator==(const Vec3 &other) const noexcept;


        /**
         * @fn                          operator!=
         * @brief                       checks if the two vectors are NOT the same
         * @param [const Vec3&]          other vector
         * @return [bool]               true  - vectors are NOT the same
         *                              false - vectors are     the same
         */
        [[nodiscard]] bool operator!=(const Vec3 &other) const noexcept;

        // END OF OPERATORS

        /**
         * @fn                          AngleBetween
         * @brief                       returns angle in RADIANS between two vectors
         * @param [const Vec&]          other vector
         * @return [float]              angle in radians
         */
        [[nodiscard]] float AngleBetween(const Vec3 &other) const noexcept;


        /**
         * @fn                          Len
         * @brief                       calculates length of the vector
         * @return [float]              length of the vector
         */
        [[nodiscard]] float Len() const noexcept;


        /**
         * @fn                          DotProduct
         * @brief                       calculates dot product
         * @param [const Vec3&]         other vector
         * @return [float]              dot product of the vector passed in
         */
        [[nodiscard]] float DotProduct(const Vec3 &other) const noexcept;


        /**
         * @fn                          CrossProduct
         * @brief                       calculates cross product
         * @param [const Vec3&]         other vector
         * @return [Vec3]               cross product (new vector) with the vector passed in
         */
        [[nodiscard]] Vec3 CrossProduct(const Vec3 &other) const noexcept;

    private:
        float m_x;
        float m_y;
        float m_z;

    }; // END OF CLASS VEC3
} // END OF NAMESPACE BALD::MATH
