//
// Created by blinku on 07.02.19.
//

#include "mat4.h"

namespace Bald::Math {

    void Mat4::Inverse() noexcept {
            Mat4 copy = *this;

            m_MatrixElements[0] =   copy.m_MatrixElements[5]  * copy.m_MatrixElements[10] * copy.m_MatrixElements[15] -
                                    copy.m_MatrixElements[5]  * copy.m_MatrixElements[11] * copy.m_MatrixElements[14] -
                                    copy.m_MatrixElements[9]  * copy.m_MatrixElements[6]  * copy.m_MatrixElements[15] +
                                    copy.m_MatrixElements[9]  * copy.m_MatrixElements[7]  * copy.m_MatrixElements[14] +
                                    copy.m_MatrixElements[13] * copy.m_MatrixElements[6]  * copy.m_MatrixElements[11] -
                                    copy.m_MatrixElements[13] * copy.m_MatrixElements[7]  * copy.m_MatrixElements[10];

            m_MatrixElements[4] =  -copy.m_MatrixElements[4]  * copy.m_MatrixElements[10] * copy.m_MatrixElements[15] +
                                    copy.m_MatrixElements[4]  * copy.m_MatrixElements[11] * copy.m_MatrixElements[14] +
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[6]  * copy.m_MatrixElements[15] -
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[7]  * copy.m_MatrixElements[14] -
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[6]  * copy.m_MatrixElements[11] +
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[7]  * copy.m_MatrixElements[10];

            m_MatrixElements[8] =   copy.m_MatrixElements[4]  * copy.m_MatrixElements[9]  * copy.m_MatrixElements[15] -
                                    copy.m_MatrixElements[4]  * copy.m_MatrixElements[11] * copy.m_MatrixElements[13] -
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[5]  * copy.m_MatrixElements[15] +
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[7]  * copy.m_MatrixElements[13] +
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[5]  * copy.m_MatrixElements[11] -
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[7]  * copy.m_MatrixElements[9];

            m_MatrixElements[12] = -copy.m_MatrixElements[4]  * copy.m_MatrixElements[9]  * copy.m_MatrixElements[14] +
                                    copy.m_MatrixElements[4]  * copy.m_MatrixElements[10] * copy.m_MatrixElements[13] +
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[5]  * copy.m_MatrixElements[14] -
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[6]  * copy.m_MatrixElements[13] -
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[5]  * copy.m_MatrixElements[10] +
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[6]  * copy.m_MatrixElements[9];

            m_MatrixElements[1] =  -copy.m_MatrixElements[1]  * copy.m_MatrixElements[10] * copy.m_MatrixElements[15] +
                                    copy.m_MatrixElements[1]  * copy.m_MatrixElements[11] * copy.m_MatrixElements[14] +
                                    copy.m_MatrixElements[9]  * copy.m_MatrixElements[2]  * copy.m_MatrixElements[15] -
                                    copy.m_MatrixElements[9]  * copy.m_MatrixElements[3]  * copy.m_MatrixElements[14] -
                                    copy.m_MatrixElements[13] * copy.m_MatrixElements[2]  * copy.m_MatrixElements[11] +
                                    copy.m_MatrixElements[13] * copy.m_MatrixElements[3]  * copy.m_MatrixElements[10];

            m_MatrixElements[5] =   copy.m_MatrixElements[0]  * copy.m_MatrixElements[10] * copy.m_MatrixElements[15] -
                                    copy.m_MatrixElements[0]  * copy.m_MatrixElements[11] * copy.m_MatrixElements[14] -
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[2]  * copy.m_MatrixElements[15] +
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[3]  * copy.m_MatrixElements[14] +
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[2]  * copy.m_MatrixElements[11] -
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[3]  * copy.m_MatrixElements[10];

            m_MatrixElements[9] =  -copy.m_MatrixElements[0]  * copy.m_MatrixElements[9]  * copy.m_MatrixElements[15] +
                                    copy.m_MatrixElements[0]  * copy.m_MatrixElements[11] * copy.m_MatrixElements[13] +
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[1]  * copy.m_MatrixElements[15] -
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[3]  * copy.m_MatrixElements[13] -
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[1]  * copy.m_MatrixElements[11] +
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[3]  * copy.m_MatrixElements[9];

            m_MatrixElements[13] =  copy.m_MatrixElements[0]  * copy.m_MatrixElements[9]  * copy.m_MatrixElements[14] -
                                    copy.m_MatrixElements[0]  * copy.m_MatrixElements[10] * copy.m_MatrixElements[13] -
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[1]  * copy.m_MatrixElements[14] +
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[2]  * copy.m_MatrixElements[13] +
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[1]  * copy.m_MatrixElements[10] -
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[2]  * copy.m_MatrixElements[9];

            m_MatrixElements[2] =   copy.m_MatrixElements[1]  * copy.m_MatrixElements[6]  * copy.m_MatrixElements[15] -
                                    copy.m_MatrixElements[1]  * copy.m_MatrixElements[7]  * copy.m_MatrixElements[14] -
                                    copy.m_MatrixElements[5]  * copy.m_MatrixElements[2]  * copy.m_MatrixElements[15] +
                                    copy.m_MatrixElements[5]  * copy.m_MatrixElements[3]  * copy.m_MatrixElements[14] +
                                    copy.m_MatrixElements[13] * copy.m_MatrixElements[2]  * copy.m_MatrixElements[7]  -
                                    copy.m_MatrixElements[13] * copy.m_MatrixElements[3]  * copy.m_MatrixElements[6];

            m_MatrixElements[6] =  -copy.m_MatrixElements[0]  * copy.m_MatrixElements[6]  * copy.m_MatrixElements[15] +
                                    copy.m_MatrixElements[0]  * copy.m_MatrixElements[7]  * copy.m_MatrixElements[14] +
                                    copy.m_MatrixElements[4]  * copy.m_MatrixElements[2]  * copy.m_MatrixElements[15] -
                                    copy.m_MatrixElements[4]  * copy.m_MatrixElements[3]  * copy.m_MatrixElements[14] -
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[2]  * copy.m_MatrixElements[7]  +
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[3]  * copy.m_MatrixElements[6];

            m_MatrixElements[10] =  copy.m_MatrixElements[0]  * copy.m_MatrixElements[5]  * copy.m_MatrixElements[15] -
                                    copy.m_MatrixElements[0]  * copy.m_MatrixElements[7]  * copy.m_MatrixElements[13] -
                                    copy.m_MatrixElements[4]  * copy.m_MatrixElements[1]  * copy.m_MatrixElements[15] +
                                    copy.m_MatrixElements[4]  * copy.m_MatrixElements[3]  * copy.m_MatrixElements[13] +
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[1]  * copy.m_MatrixElements[7]  -
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[3]  * copy.m_MatrixElements[5];

            m_MatrixElements[14] = -copy.m_MatrixElements[0]  * copy.m_MatrixElements[5]  * copy.m_MatrixElements[14] +
                                    copy.m_MatrixElements[0]  * copy.m_MatrixElements[6]  * copy.m_MatrixElements[13] +
                                    copy.m_MatrixElements[4]  * copy.m_MatrixElements[1]  * copy.m_MatrixElements[14] -
                                    copy.m_MatrixElements[4]  * copy.m_MatrixElements[2]  * copy.m_MatrixElements[13] -
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[1]  * copy.m_MatrixElements[6]  +
                                    copy.m_MatrixElements[12] * copy.m_MatrixElements[2]  * copy.m_MatrixElements[5];

            m_MatrixElements[3] =  -copy.m_MatrixElements[1]  * copy.m_MatrixElements[6]  * copy.m_MatrixElements[11] +
                                    copy.m_MatrixElements[1]  * copy.m_MatrixElements[7]  * copy.m_MatrixElements[10] +
                                    copy.m_MatrixElements[5]  * copy.m_MatrixElements[2]  * copy.m_MatrixElements[11] -
                                    copy.m_MatrixElements[5]  * copy.m_MatrixElements[3]  * copy.m_MatrixElements[10] -
                                    copy.m_MatrixElements[9]  * copy.m_MatrixElements[2]  * copy.m_MatrixElements[7]  +
                                    copy.m_MatrixElements[9]  * copy.m_MatrixElements[3]  * copy.m_MatrixElements[6];

            m_MatrixElements[7] =   copy.m_MatrixElements[0]  * copy.m_MatrixElements[6]  * copy.m_MatrixElements[11] -
                                    copy.m_MatrixElements[0]  * copy.m_MatrixElements[7]  * copy.m_MatrixElements[10] -
                                    copy.m_MatrixElements[4]  * copy.m_MatrixElements[2]  * copy.m_MatrixElements[11] +
                                    copy.m_MatrixElements[4]  * copy.m_MatrixElements[3]  * copy.m_MatrixElements[10] +
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[2]  * copy.m_MatrixElements[7]  -
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[3]  * copy.m_MatrixElements[6];

            m_MatrixElements[11] = -copy.m_MatrixElements[0]  * copy.m_MatrixElements[5]  * copy.m_MatrixElements[11] +
                                    copy.m_MatrixElements[0]  * copy.m_MatrixElements[7]  * copy.m_MatrixElements[9]  +
                                    copy.m_MatrixElements[4]  * copy.m_MatrixElements[1]  * copy.m_MatrixElements[11] -
                                    copy.m_MatrixElements[4]  * copy.m_MatrixElements[3]  * copy.m_MatrixElements[9]  -
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[1]  * copy.m_MatrixElements[7]  +
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[3]  * copy.m_MatrixElements[5];

            m_MatrixElements[15] =  copy.m_MatrixElements[0]  * copy.m_MatrixElements[5]  * copy.m_MatrixElements[10] -
                                    copy.m_MatrixElements[0]  * copy.m_MatrixElements[6]  * copy.m_MatrixElements[9]  -
                                    copy.m_MatrixElements[4]  * copy.m_MatrixElements[1]  * copy.m_MatrixElements[10] +
                                    copy.m_MatrixElements[4]  * copy.m_MatrixElements[2]  * copy.m_MatrixElements[9]  +
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[1]  * copy.m_MatrixElements[6]  -
                                    copy.m_MatrixElements[8]  * copy.m_MatrixElements[2]  * copy.m_MatrixElements[5];

            float det = copy.m_MatrixElements[0] * m_MatrixElements[0] +
                        copy.m_MatrixElements[1] * m_MatrixElements[4] +
                        copy.m_MatrixElements[2] * m_MatrixElements[8] +
                        copy.m_MatrixElements[3] * m_MatrixElements[12];

            if(det == 0) {
                    CORE_LOG_WARN("Matrix determinant equals 0! Returning identity matrix!");
                    *this = Identity();
                    return;
            }

            for (int i = 0; i < 16; ++i)
                    m_MatrixElements[i] /= det;
    }

    Mat4 Mat4::Inverse(const Mat4& matrix) noexcept {
            Mat4 copy = matrix;
            copy.Inverse();
            return copy;
    }

}
