//
// Created by blinku on 05.02.19.
//

#pragma once

#include "pch.h"
#include "math.h"
#include "utils/utils.h"
#include "utils/math_utils.h"
#include <cmath>



/**
 * @class Mat4
 * @brief 4x4 matrix class, column major implementation
 */

namespace Bald::Math {
    class Mat4 {
    public:
        /**
        * @fn               Mat4
        * @brief            constructor
        * @param [float]    diagonal -> diagonal value which will be used to construct matrix
        */
        explicit constexpr Mat4(float diagonal = 1.0f);

        /**
        * @fn               Mat4
        * @brief            constructor
        * @param [float*]   data -> pointer to an array of floats, which will be used to construct matrix
        */
        explicit constexpr Mat4(float* data);

        /**
        * @fn               ~Mat4
        * @brief            trivial destructor
        */
        ~Mat4() = default;

        /**
        * @fn               Det
        * @brief            calculates determinant of the matrix
        * @return [float]   determinant
        */
        [[nodiscard]] constexpr float Det() const noexcept;

        /**
        * @fn               Transpose
        * @brief            transposes the matrix
        */
        constexpr void Transpose() noexcept;

        /**
        * @fn                   Transpose
        * @brief                calculates transpose matrix of a given matrix
        * @param [const Mat4&]  matrix -> const reference to Mat4
        * @return [Mat4]        transposed matrix
        */
        [[nodiscard]] constexpr static Mat4 Transpose(const Mat4& matrix) noexcept;

        /**
        * @fn               Inverse
        * @brief            inverses the matrix
        */
        void Inverse() noexcept;

        /**
        * @fn                   Inverse
        * @brief                calculates inverse matrix
        * @param [const Mat4&]  matrix -> matrix which we want to get inverse of
        * @return [Mat4]        inversed matrix
        */
        [[nodiscard]] static Mat4 Inverse(const Mat4& matrix) noexcept;

        /**
        * @fn                   Identity
        * @brief                constructs identity matrix
        * @return [Mat4]        identity matrix
        */
        [[nodiscard]] constexpr static Mat4 Identity() noexcept;

        /**
        * @fn                   Translation
        * @brief                constructs translation matrix
        * @param [const Vec3&]  translation -> vector by which the matrix will translate
        * @return [Mat4]        translation matrix
        */
        [[nodiscard]] constexpr static Mat4 Translation(const Vec3& translation) noexcept;

        /**
        * @fn                   Scale
        * @brief                constructs scale matrix
        * @param [const Vec3&]  scale -> vector by which the matrix will scale
        * @return [Mat4]        scale matrix
        */
        [[nodiscard]] constexpr static Mat4 Scale(const Vec3& scale) noexcept;

        /**
        * @fn                   Rotation
        * @brief                constructs rotation matrix
        * @param [float]        angle -> angle in degrees by which the matrix will rotate
        * @param [const Vec3&]  axis -> axis around which the matrix will rotate
        * @return [Mat4]        rotation matrix
        */
        [[nodiscard]] constexpr static Mat4 Rotation(float angle, const Vec3& axis) noexcept;

        /**
        * @fn                   LookAt
        * @brief                constructs look at matrix
        * @param [const Vec3&]  eye -> eye position in world space
        * @param [const Vec3&]  center -> position of thing we want to look at
        * @param [const Vec3&]  up -> up vector of e.g. camera (not world up!)
        * @return [Mat4]        look at matrix
        */
        [[nodiscard]] constexpr static Mat4 LookAt(const Vec3& eye, const Vec3& center, const Vec3& up);

        /**
        * @fn                   OrthogonalProjection
        * @brief                constructs orthogonal projection matrix
        * @param [float]        lightSource -> the point towards which we project
        * @param [float]        normal -> plane's normal vector
        * @param [float]        offset -> how much the plane is moved from the center (0,0,0)
        * @return [Mat4]        orthogonal projection matrix
        */
        [[nodiscard]] constexpr static Mat4 OrthogonalProjection(const Vec3& lightSource, const Vec3& normal, float offset) noexcept;

