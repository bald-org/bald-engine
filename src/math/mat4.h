//
// Created by blinku on 05.02.19.
//

#pragma once

#include "pch.h"
#include "vec3.h"
#include <cmath>

namespace Bald::Math {
    class Mat4 {
    public:
        explicit constexpr Mat4(float diagonal = 1.0f);

        explicit constexpr Mat4(float *data);

        ~Mat4() = default;

        [[nodiscard]] constexpr float Det() const noexcept;

        void Transpose() noexcept;
        // constexpr void Inverse() noexcept;

        [[nodiscard]] constexpr static Mat4 Identity() noexcept;

        [[nodiscard]] constexpr static Mat4 Translation(float translationX, float translationY, float translationZ) noexcept;
        [[nodiscard]] constexpr static Mat4 Translation(const Vec3& translation) noexcept;
        [[nodiscard]] constexpr static Mat4 Translation(float scaleX, float scaleY, float scaleZ) noexcept;
        [[nodiscard]] constexpr static Mat4 Scale(const Vec3& scale) noexcept;
        [[nodiscard]] constexpr static Mat4 Rotation(float angle, const Vec3& axis) noexcept;
        [[nodiscard]] constexpr static Mat4 Orthographic(float left, float right, float bottom, float top, float near, float far) noexcept;
        [[nodiscard]] constexpr static Mat4 Perspective(float fov, float aspectRatio, float near, float far) noexcept;

        [[nodiscard]] constexpr Mat4 Add(const Mat4& other) const noexcept;
        [[nodiscard]] constexpr Mat4 Subtract(const Mat4& other) const noexcept;
        [[nodiscard]] constexpr Mat4 Multiply(const Mat4& other) const noexcept;

        [[nodiscard]] constexpr Mat4 operator+(const Mat4& other) const noexcept;
        [[nodiscard]] constexpr Mat4 operator-(const Mat4& other) const noexcept;
        [[nodiscard]] constexpr Mat4 operator*(const Mat4& other) const noexcept;

        [[nodiscard]] constexpr Mat4& operator+=(const Mat4& other) const noexcept;
        [[nodiscard]] constexpr Mat4& operator-=(const Mat4& other) const noexcept;
        // [[nodiscard]] constexpr Mat4& operator*=(const Mat4& other) const noexcept;

    private:
        float m_MatrixElements[16];
    }; // END OF CLASS Mat4

    constexpr Mat4::Mat4(float diagonal) : m_MatrixElements{0.0f} {
        m_MatrixElements[0 + 0 * 4] = diagonal;
        m_MatrixElements[1 + 1 * 4] = diagonal;
        m_MatrixElements[2 + 2 * 4] = diagonal;
        m_MatrixElements[3 + 3 * 4] = diagonal;
    }

    constexpr Mat4::Mat4(float *data) : m_MatrixElements{0.0f} {
        for (int i = 0; i < 16; ++i)
            m_MatrixElements[i] = data[i];
    }

    constexpr float Mat4::Det() const noexcept {
        float minors[4] = {0.0f, 0.0f, 0.0f, 0.0f};

        minors[0] = m_MatrixElements[5] * m_MatrixElements[10] * m_MatrixElements[15] +
                    m_MatrixElements[9] * m_MatrixElements[14] * m_MatrixElements[7] +
                    m_MatrixElements[13] * m_MatrixElements[6] * m_MatrixElements[11] -
                    m_MatrixElements[13] * m_MatrixElements[10] * m_MatrixElements[7] -
                    m_MatrixElements[5] * m_MatrixElements[14] * m_MatrixElements[11] -
                    m_MatrixElements[9] * m_MatrixElements[6] * m_MatrixElements[15];

        minors[1] = m_MatrixElements[1] * m_MatrixElements[10] * m_MatrixElements[15] +
                    m_MatrixElements[9] * m_MatrixElements[14] * m_MatrixElements[3] +
                    m_MatrixElements[13] * m_MatrixElements[2] * m_MatrixElements[11] -
                    m_MatrixElements[13] * m_MatrixElements[10] * m_MatrixElements[3] -
                    m_MatrixElements[1] * m_MatrixElements[14] * m_MatrixElements[11] -
                    m_MatrixElements[9] * m_MatrixElements[2] * m_MatrixElements[15];

        minors[2] = m_MatrixElements[1] * m_MatrixElements[6] * m_MatrixElements[15] +
                    m_MatrixElements[5] * m_MatrixElements[14] * m_MatrixElements[3] +
                    m_MatrixElements[13] * m_MatrixElements[2] * m_MatrixElements[7] -
                    m_MatrixElements[13] * m_MatrixElements[6] * m_MatrixElements[3] -
                    m_MatrixElements[1] * m_MatrixElements[14] * m_MatrixElements[7] -
                    m_MatrixElements[5] * m_MatrixElements[2] * m_MatrixElements[15];

        minors[3] = m_MatrixElements[1] * m_MatrixElements[6] * m_MatrixElements[11] +
                    m_MatrixElements[5] * m_MatrixElements[10] * m_MatrixElements[3] +
                    m_MatrixElements[9] * m_MatrixElements[2] * m_MatrixElements[7] -
                    m_MatrixElements[9] * m_MatrixElements[6] * m_MatrixElements[3] -
                    m_MatrixElements[1] * m_MatrixElements[10] * m_MatrixElements[7] -
                    m_MatrixElements[5] * m_MatrixElements[2] * m_MatrixElements[11];

        return m_MatrixElements[0] * minors[0] - m_MatrixElements[5] * minors[1] + m_MatrixElements[8] * minors[2] -
               m_MatrixElements[12] * minors[3];
    }

