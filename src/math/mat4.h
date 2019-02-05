//
// Created by blinku on 05.02.19.
//

#pragma once

#include "pch.h"

namespace Bald::Math {
    class Mat4 {
    public:
        explicit constexpr Mat4 (float diagonal = 1.0f);

        explicit constexpr Mat4 (float* data);
        ~Mat4() = default;

        [[nodiscard]] constexpr float Det() const noexcept;
        void Transpose() noexcept;
        // constexpr void Inverse() noexcept;

/*        [[nodiscard]] constexpr static Mat4 Identity() noexcept;
        [[nodiscard]] constexpr static Mat4 Translation(const Vec3& translation) noexcept;
        [[nodiscard]] constexpr static Mat4 Scale(const Vec3& scale) noexcept;
        [[nodiscard]] constexpr static Mat4 Rotation(float angle, const Vec3& axis) noexcept;
        [[nodiscard]] constexpr static Mat4 Orthographic(float left, float right, float bottom, float top, float near, float right) noexcept;
        [[nodiscard]] constexpr static Mat4 Perspective(float fov, float aspectRatio, float near, float far) noexcept;*/

        [[nodiscard]] constexpr Mat4 Add(const Mat4& other) const noexcept;
        [[nodiscard]] constexpr Mat4 Subtract(const Mat4& other) const noexcept;
        [[nodiscard]] constexpr Mat4 Multiply(const Mat4& other) const noexcept;

/*        [[nodiscard]] constexpr Mat4 operator+(const Mat4& other) const noexcept;
        [[nodiscard]] constexpr Mat4 operator-(const Mat4& other) const noexcept;
        [[nodiscard]] constexpr Mat4 operator*(const Mat4& other) const noexcept;

        [[nodiscard]] constexpr Mat4& operator+=(const Mat4& other) const noexcept;
        [[nodiscard]] constexpr Mat4& operator-=(const Mat4& other) const noexcept;
        [[nodiscard]] constexpr Mat4& operator*=(const Mat4& other) const noexcept;*/

    private:
        float m_MatrixElements[16];
    }; // END OF CLASS Mat4

        constexpr Mat4::Mat4 (float diagonal) : m_MatrixElements{0.0f} {
            m_MatrixElements[0 + 0 * 4] = diagonal;
            m_MatrixElements[1 + 1 * 4] = diagonal;
            m_MatrixElements[2 + 2 * 4] = diagonal;
            m_MatrixElements[3 + 3 * 4] = diagonal;
        }

        constexpr Mat4::Mat4 (float* data) : m_MatrixElements{0.0f} {
        for(int i = 0; i < 16; ++i)
            m_MatrixElements[i] = data[i];
        }

        constexpr float Mat4::Det() const noexcept {
            float minors[4] = {0.0f, 0.0f, 0.0f, 0.0f};

            minors[0] = m_MatrixElements[5] * m_MatrixElements[10] * m_MatrixElements[15] +
                       m_MatrixElements[9]  * m_MatrixElements[14] * m_MatrixElements[7]  +
                       m_MatrixElements[13] * m_MatrixElements[6]  * m_MatrixElements[11] -
                       m_MatrixElements[13] * m_MatrixElements[10] * m_MatrixElements[7]  -
                       m_MatrixElements[5]  * m_MatrixElements[14] * m_MatrixElements[11] -
                       m_MatrixElements[9]  * m_MatrixElements[6]  * m_MatrixElements[15];

            minors[1] = m_MatrixElements[1] * m_MatrixElements[10] * m_MatrixElements[15] +
                       m_MatrixElements[9]  * m_MatrixElements[14] * m_MatrixElements[3]  +
                       m_MatrixElements[13] * m_MatrixElements[2]  * m_MatrixElements[11] -
                       m_MatrixElements[13] * m_MatrixElements[10] * m_MatrixElements[3]  -
                       m_MatrixElements[1]  * m_MatrixElements[14] * m_MatrixElements[11] -
                       m_MatrixElements[9]  * m_MatrixElements[2]  * m_MatrixElements[15];

            minors[2] = m_MatrixElements[1] * m_MatrixElements[6]  * m_MatrixElements[15] +
                       m_MatrixElements[5]  * m_MatrixElements[14] * m_MatrixElements[3]  +
                       m_MatrixElements[13] * m_MatrixElements[2]  * m_MatrixElements[7]  -
                       m_MatrixElements[13] * m_MatrixElements[6]  * m_MatrixElements[3]  -
                       m_MatrixElements[1]  * m_MatrixElements[14] * m_MatrixElements[7]  -
                       m_MatrixElements[5]  * m_MatrixElements[2]  * m_MatrixElements[15];

            minors[3] = m_MatrixElements[1] * m_MatrixElements[6]  * m_MatrixElements[11] +
                       m_MatrixElements[5]  * m_MatrixElements[10] * m_MatrixElements[3]  +
                       m_MatrixElements[9]  * m_MatrixElements[2]  * m_MatrixElements[7]  -
                       m_MatrixElements[9]  * m_MatrixElements[6]  * m_MatrixElements[3]  -
                       m_MatrixElements[1]  * m_MatrixElements[10] * m_MatrixElements[7]  -
                       m_MatrixElements[5]  * m_MatrixElements[2]  * m_MatrixElements[11];

            return m_MatrixElements[0] * minors[0] - m_MatrixElements[5] * minors[1] + m_MatrixElements[8] * minors[2] - m_MatrixElements[12] * minors[3];
        }

        void Mat4::Transpose() noexcept {
            std::swap(m_MatrixElements[1], m_MatrixElements[4]);
            std::swap(m_MatrixElements[2], m_MatrixElements[8]);
            std::swap(m_MatrixElements[3], m_MatrixElements[12]);
            std::swap(m_MatrixElements[6], m_MatrixElements[9]);
            std::swap(m_MatrixElements[7], m_MatrixElements[13]);
            std::swap(m_MatrixElements[11], m_MatrixElements[14]);
        }

        constexpr Mat4 Mat4::Add(const Mat4& other) const noexcept {
            float newElements[16] = {};
            for(int i = 0; i < 16; ++i) {
                newElements[i] = m_MatrixElements[i] + other.m_MatrixElements[i];
            }
            return Mat4(newElements);
        }

        constexpr Mat4 Mat4::Subtract(const Mat4& other) const noexcept {
            float newElements[16] = {};
            for(int i = 0; i < 16; ++i) {
                newElements[i] = m_MatrixElements[i] - other.m_MatrixElements[i];
            }
            return Mat4(newElements);
        }

        constexpr Mat4 Mat4::Multiply(const Mat4& other) const noexcept {
            Mat4 result;

            for(int col = 0; col < 4; ++col)
                for(int row = 0; row < 4; ++row)
                    result.m_MatrixElements[row  + col * 4] = m_MatrixElements[4 * col] * other.m_MatrixElements[row] +
                                                              m_MatrixElements[4 * col + 1] * other.m_MatrixElements[row + 4] +
                                                              m_MatrixElements[4 * col + 2] * other.m_MatrixElements[row + 8] +
                                                              m_MatrixElements[4 * col + 3] * other.m_MatrixElements[row + 12];

            return result;
        }


}
// END OF NAMESPACE Bald::Math