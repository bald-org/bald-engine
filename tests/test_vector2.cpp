//
// Created by ajer on 16.12.18.
//

#include "pch.h"
#include "gtest/gtest.h"
#include "math/vec2.h"




TEST(GetterX, GetX) { //NOLINT
    Bald::Math::Vec2 A(66.0f,3.4f);

    float get_x = A.GetX();

    EXPECT_EQ(66.0f, get_x);
}



TEST(GetterY, GetY) { //NOLINT
    Bald::Math::Vec2 A(2.0f, -23.33f);

    float get_y = A.GetY();

    EXPECT_EQ(-23.33f, get_y);
}



TEST(Length, CalculateLength) { //NOLINT
    Bald::Math::Vec2 A(3.0f, 4.0f);

    float len_result = A.Len();

    EXPECT_EQ(5.0f, len_result);
}



TEST(DotProduct, CalculateScalarProduct) { //NOLINT
    Bald::Math::Vec2 A(1.0f, 1.0f);
    Bald::Math::Vec2 B = Bald::Math::Vec2(2.0f, 2.0f);

    float scalar_product = A.DotProduct(B);


    EXPECT_EQ(4.0f, scalar_product);
}




TEST(Adding, AddingTwoVecs) { //NOLINT
    Bald::Math::Vec2 A(1.0f, 1.0f);
    Bald::Math::Vec2 B = Bald::Math::Vec2(2.0f, 2.0f);

    Bald::Math::Vec2 C = A+B;

    bool test = false;
    if(C.GetX() == 3.0f && C.GetY() == 3.0f) test = true;

    EXPECT_EQ(true , test);
}



TEST(Multiplying, MultiplyingByValue) { //NOLINT
    Bald::Math::Vec2 A(1.0f, -2.0f);

    float multiplier = 2.0f;

    Bald::Math::Vec2 C = A*multiplier;

    bool test = false;
    if(C.GetX() == 2.0f && C.GetY() == -4.0f) test = true;

    EXPECT_EQ(true , test);
}

// Why doesn't this pass ?

TEST(Angle, AngleBetweenTwoVectors) { //NOLINT

    float helpX = (static_cast<float> (sqrt(3.0))*2.0f);

    Bald::Math::Vec2 A(helpX, 2.0f);
    Bald::Math::Vec2 B(helpX, 0.0f);

    float test_angle = A.AngleBetween(B);


    EXPECT_EQ(30.0f, test_angle);
}
