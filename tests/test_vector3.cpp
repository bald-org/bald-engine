//
// Created by ajer on 30.12.18.
//

#include "pch.h"
#include "gtest/gtest.h"
#include "math.h"

TEST(Getter, Vec3_GetX) { //NOLINT
    Bald::Math::Vec3 A(66.0f, 3.4f, 1.0f);

    ASSERT_FLOAT_EQ(66.0f, A.GetX());
}

TEST(Getter, Vec3_GetY) { //NOLINT
    Bald::Math::Vec3 A(2.0f, -23.33f, 2.0f);

    ASSERT_FLOAT_EQ(-23.33f, A.GetY());
}

TEST(Getter, Vec3_GetZ) { //NOLINT
    Bald::Math::Vec3 A(1.0f, -21.2f, -5.3f);

    ASSERT_FLOAT_EQ(-5.3f, A.GetZ());
}

TEST(NormalizeVector, Vec3_StaticUnitVec) { //NOLINT
    Bald::Math::Vec3 A = Bald::Math::Vec3::MakeUnitVec(Bald::Math::Vec3(2.0f, 3.0f, 6.0f));

    ASSERT_EQ(Bald::Math::Vec3(2.0f / 7.0f, 3.0f / 7.0f, 6.0f / 7.0f), A);
}

TEST(NormalizeVector, Vec3_StaticUnitZeroVec) { //NOLINT
    Bald::Math::Vec3 A = Bald::Math::Vec3::MakeUnitVec(Bald::Math::Vec3(0.0f, 0.0f, 0.0f));

    EXPECT_EQ(Bald::Math::Vec3(0.0f, 0.0f, 0.0f), A);
}

TEST(NormalizeVector, Vec3_UnitVecMethod) { //NOLINT
    Bald::Math::Vec3 A(5.0f, 12.0f, 1.0f);

    A.Normalize();

    ASSERT_FLOAT_EQ(1.0f, A.Length());
}

TEST(Operator, Vec3_AddingOperator) { //NOLINT
    Bald::Math::Vec3 A(2.0f, -4.0f, 1.0f);
    Bald::Math::Vec3 B(1.0f, 3.0f, 3.0f);

    EXPECT_EQ(Bald::Math::Vec3(3.0f, -1.0f, 4.0f), A + B);
}

TEST(Operator, Vec3_SubtractingOperator) { //NOLINT
    Bald::Math::Vec3 A(2.0f, -4.0f, 1.0f);
    Bald::Math::Vec3 B(1.0f, 3.0f, 3.0f);

    EXPECT_EQ(Bald::Math::Vec3(1.0f, -7.0f, -2.0f), A - B);
}

TEST(Operator, Vec3_MultiplyingOperator) { //NOLINT
    Bald::Math::Vec3 A(2.0f, -4.0f, 1.0f);

    EXPECT_EQ(Bald::Math::Vec3(6.0f, -12.0f, 3.0f), A * 3.0f);
}

TEST(Operator, Vec3_PlusEqualsOperator) { //NOLINT
    Bald::Math::Vec3 A(2.0f, 4.0f, -2.5f);
    Bald::Math::Vec3 B(1.0f, 1.0f, 1.0f);

    A += B;

    EXPECT_EQ(Bald::Math::Vec3(3.0f, 5.0f, -1.5f), A);
}

TEST(Operator, Vec3_MinusEqualsOperator) { //NOLINT
    Bald::Math::Vec3 A(2.0f, 4.0f, 1.0f);
    Bald::Math::Vec3 B(1.0f, 1.0f, 4.5f);

    A -= B;

    EXPECT_EQ(Bald::Math::Vec3(1.0f, 3.0f, -3.5f), A);
}

TEST(Operator, Vec3_MultiEqualsOperator) { //NOLINT
    Bald::Math::Vec3 A(2.0f, -3.0f, 2.0f);

    A *= 4.0f;

    EXPECT_EQ(Bald::Math::Vec3(8.0f, -12.0f, 8.0f), A);
}

TEST(Operator, Vec3_EqualsEqualsOperatorTrue) { //NOLINT
    Bald::Math::Vec3 A(2.0f, -3.0f, -5.0f);
    Bald::Math::Vec3 B(2.0f, -3.0f, -5.0f);

    ASSERT_TRUE(A == B);
}

TEST(Operator, Vec3_EqualsEqualsOperatorFalse) { //NOLINT
    Bald::Math::Vec3 A(2.4f, -3.0f, 1.0f);
    Bald::Math::Vec3 B(5.0f, -1.0f, 1.0f);


    ASSERT_FALSE(A == B);
}

TEST(Operator, Vec3_NotEqualsOperatorTrue) { //NOLINT
    Bald::Math::Vec3 A(2.0f, -3.2f, 1.0f);
    Bald::Math::Vec3 B(4.0f, -11.2f, 2.0f);

    ASSERT_TRUE(A != B);
}

TEST(Operator, Vec3_NotEqualsOperatorFalse) { //NOLINT
    Bald::Math::Vec3 A(2.0f, -1.0f, 5.0f);
    Bald::Math::Vec3 B(2.0f, -1.0f, 5.0f);

    ASSERT_FALSE(A != B);
}

TEST(Length, Vec3_CalculateLength) { //NOLINT
    Bald::Math::Vec3 A(2.0f, 3.0f, 6.0f);

    ASSERT_FLOAT_EQ(7.0f, A.Length());
}

TEST(DotProduct, Vec3_CalculateDotProduct) { //NOLINT
    Bald::Math::Vec3 A(1.0f, 5.0f, 3.0f);
    Bald::Math::Vec3 B = Bald::Math::Vec3(2.0f, 2.0f, -1.0f);

    ASSERT_FLOAT_EQ(9.0f, Bald::Math::Vec3::DotProduct(A,B));
}

TEST(CrossProduct, Vec3_CalculateCrossProduct) { //NOLINT
    Bald::Math::Vec3 A(1.0f, 5.0f, 3.0f);
    Bald::Math::Vec3 B = Bald::Math::Vec3(2.0f, 2.0f, -1.0f);

    EXPECT_EQ(Bald::Math::Vec3(-11.0f, 7.0f, -8.0f), Bald::Math::Vec3::CrossProduct(A,B));
}

TEST(CrossProduct, Vec3_CalculateCrossProductUsingOperatorOverload) { //NOLINT
    Bald::Math::Vec3 A(1.0f, 5.0f, 3.0f);
    Bald::Math::Vec3 B = Bald::Math::Vec3(2.0f, 2.0f, -1.0f);

    A *= B;

    EXPECT_EQ(Bald::Math::Vec3(-11.0f, 7.0f, -8.0f), A);
}

TEST(Reverse, Vec3_ReversingTheVec) { //NOLINT
    Bald::Math::Vec3 A(3.5f, -2.0f, 0.01f);

    EXPECT_EQ(Bald::Math::Vec3(-3.5f, 2.0f, -0.01f), Bald::Math::Vec3::MakeReverseVec(A));
}

TEST(AngleBetweenTwoVectors, Vec3_Radians) { //NOLINT
    Bald::Math::Vec3 A(3.0f, 3.0f, -3.0f);
    Bald::Math::Vec3 B(2.0f, 1.0f, 3.0f);

    ASSERT_FLOAT_EQ((static_cast<float> (M_PI) / 2.0f), Bald::Math::Vec3::AngleBetween(A,B));
}