        /**
        * @fn                   Orthographic
        * @brief                constructs orthographic matrix
        * @param [float]        left -> left screen space coordinate
        * @param [float]        right -> right screen space coordinate
        * @param [float]        bottom -> bottom screen space coordinate
        * @param [float]        top -> top screen space coordinate
        * @param [float]        near -> near screen space coordinate
        * @param [float]        far -> far screen space coordinate
        * @return [Mat4]        orthographic matrix
        */
        [[nodiscard]] constexpr static Mat4 Orthographic(float left, float right, float bottom, float top, float near, float far) noexcept;

        /**
        * @fn                   Perspective
        * @brief                constructs perspective matrix
        * @param [float]        fov -> field of view (vertical)
        * @param [float]        aspectRatio -> window's aspect ratio
        * @param [float]        near -> near screen space coordinate
        * @param [float]        far -> far screen space coordinate
        * @return [Mat4]        perspective matrix
        */
        [[nodiscard]] constexpr static Mat4 Perspective(float fov, float aspectRatio, float near, float far) noexcept;

        /**
        * @fn                   operator+
        * @brief                adds two matrices
        * @param [const Mat4&]  other -> matrix which we add to our current matrix
        * @return [Mat4]        sum of two matrices
        */
        [[nodiscard]] constexpr Mat4 operator+(const Mat4& other) const noexcept;

        /**
        * @fn                   operator-
        * @brief                subtracts two matrices
        * @param [const Mat4&]  other -> matrix which we subtract to our current matrix
        * @return [Mat4]        difference of two matrices
        */
        [[nodiscard]] constexpr Mat4 operator-(const Mat4& other) const noexcept;

        /**
        * @fn                   operator*
        * @brief                multiplies matrix by a scalar
        * @param [float]        scalar -> number by which the matrix will be multiplied
        * @return [Mat4]        product of scalar and matrix
        */
        [[nodiscard]] constexpr Mat4 operator*(float scalar) const noexcept;

        /**
        * @fn                   operator*
        * @brief                multiplies two matrices
        * @param [const Mat4&]  other -> matrix by which we multiply our current matrix
        * @return [Mat4]        product of two matrices
        */
        [[nodiscard]] constexpr Mat4 operator*(const Mat4& other) const noexcept;

        /**
        * @fn                   operator*
        * @brief                multiplies matrix by vector
        * @param [const Vec4&]  other -> vector by which we multiply the matrix
        * @return [Vec4]        product of matrix and vector
        */
        [[nodiscard]] constexpr Vec4 operator*(const Vec4& other) const noexcept;

        /**
        * @fn                   operator*
        * @brief                multiplies matrix by vector
        * @param [const Vec3&]  other -> vector by which we multiply the matrix
        * @return [Vec4]        product of matrix and vector
        */
        [[nodiscard]] constexpr Vec4 operator*(const Vec3& other) const noexcept;

        /**
        * @fn                   operator==
        * @brief                checks if two matrices are the same
        * @param [const Mat4&]  other -> matrix with which we check identity
        * @return [bool]        true or false
        */
        [[nodiscard]] constexpr bool operator==(const Mat4& other) const noexcept;

        /**
        * @fn                   operator!=
        * @brief                checks if two matrices are different
        * @param [const Mat4&]  other -> matrix with which we check identity
        * @return [bool]        true or false
        */
        [[nodiscard]] constexpr bool operator!=(const Mat4& other) const noexcept;

        /**
        * @fn                   operator+=
        * @brief                adds two matrices
        * @param [const Mat4&]  other -> matrix which we add to our current matrix
        * @return [Mat4&]       sum of two matrices
        */
        constexpr Mat4& operator+=(const Mat4& other) noexcept;

        /**
        * @fn                   operator-=
        * @brief                subtracts two matrices
        * @param [const Mat4&]  other -> matrix which we subtract to our current matrix
        * @return [Mat4&]       difference of two matrices
        */
        constexpr Mat4& operator-=(const Mat4& other) noexcept;