    void Mat4::Transpose() noexcept {
        std::swap(m_MatrixElements[1], m_MatrixElements[4]);
        std::swap(m_MatrixElements[2], m_MatrixElements[8]);
        std::swap(m_MatrixElements[3], m_MatrixElements[12]);
        std::swap(m_MatrixElements[6], m_MatrixElements[9]);
        std::swap(m_MatrixElements[7], m_MatrixElements[13]);
        std::swap(m_MatrixElements[11], m_MatrixElements[14]);
    }

    Mat4 Mat4::Identity() noexcept {
        return Mat4(1.0f);
    }

    Mat4 Mat4::Translation(float translationX, float translationY, float translationZ) noexcept {
        Mat4 result(1.0f);

        result.m_MatrixElements[0 + 3 * 4] = translationX;
        result.m_MatrixElements[1 + 3 * 4] = translationX;
        result.m_MatrixElements[2 + 3 * 4] = translationX;

        return result;
    }

    Mat4 Mat4::Translation(const Vec3& translation) noexcept {
        Mat4 result(1.0f);

        result.m_MatrixElements[0 + 3 * 4] = translation.GetX();
        result.m_MatrixElements[1 + 3 * 4] = translation.GetY();
        result.m_MatrixElements[2 + 3 * 4] = translation.GetZ();

        return result;
    }

    Mat4 Mat4::Scale(float scaleX, float scaleY, float scaleZ) noexcept {
        Mat4 result(1.0f);

        result.m_MatrixElements[0 + 0 * 4] = scaleX;
        result.m_MatrixElements[1 + 1 * 4] = scaleY;
        result.m_MatrixElements[2 + 2 * 4] = scaleZ;

        return result;
    }

    Mat4 Mat4::Scale(const Vec3& scale) noexcept {
        Mat4 result(1.0f);

        result.m_MatrixElements[0 + 0 * 4] = scale.GetX();
        result.m_MatrixElements[1 + 1 * 4] = scale.GetY();
        result.m_MatrixElements[2 + 2 * 4] = scale.GetZ();

        return result;
    }

    Mat4 Mat4::Rotation(float angle, const Vec3& axis) noexcept {
        Mat4 result(1.0f);

        float angleInRadians = angle / 180.0f * static_cast<float>(M_PI);
        float c = static_cast<float>(cos(angleInRadians));
        float s = static_cast<float>(sin(angleInRadians));
        float omc = 1 - c;

        result.m_MatrixElements[0 + 0 * 4] = axis.GetX() * axis.GetX() * omc + c;
        result.m_MatrixElements[1 + 0 * 4] = axis.GetX() * axis.GetY() * omc + axis.GetZ() * s;
        result.m_MatrixElements[2 + 0 * 4] = axis.GetX() * axis.GetZ() * omc - axis.GetY() * s;

        result.m_MatrixElements[0 + 1 * 4] = axis.GetX() * axis.GetY() * omc - axis.GetZ() * s;
        result.m_MatrixElements[1 + 1 * 4] = axis.GetY() * axis.GetY() * omc + c;
        result.m_MatrixElements[2 + 1 * 4] = axis.GetY() * axis.GetZ() * omc + axis.GetX() * s;

        result.m_MatrixElements[0 + 2 * 4] = axis.GetX() * axis.GetZ() * omc + axis.GetY() * s;
        result.m_MatrixElements[1 + 2 * 4] = axis.GetY() * axis.GetZ() * omc - axis.GetX() * s;
        result.m_MatrixElements[2 + 2 * 4] = axis.GetZ() * axis.GetZ() * omc + c;

        return result;
    }

