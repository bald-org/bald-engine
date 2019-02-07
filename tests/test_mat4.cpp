//
// Created by blinku on 07.02.19.
//

#include "pch.h"
#include "gtest/gtest.h"
#include "math.h"

TEST(Determinant, Mat4_Det) {
    Bald::Math::Mat4 A(1.0f);

    ASSERT_FLOAT_EQ(1.0f, A.Det());
}
