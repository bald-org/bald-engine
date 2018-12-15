//
// Created by Piotr Moszkowicz on 2018-12-15.
//

#include "pch.h"
#include "gtest/gtest.h"

double divide(int a, int b) {
    if (b == 0) return -1;
    return static_cast<double>(a) / static_cast<double>(b);
}

TEST(Division, DivisionByZero) { //NOLINT
    int a = 1;
    int b = 0;

    double division_result = divide(a, b);
    EXPECT_EQ(-1, division_result);
}

TEST(Division, CorrectDivision) { //NOLINT
    int a = 5;
    int b = 2;

    double division_result = divide(a, b);
    EXPECT_EQ(2.5, division_result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