    Mat4 Mat4::Orthographic(float left, float right, float bottom, float top, float near, float far) noexcept {
        Mat4 result(1.0f);

        result.m_MatrixElements[0 + 0 * 4] = 2.0f / (right - left);
        result.m_MatrixElements[1 + 1 * 4] = 2.0f / (top - bottom);
        result.m_MatrixElements[2 + 2 * 4] = 2.0f / (near - far);

        result.m_MatrixElements[0 + 3 * 4] = (right + left) / (left - right);
        result.m_MatrixElements[1 + 3 * 4] = (top + bottom) / (bottom - top);
        result.m_MatrixElements[2 + 3 * 4] = (far + near) / (near - far);

        return result;
    }

    Mat4 Mat4::Perspective(float fov, float aspectRatio, float near, float far) noexcept {
        Mat4 result(0.0f);

        float fovInRadians = fov / 180.0f * static_cast<float>(M_PI);
        float a = static_cast<float>(tan(fovInRadians / 2.0f));
        float b = a * aspectRatio;

        result.m_MatrixElements[0 + 0 * 4] = 1.0f / b;
        result.m_MatrixElements[1 + 1 * 4] = 1.0f / a;
        result.m_MatrixElements[2 + 2 * 4] = (-near - far) / (near - far);
        result.m_MatrixElements[2 + 3 * 4] = (2.0f * near * far) / (near - far);
        result.m_MatrixElements[3 + 2 * 4] = 1.0f;

        return result;
    }

    constexpr Mat4 Mat4::Add(const Mat4& other) const noexcept {
        float newElements[16] = {};
        for (int i = 0; i < 16; ++i) {
            newElements[i] = m_MatrixElements[i] + other.m_MatrixElements[i];
        }
        return Mat4(newElements);
    }

    constexpr Mat4 Mat4::Subtract(const Mat4& other) const noexcept {
        float newElements[16] = {};
        for (int i = 0; i < 16; ++i) {
            newElements[i] = m_MatrixElements[i] - other.m_MatrixElements[i];
        }
        return Mat4(newElements);
    }

    constexpr Mat4 Mat4::Multiply(const Mat4& other) const noexcept {
        Mat4 result;

        for (int col = 0; col < 4; ++col)
            for (int row = 0; row < 4; ++row)
                result.m_MatrixElements[row + col * 4] = m_MatrixElements[4 * col] * other.m_MatrixElements[row] +
                                                         m_MatrixElements[4 * col + 1] *
                                                         other.m_MatrixElements[row + 1 * 4] +
                                                         m_MatrixElements[4 * col + 2] *
                                                         other.m_MatrixElements[row + 2 * 4] +
                                                         m_MatrixElements[4 * col + 3] *
                                                         other.m_MatrixElements[row + 3 * 4];

        return result;
    }

    constexpr Mat4 Mat4::operator+(const Mat4& other) const noexcept {
        return this->Add(other);
    }

    constexpr Mat4 Mat4::operator-(const Mat4& other) const noexcept {
        return this->Subtract(other);
    }

    constexpr Mat4 Mat4::operator*(const Mat4& other) const noexcept {
        return this->Multiply(other);
    }

    constexpr Mat4& Mat4::operator+=(const Mat4& other) const noexcept {
        for(int i = 0; i < 16; ++i)
            m_MatrixElements[i] += other.m_MatrixElements[i];
        return *this;
    }

    constexpr Mat4& operator-=(const Mat4& other) const noexcept {
        for(int i = 0; i < 16; ++i)
            m_MatrixElements[i] -= other.m_MatrixElements[i];
        return *this;
    }




}
// END OF NAMESPACE Bald::Math