        /**
        * @fn                   operator*=
        * @brief                multiplies matrix by a scalar
        * @param [float]        scalar -> number by which the matrix will be multiplied
        * @return [Mat4]        product of scalar and matrix
        */
        constexpr Mat4& operator*=(float scalar) noexcept;

        /**
        * @fn                   operator*=
        * @brief                multiplies two matrices
        * @param [const Mat4&]  other -> matrix by which we multiply our current matrix
        * @return [Mat4&]       product of two matrices
        */
        constexpr Mat4& operator*=(const Mat4& other) noexcept;

        /**
        * @fn                   operator*
        * @brief                multiplies matrix by a scalar
        * @param [float]        scalar -> number by which the matrix will be multiplied
        * @param [const Mat4&]  other -> matrix which we multiply
        * @return [Mat4]        product of scalar and matrix
        */
        friend constexpr Mat4 operator*(float scalar, const Mat4& other) noexcept;

        /**
         * @fn                          operator[]
         * @brief                       returns column at given index
         * @param [int]                 index -> index of a column which you want to retrieve
         * @return [const Vec4&]        column in a form of Vec4
         */
        [[nodiscard]] constexpr const Vec4& operator[](int index) const noexcept;
    private:
        union { /**< union for optimized elements access and elements interpretation*/
            std::array<float, 16> m_MatrixElements; /**< matrix elements are kept in an array of floats*/
            Vec4 m_MatrixColumns[4];                /**< matrix elements are kept in an array of Vec4s */
        };

    }; // END OF CLASS Mat4

    constexpr Mat4::Mat4(float diagonal) : m_MatrixElements{0.0f} {
        m_MatrixElements[0 + 0 * 4] = diagonal;
        m_MatrixElements[1 + 1 * 4] = diagonal;
        m_MatrixElements[2 + 2 * 4] = diagonal;
        m_MatrixElements[3 + 3 * 4] = diagonal;
    }

    constexpr Mat4::Mat4(float* data) : m_MatrixElements{0.0f} {
        std::memcpy(m_MatrixElements.begin(), data, 16 * sizeof(m_MatrixElements[0]));
    }

    constexpr float Mat4::Det() const noexcept {
        float minors[4] = {0.0f, 0.0f, 0.0f, 0.0f};

        minors[0] =  m_MatrixElements[5]  * m_MatrixElements[10] * m_MatrixElements[15] -
                     m_MatrixElements[5]  * m_MatrixElements[11] * m_MatrixElements[14] -
                     m_MatrixElements[9]  * m_MatrixElements[6]  * m_MatrixElements[15] +
                     m_MatrixElements[9]  * m_MatrixElements[7]  * m_MatrixElements[14] +
                     m_MatrixElements[13] * m_MatrixElements[6]  * m_MatrixElements[11] -
                     m_MatrixElements[13] * m_MatrixElements[7]  * m_MatrixElements[10];

        minors[1] = -m_MatrixElements[4]  * m_MatrixElements[10] * m_MatrixElements[15] +
                     m_MatrixElements[4]  * m_MatrixElements[11] * m_MatrixElements[14] +
                     m_MatrixElements[8]  * m_MatrixElements[6]  * m_MatrixElements[15] -
                     m_MatrixElements[8]  * m_MatrixElements[7]  * m_MatrixElements[14] -
                     m_MatrixElements[12] * m_MatrixElements[6]  * m_MatrixElements[11] +
                     m_MatrixElements[12] * m_MatrixElements[7]  * m_MatrixElements[10];

        minors[2] =  m_MatrixElements[4]  * m_MatrixElements[9]  * m_MatrixElements[15] -
                     m_MatrixElements[4]  * m_MatrixElements[11] * m_MatrixElements[13] -
                     m_MatrixElements[8]  * m_MatrixElements[5]  * m_MatrixElements[15] +
                     m_MatrixElements[8]  * m_MatrixElements[7]  * m_MatrixElements[13] +
                     m_MatrixElements[12] * m_MatrixElements[5]  * m_MatrixElements[11] -
                     m_MatrixElements[12] * m_MatrixElements[7]  * m_MatrixElements[9];

        minors[3] = -m_MatrixElements[4]  * m_MatrixElements[9]  * m_MatrixElements[14] +
                     m_MatrixElements[4]  * m_MatrixElements[10] * m_MatrixElements[13] +
                     m_MatrixElements[8]  * m_MatrixElements[5]  * m_MatrixElements[14] -
                     m_MatrixElements[8]  * m_MatrixElements[6]  * m_MatrixElements[13] -
                     m_MatrixElements[12] * m_MatrixElements[5]  * m_MatrixElements[10] +
                     m_MatrixElements[12] * m_MatrixElements[6]  * m_MatrixElements[9];

        return m_MatrixElements[0] * minors[0] + m_MatrixElements[1] * minors[1] + m_MatrixElements[2] * minors[2] + m_MatrixElements[3] * minors[3];
    }

