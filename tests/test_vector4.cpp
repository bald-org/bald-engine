//
// Created by blinku on 02.02.19.
//
#include "pch.h"
#include "gtest/gtest.h"
#include "math.h"

TEST(Getter, Vec4_GetX) { //NOLINT
    Bald::Math::Vec4 A(66.0f, 3.4f, 1.0f, 17.0f);

    ASSERT_FLOAT_EQ(66.0f, A.GetX());
}


TEST(Getter, Vec4_GetY) { //NOLINT
    Bald::Math::Vec4 A(66.0f, 3.4f, 1.0f, 17.0f);

    ASSERT_FLOAT_EQ(3.4f, A.GetY());
}


TEST(Getter, Vec4_GetZ) { //NOLINT
    Bald::Math::Vec4 A(66.0f, 3.4f, -51.0f, 17.0f);

    ASSERT_FLOAT_EQ(-51.0f, A.GetZ());
}

TEST(Getter, Vec4_GetW) { //NOLINT
    Bald::Math::Vec4 A(66.0f, 3.4f, 1.0f, 17.0f);

    ASSERT_FLOAT_EQ(17.0f, A.GetW());
}

TEST(NormalizeVector, Vec4_StaticUnitVec) { //NOLINT
    Bald::Math::Vec4 A = Bald::Math::Vec4::MakeUnitVec(Bald::Math::Vec4(2.0f, 3.0f, 6.0f, 1.0f));

    float len = 5.0f * static_cast<float>(sqrt(2.0));

    ASSERT_EQ(Bald::Math::Vec4(2.0f / len, 3.0f / len, 6.0f / len, 1.0f / len), A);
}

TEST(NormalizeVector, Vec4_StaticUnitZeroVec) { //NOLINT
    Bald::Math::Vec4 A = Bald::Math::Vec4::MakeUnitVec(Bald::Math::Vec4(0.0f, 0.0f, 0.0f, 0.0f));

    EXPECT_EQ(Bald::Math::Vec4(0.0f, 0.0f, 0.0f, 0.0f), A);
}

TEST(NormalizeVector, Vec4_Normalize) { //NOLINT
    Bald::Math::Vec4 A(5.0f, 12.0f, 1.0f, 16.0f);

    A.Normalize();

    ASSERT_FLOAT_EQ(1.0f, A.Length());
}

TEST(Operator, Vec4_AddingOperator) { //NOLINT
    Bald::Math::Vec4 A(2.0f, -4.0f, 1.0f, 2.0f);
    Bald::Math::Vec4 B(1.0f, 3.0f, 3.0f, 3.0f);

    EXPECT_EQ(Bald::Math::Vec4(3.0f, -1.0f, 4.0f, 5.0f), A + B);
}

TEST(Operator, Vec4_SubtractingOperator) { //NOLINT
    Bald::Math::Vec4 A(2.0f, -4.0f, 1.0f, 5.0f);
    Bald::Math::Vec4 B(1.0f, 3.0f, 3.0f, 10.0f);

    EXPECT_EQ(Bald::Math::Vec4(1.0f, -7.0f, -2.0f, -5.0f), A - B);
}

TEST(Operator, Vec4_MultiplyingOperator) { //NOLINT
    Bald::Math::Vec4 A(2.0f, -4.0f, 1.0f, 4.0f);

    EXPECT_EQ(Bald::Math::Vec4(6.0f, -12.0f, 3.0f, 12.0f), A * 3.0f);
}

TEST(Operator, Vec4_PlusEqualsOperator) { //NOLINT
    Bald::Math::Vec4 A(2.0f, 4.0f, -2.5f, 2.0f);
    Bald::Math::Vec4 B(1.0f, 1.0f, 1.0f, 3.0f);

    A += B;

    EXPECT_EQ(Bald::Math::Vec4(3.0f, 5.0f, -1.5f, 5.0f), A);
}

TEST(Operator, Vec4_MinusEqualsOperator) { //NOLINT
    Bald::Math::Vec4 A(2.0f, 4.0f, 1.0f, 6.0f);
    Bald::Math::Vec4 B(1.0f, 1.0f, 4.5f, 3.0f);

    A -= B;

    EXPECT_EQ(Bald::Math::Vec4(1.0f, 3.0f, -3.5f, 3.0f), A);
}

TEST(Operator, Vec4_MultiEqualsOperator) { //NOLINT
    Bald::Math::Vec4 A(2.0f, -3.0f, 2.0f, 1.5f);

    A *= 4.0f;

    EXPECT_EQ(Bald::Math::Vec4(8.0f, -12.0f, 8.0f, 6.0f), A);
}

TEST(Operator, Vec4_EqualsEqualsOperatorTrue) { //NOLINT
    Bald::Math::Vec4 A(2.0f, -3.0f, -5.0f, 1.0f);
    Bald::Math::Vec4 B(2.0f, -3.0f, -5.0f, 1.0f);

    ASSERT_TRUE(A == B);
}

TEST(Operator, Vec4_EqualsEqualsOperatorFalse) { //NOLINT
    Bald::Math::Vec4 A(2.4f, -3.0f, 1.0f, 2.0f);
    Bald::Math::Vec4 B(5.0f, -1.0f, 1.0f, 2.0f);


    ASSERT_FALSE(A == B);
}

TEST(Operator, Vec4_NotEqualsOperatorTrue) { //NOLINT
    Bald::Math::Vec4 A(2.0f, -3.2f, 1.0f, 3.0f);
    Bald::Math::Vec4 B(4.0f, -11.2f, 2.0f, 4.0f);

    ASSERT_TRUE(A != B);
}

TEST(Operator, Vec4_NotEqualsOperatorFalse) { //NOLINT
    Bald::Math::Vec4 A(2.0f, -1.0f, 5.0f, 4.0f);
    Bald::Math::Vec4 B(2.0f, -1.0f, 5.0f, 4.0f);


    ASSERT_FALSE(A != B);
}

TEST(Length, Vec4_CalculateLength) { //NOLINT
    Bald::Math::Vec4 A(2.0f, 3.0f, 6.0f, 16.0f);

    ASSERT_FLOAT_EQ(static_cast<float>(sqrt(305.0)), A.Length());
}

TEST(DotProduct, Vec4_CalculateDotProduct) { //NOLINT
    Bald::Math::Vec4 A(1.0f, 5.0f, 3.0f, 1.0f);
    Bald::Math::Vec4 B = Bald::Math::Vec4(2.0f, 2.0f, -1.0f, 1.0f);


    ASSERT_FLOAT_EQ(10.0f, Bald::Math::Vec4::DotProduct(A,B));
}

TEST(Reverse, Vec4_ReversingTheVec) { //NOLINT
    Bald::Math::Vec4 A(3.5f, -2.0f, 0.01f, 3.0f);

    EXPECT_EQ(Bald::Math::Vec4(-3.5f, 2.0f, -0.01f, -3.0f), Bald::Math::Vec4::MakeReverseVec(A));
}

TEST(AngleBetweenTwoVectors, Vec4_Radians) { //NOLINT
    Bald::Math::Vec4 A(1.0f, 0.0f, 0.0f, 0.0f);
    Bald::Math::Vec4 B(0.0f, 1.0f, 0.0f, 0.0f);

    ASSERT_FLOAT_EQ(static_cast<float>(M_PI)/2.0f, Bald::Math::Vec4::AngleBetween(A,B));
}
