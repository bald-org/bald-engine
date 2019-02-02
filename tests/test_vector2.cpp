//
// Created by ajer on 16.12.18.
//

#include "pch.h"
#include "gtest/gtest.h"
#include "math/vec2.h"


TEST(Getter, GetX) { //NOLINT
    Bald::Math::Vec2 A(66.0f, 3.4f);

    ASSERT_FLOAT_EQ(66.0f, A.GetX());
}


TEST(Getter, GetY) { //NOLINT
    Bald::Math::Vec2 A(2.0f, -23.33f);

    ASSERT_FLOAT_EQ(-23.33f, A.GetY());
}


TEST(NormalizeVector, StaticUnitVec) { //NOLINT
    Bald::Math::Vec2 A = Bald::Math::Vec2::MakeUnitVec(Bald::Math::Vec2(3.0f, 4.0f));

    EXPECT_EQ(Bald::Math::Vec2(0.6f, 0.8f), A);
}


TEST(NormalizeVector, UnitVecMethod) { //NOLINT
    Bald::Math::Vec2 A(5.0f, 12.0f);

    A.Normalize();

    ASSERT_FLOAT_EQ(1.0f, A.Length());
}


TEST(Operator, AddingOperator) { //NOLINT
    Bald::Math::Vec2 A(2.0f, -4.0f);
    Bald::Math::Vec2 B(1.0f, 3.0f);

    EXPECT_EQ(Bald::Math::Vec2(3.0f, -1.0f), A + B);
}


TEST(Operator, SubtractingOperator) { //NOLINT
    Bald::Math::Vec2 A(2.0f, -4.0f);
    Bald::Math::Vec2 B(1.0f, 3.0f);

    EXPECT_EQ(Bald::Math::Vec2(1.0f, -7.0f), A - B);
}


TEST(Operator, MultiplyingOperator) { //NOLINT
    Bald::Math::Vec2 A(2.0f, -4.0f);

    EXPECT_EQ(Bald::Math::Vec2(6.0f, -12.0f), A * 3.0f);
}

TEST(Operator, PlusEqualsOperator) { //NOLINT
    Bald::Math::Vec2 A(2.0f, 4.0f);
    Bald::Math::Vec2 B(1.0f, 1.0f);

    A += B;

    EXPECT_EQ(Bald::Math::Vec2(3.0f, 5.0f), A);
}

TEST(Operator, MinusEqualsOperator) { //NOLINT
    Bald::Math::Vec2 A(2.0f, 4.0f);
    Bald::Math::Vec2 B(1.0f, 1.0f);

    A -= B;

    EXPECT_EQ(Bald::Math::Vec2(1.0f, 3.0f), A);
}

TEST(Operator, MultiEqualsOperator) { //NOLINT
    Bald::Math::Vec2 A(2.0f, -3.0f);

    A *= 4.0f;

    EXPECT_EQ(Bald::Math::Vec2(8.0f, -12.0f), A);
}

TEST(Operator, EqualsEqualsOperatorTrue) { //NOLINT
    Bald::Math::Vec2 A(2.0f, -3.0f);
    Bald::Math::Vec2 B(2.0f, -3.0f);

    ASSERT_TRUE(A == B);
}

TEST(Operator, EqualsEqualsOperatorFalse) { //NOLINT
    Bald::Math::Vec2 A(2.4f, -3.0f);
    Bald::Math::Vec2 B(5.0f, -1.0f);

    ASSERT_FALSE(A == B);
}

TEST(Operator, NotEqualsOperatorTrue) { //NOLINT
    Bald::Math::Vec2 A(2.0f, -3.2f);
    Bald::Math::Vec2 B(4.0f, -11.2f);

    ASSERT_TRUE(A != B);
}

TEST(Operator, NotEqualsOperatorFalse) { //NOLINT
    Bald::Math::Vec2 A(2.0f, -1.0f);
    Bald::Math::Vec2 B(2.0f, -1.0f);

    ASSERT_FALSE(A != B);
}

TEST(Length, CalculateLength) { //NOLINT
    Bald::Math::Vec2 A(3.0f, 4.0f);

    ASSERT_FLOAT_EQ(5.0f, A.Length());
}

TEST(Length, CalculateLength2) { //NOLINT
    Bald::Math::Vec2 A(-12.0f, -5.0f);

    ASSERT_FLOAT_EQ(13.0f, A.Length());
}

TEST(DotProduct, CalculateDotProduct) { //NOLINT
    Bald::Math::Vec2 A(1.0f, 1.0f);
    Bald::Math::Vec2 B = Bald::Math::Vec2(2.0f, 2.0f);

    ASSERT_FLOAT_EQ(4.0f, Bald::Math::Vec2::DotProduct(A,B));
}

TEST(Reverse, ReversingTheVec) { //NOLINT
    Bald::Math::Vec2 A(3.5f, -2.0f);

    EXPECT_EQ(Bald::Math::Vec2(-3.5f, 2.0f), Bald::Math::Vec2::MakeReverseVec(A));
}

TEST(AngleBetweenTwoVectors, Radians) { //NOLINT
    Bald::Math::Vec2 A(static_cast<float> (sqrt(3.0)) * 2.0f, 2.0f);
    Bald::Math::Vec2 B(static_cast<float> (sqrt(3.0)) * 2.0f, 0.0f);

    ASSERT_FLOAT_EQ(static_cast<float> (M_PI / 6.0), Bald::Math::Vec2::AngleBetween(A,B));
}