    constexpr void Mat4::Transpose() noexcept {
        Bald::Utils::ConstexprSwap(m_MatrixElements[1],  m_MatrixElements[4]);
        Bald::Utils::ConstexprSwap(m_MatrixElements[2],  m_MatrixElements[8]);
        Bald::Utils::ConstexprSwap(m_MatrixElements[3],  m_MatrixElements[12]);
        Bald::Utils::ConstexprSwap(m_MatrixElements[6],  m_MatrixElements[9]);
        Bald::Utils::ConstexprSwap(m_MatrixElements[7],  m_MatrixElements[13]);
        Bald::Utils::ConstexprSwap(m_MatrixElements[11], m_MatrixElements[14]);
    }

    constexpr Mat4 Mat4::Transpose(const Mat4& matrix) noexcept {
        Mat4 copy = matrix;
        copy.Transpose();
        return copy;
    }

    constexpr Mat4 Mat4::Identity() noexcept {
        return Mat4(1.0f);
    }

    constexpr Mat4 Mat4::Translation(const Vec3& translation) noexcept {
        Mat4 result(1.0f);

        result.m_MatrixElements[0 + 3 * 4] = translation.GetX();
        result.m_MatrixElements[1 + 3 * 4] = translation.GetY();
        result.m_MatrixElements[2 + 3 * 4] = translation.GetZ();

        return result;
    }

    constexpr Mat4 Mat4::Scale(const Vec3& scale) noexcept {
        Mat4 result(1.0f);

        result.m_MatrixElements[0 + 0 * 4] = scale.GetX();
        result.m_MatrixElements[1 + 1 * 4] = scale.GetY();
        result.m_MatrixElements[2 + 2 * 4] = scale.GetZ();

        return result;
    }

    constexpr Mat4 Mat4::Rotation(float angle, const Vec3& axis) noexcept {
        Mat4 result(1.0f);

        float angleInRadians = Bald::Utils::ToRadians(angle);
        float x = axis.GetX();
        float y = axis.GetY();
        float z = axis.GetZ();
        float c = static_cast<float>(cos(angleInRadians));
        float s = static_cast<float>(sin(angleInRadians));
        float omc = 1 - c;

        result.m_MatrixElements[0 + 0 * 4] = x * x * omc + c;
        result.m_MatrixElements[1 + 0 * 4] = x * y * omc + z * s;
        result.m_MatrixElements[2 + 0 * 4] = x * z * omc - y * s;

        result.m_MatrixElements[0 + 1 * 4] = x * y * omc - z * s;
        result.m_MatrixElements[1 + 1 * 4] = y * y * omc + c;
        result.m_MatrixElements[2 + 1 * 4] = y * z * omc + x * s;

        result.m_MatrixElements[0 + 2 * 4] = x * z * omc + y * s;
        result.m_MatrixElements[1 + 2 * 4] = y * z * omc - x * s;
        result.m_MatrixElements[2 + 2 * 4] = z * z * omc + c;

        return result;
    }

