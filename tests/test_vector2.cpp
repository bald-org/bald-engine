//
// Created by ajer on 16.12.18.
//

#include "pch.h"
#include "gtest/gtest.h"
#include "math/vec2.h"



TEST(GetterX, GetX) { //NOLINT
    Bald::Math::Vec2 A(66.0f,3.4f);

    EXPECT_EQ(66.0f, A.GetX());
}



TEST(GetterY, GetY) { //NOLINT
    Bald::Math::Vec2 A(2.0f, -23.33f);

    EXPECT_EQ(-23.33f, A.GetY());
}



TEST(MakeUnitVec, StaticUnitVec) { //NOLINT
    Bald::Math::Vec2 A = Bald::Math::Vec2::MakeUnitVec(Bald::Math::Vec2(3.0f, 4.0f));

    EXPECT_EQ(1.0f, A.Len());
}



TEST(NormalizeVector, UnitVecMethod) { //NOLINT
    Bald::Math::Vec2 A(5.0f,12.0f);

    A.Normalize();

    EXPECT_EQ(1.0f, A.Len());
}



TEST(PlusOperator, AddingOperator) { //NOLINT
    Bald::Math::Vec2 A(2.0f,-4.0f);
    Bald::Math::Vec2 B(1.0f, 3.0f);

    Bald::Math::Vec2 C(A+B);

    EXPECT_EQ(Bald::Math::Vec2(3.0f,-1.0f), C);
}



TEST(MinusOperator, SubtractingOperator) { //NOLINT
    Bald::Math::Vec2 A(2.0f,-4.0f);
    Bald::Math::Vec2 B(1.0f, 3.0f);

    Bald::Math::Vec2 C(A-B);

    EXPECT_EQ(Bald::Math::Vec2(1.0f,-7.0f), C);
}



TEST(MultiplyOperator, MultiplyingOperator) { //NOLINT
    Bald::Math::Vec2 A(2.0f,-4.0f);

    Bald::Math::Vec2 C(A*3.0f);

    EXPECT_EQ(Bald::Math::Vec2(6.0f,-12.0f), C);
}



TEST(PlusEqualsOperator, AddingOperator) { //NOLINT
    Bald::Math::Vec2 A(2.0f, 4.0f);
    Bald::Math::Vec2 B(1.0f, 1.0f);

    A += B;

    EXPECT_EQ(Bald::Math::Vec2(3.0f,5.0f), A);
}



TEST(MinusEqualsOperator, SubtractingOperator) { //NOLINT
    Bald::Math::Vec2 A(2.0f, 4.0f);
    Bald::Math::Vec2 B(1.0f, 1.0f);

    A -= B;

    EXPECT_EQ(Bald::Math::Vec2(1.0f,3.0f), A);
}



TEST(MultiEqualsOperator, MultiplyingOperator) { //NOLINT
    Bald::Math::Vec2 A(2.0f,-3.0f);

    A *= 4.0f;

    EXPECT_EQ(Bald::Math::Vec2(8.0f,-12.0f), A);
}



TEST(EqualsEqualsOperator, ComparingOperator) { //NOLINT
    Bald::Math::Vec2 A(2.0f,-3.0f);
    Bald::Math::Vec2 B(2.0f,-3.0f);

    EXPECT_EQ(true, A == B);
}



TEST(NotEqualsOperator2, ComparingOperator2) { //NOLINT
    Bald::Math::Vec2 A(2.0f,-3.0f);
    Bald::Math::Vec2 B(4.0f,-11.2f);

    EXPECT_EQ(true, A != B);
}



TEST(Length, CalculateLength) { //NOLINT
    Bald::Math::Vec2 A(3.0f, 4.0f);

    EXPECT_EQ(5.0f, A.Len());
}



TEST(DotProduct, CalculateScalarProduct) { //NOLINT
    Bald::Math::Vec2 A(1.0f, 1.0f);
    Bald::Math::Vec2 B = Bald::Math::Vec2(2.0f, 2.0f);

    EXPECT_EQ(4.0f, A.DotProduct(B));
}



TEST(Reverse, ReversingTheVec) { //NOLINT
    Bald::Math::Vec2 A(3.5f, -2.0f);

    Bald::Math::Vec2 B = A.Reverse();

    EXPECT_EQ(Bald::Math::Vec2(-3.5f, 2.0f) , B);
}



TEST(Angle, AngleBetweenTwoVectors) { //NOLINT

    float helpX = (static_cast<float> (sqrt(3.0))*2.0f);

    Bald::Math::Vec2 A(helpX, 2.0f);
    Bald::Math::Vec2 B(helpX, 0.0f);

    float test_angle = A.AngleBetween(B);


    ASSERT_FLOAT_EQ (static_cast<float> (M_PI / 6.0), test_angle);
}
