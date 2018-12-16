//
// Created by ajer on 16.12.18.
//

#include "pch.h"
#include "gtest/gtest.h"
#include "math/vec2.h"


TEST(Length, CalculateLength) { //NOLINT
    Bald::Math::Vec2 A(3.0,4.0);

    double len_result = A.Len();


    EXPECT_EQ(5.0, len_result);
}

TEST(ScalarProduct, CalculateScalarProduct) { //NOLINT
    Bald::Math::Vec2 A(1.0,1.0);
    Bald::Math::Vec2 B = Bald::Math::Vec2(2.0, 2.0);

    double scalar_product = A.ScalarProduct(B);


    EXPECT_EQ(4.0, scalar_product);
}