    constexpr Mat4 Mat4::LookAt(const Vec3& eye, const Vec3& center, const Vec3& up) {
        Mat4 result(0.0f);

        Vec3 e = eye;
        Vec3 c = center;
        Vec3 u = up;

        Vec3 f = c - e;
        f.Normalize();
        Vec3 fNorm = f;

        Vec3 r = Vec3::CrossProduct(fNorm, u);
        r.Normalize();
        Vec3 rNorm = r;

        Vec3 uNorm = Vec3::CrossProduct(rNorm, fNorm);

        for (int col = 0; col < 3; ++col) {
            result.m_MatrixElements[0 + col * 4] =  rNorm[col];
            result.m_MatrixElements[1 + col * 4] =  uNorm[col];
            result.m_MatrixElements[2 + col * 4] = -fNorm[col];
        }

        result.m_MatrixElements[0 + 3 * 4] = -Vec3::DotProduct(rNorm, e);
        result.m_MatrixElements[1 + 3 * 4] = -Vec3::DotProduct(uNorm, e);
        result.m_MatrixElements[2 + 3 * 4] =  Vec3::DotProduct(fNorm, e);
        result.m_MatrixElements[3 + 3 * 4] =  1;

        return result;
    }

    constexpr Mat4 Mat4::OrthogonalProjection(const Vec3& lightSource, const Vec3& normal, float offset) noexcept {
        Mat4 result(1.0f);

        Vec4 l = Vec4(lightSource[0], lightSource[1], lightSource[2], 1.0f);
        Vec4 n = Vec4(normal[0], normal[1], normal[2], offset);
        float alfa = Vec4::DotProduct(n, l);

        result.m_MatrixElements[0 + 0 * 4] = alfa - n[0] * l[0];
        result.m_MatrixElements[0 + 1 * 4] =      - n[1] * l[0];
        result.m_MatrixElements[0 + 2 * 4] =      - n[2] * l[0];
        result.m_MatrixElements[0 + 3 * 4] =      - n[3] * l[0];

        result.m_MatrixElements[1 + 0 * 4] =      - n[0] * l[1];
        result.m_MatrixElements[1 + 1 * 4] = alfa - n[1] * l[1];
        result.m_MatrixElements[1 + 2 * 4] =      - n[2] * l[1];
        result.m_MatrixElements[1 + 3 * 4] =      - n[3] * l[1];

        result.m_MatrixElements[2 + 0 * 4] =      - n[0] * l[2];
        result.m_MatrixElements[2 + 1 * 4] =      - n[1] * l[2];
        result.m_MatrixElements[2 + 2 * 4] = alfa - n[2] * l[2];
        result.m_MatrixElements[2 + 3 * 4] =      - n[3] * l[2];

        result.m_MatrixElements[3 + 0 * 4] =      - n[0] * l[3];
        result.m_MatrixElements[3 + 1 * 4] =      - n[1] * l[3];
        result.m_MatrixElements[3 + 2 * 4] =      - n[2] * l[3];
        result.m_MatrixElements[3 + 3 * 4] = alfa - n[3] * l[3];

        return result;
    }

    constexpr Mat4 Mat4::Orthographic(float left, float right, float bottom, float top, float near, float far) noexcept {
        Mat4 result(1.0f);

        result.m_MatrixElements[0 + 0 * 4] = 2.0f / (right - left);
        result.m_MatrixElements[1 + 1 * 4] = 2.0f / (top - bottom);
        result.m_MatrixElements[2 + 2 * 4] = 2.0f / (near - far);

        result.m_MatrixElements[0 + 3 * 4] = (right + left) / (left - right);
        result.m_MatrixElements[1 + 3 * 4] = (top + bottom) / (bottom - top);
        result.m_MatrixElements[2 + 3 * 4] = (far + near) / (near - far);

        return result;
    }

    constexpr Mat4 Mat4::Perspective(float fov, float aspectRatio, float near, float far) noexcept {
        Mat4 result(0.0f);

        float fovInRadians = Bald::Utils::ToRadians(fov);
        float a = static_cast<float>(tan(fovInRadians / 2.0f));
        float b = a * aspectRatio;

        result.m_MatrixElements[0 + 0 * 4] = 1.0f / b;
        result.m_MatrixElements[1 + 1 * 4] = 1.0f / a;
        result.m_MatrixElements[2 + 2 * 4] = (-near - far) / (near - far);
        result.m_MatrixElements[2 + 3 * 4] = (2.0f * near * far) / (near - far);
        result.m_MatrixElements[3 + 2 * 4] = 1.0f;

        return result;
    }

    constexpr Mat4 Mat4::operator+(const Mat4& other) const noexcept {
        float newElements[16] = {};
        for (int i = 0; i < 16; ++i) {
            newElements[i] = m_MatrixElements[i] + other.m_MatrixElements[i];
        }
        return Mat4(newElements);
    }

    constexpr Mat4 Mat4::operator-(const Mat4& other) const noexcept {
        return *this + (-1.0f) * other;
    }

    constexpr Mat4 Mat4::operator*(float scalar) const noexcept {
        Mat4 result = *this;

        for (int i = 0; i < 16; ++i)
            result.m_MatrixElements[i] *= scalar;

        return result;
    }

    constexpr Mat4 Mat4::operator*(const Mat4& other) const noexcept {
        Mat4 result;

        for (int row = 0; row < 4; ++row)
            for (int col = 0; col < 4; ++col)
                result.m_MatrixElements[col + row * 4] = m_MatrixElements[col]      * other.m_MatrixElements[4 * row]     +
                                                         m_MatrixElements[col + 4]  * other.m_MatrixElements[1 + row * 4] +
                                                         m_MatrixElements[col + 8]  * other.m_MatrixElements[2 + row * 4] +
                                                         m_MatrixElements[col + 12] * other.m_MatrixElements[3 + row * 4];

        return result;
    }

    constexpr Vec4 Mat4::operator*(const Vec4& other) const noexcept {
        float temp_x = other.GetX();
        float temp_y = other.GetY();
        float temp_z = other.GetZ();
        float temp_w = other.GetW();
        float x = m_MatrixElements[0] * temp_x + m_MatrixElements[0 + 1 * 4] * temp_y + m_MatrixElements[0 + 2 * 4] * temp_z + m_MatrixElements[0 + 3 * 4] * temp_w;
        float y = m_MatrixElements[1] * temp_x + m_MatrixElements[1 + 1 * 4] * temp_y + m_MatrixElements[1 + 2 * 4] * temp_z + m_MatrixElements[1 + 3 * 4] * temp_w;
        float z = m_MatrixElements[2] * temp_x + m_MatrixElements[2 + 1 * 4] * temp_y + m_MatrixElements[2 + 2 * 4] * temp_z + m_MatrixElements[2 + 3 * 4] * temp_w;
        float w = m_MatrixElements[3] * temp_x + m_MatrixElements[3 + 1 * 4] * temp_y + m_MatrixElements[3 + 2 * 4] * temp_z + m_MatrixElements[3 + 3 * 4] * temp_w;

        return Vec4(x, y, z, w);
    }

    constexpr Vec4 Mat4::operator*(const Vec3& other) const noexcept {
        return *this * Vec4(other.GetX(), other.GetY(), other.GetZ(), 1.0f);
    }

    constexpr bool Mat4::operator==(const Mat4& other) const noexcept {
        for(int i = 0; i < 16; ++i)
            if(m_MatrixElements[i] != other.m_MatrixElements[i])
                return false;
        return true;
    }

    constexpr bool Mat4::operator!=(const Mat4& other) const noexcept {
        return !(*this==other);
    }

    constexpr Mat4& Mat4::operator+=(const Mat4& other) noexcept {
        return *this = *this + other;
    }

    constexpr Mat4& Mat4::operator-=(const Mat4& other) noexcept {
        return *this = *this - other;
    }

    constexpr Mat4& Mat4::operator*=(float scalar) noexcept {
        return *this = *this * scalar;
    }

    constexpr Mat4& Mat4::operator*=(const Mat4& other) noexcept {
        return *this = *this * other;
    }

    constexpr Mat4 operator*(float scalar, const Mat4& other) noexcept {
        return other * scalar;
    }

    constexpr const Vec4& Mat4::operator[](int index) const noexcept {
        return m_MatrixColumns[index];
    }

}
// END OF NAMESPACE Bald::Math