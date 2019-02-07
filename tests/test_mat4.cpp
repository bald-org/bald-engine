//
// Created by blinku on 07.02.19.
//

#include "pch.h"
#include "gtest/gtest.h"
#include "math.h"

TEST(Determinant, Mat4_Det) {
    float data[] = {3.0f, 4.0f, 3.0f, 9.0f, 2.0f, 0.0f, 0.0f, 2.0f, 0.0f, 1.0f, 2.0f, 3.0f, 1.0f, 2.0f, 1.0f, 1.0f};
    Bald::Math::Mat4 A(data);

    ASSERT_FLOAT_EQ(24.0f, A.Det());
}

TEST(Transpose, Mat4_Transpose) {
    float data[] = {3.0f, 4.0f, 3.0f, 9.0f, 2.0f, 0.0f, 0.0f, 2.0f, 0.0f, 1.0f, 2.0f, 3.0f, 1.0f, 2.0f, 1.0f, 1.0f};
    float transposedData[] = {3.0f, 2.0f, 0.0f, 1.0f, 4.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 2.0f, 1.0f, 9.0f, 2.0f, 3.0f, 1.0f};

    Bald::Math::Mat4 A(data);
    A.Transpose();

    EXPECT_EQ(Bald::Math::Mat4(transposedData), A);
}

TEST(Transpose, Mat4_StaticTranspose) {
    float data[] = {3.0f, 4.0f, 3.0f, 9.0f, 2.0f, 0.0f, 0.0f, 2.0f, 0.0f, 1.0f, 2.0f, 3.0f, 1.0f, 2.0f, 1.0f, 1.0f};
    float transposedData[] = {3.0f, 2.0f, 0.0f, 1.0f, 4.0f, 0.0f, 1.0f, 2.0f, 3.0f, 0.0f, 2.0f, 1.0f, 9.0f, 2.0f, 3.0f, 1.0f};

    Bald::Math::Mat4 A(data);

    EXPECT_EQ(Bald::Math::Mat4(transposedData), Bald::Math::Mat4::Transpose(A));
}

TEST(Inverse, Mat4_Inverse) {
    float data[] = {1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f};
    float q = 1.0f/4.0f;
    float inversedData[] = {q, q, q, -q, q, q, -q, q, q, -q, q, q, -q, q, q, q,};

    Bald::Math::Mat4 A(data);
    A.Inverse();

    EXPECT_EQ(Bald::Math::Mat4(inversedData), A);
}

TEST(Inverse, Mat4_StaticInverse) {
    float data[] = {1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f};
    float q = 1.0f/4.0f;
    float inversedData[] = {q, q, q, -q, q, q, -q, q, q, -q, q, q, -q, q, q, q,};

    Bald::Math::Mat4 A(data);

    EXPECT_EQ(Bald::Math::Mat4(inversedData), Bald::Math::Mat4::Inverse(A));
}

TEST(Identity, Mat4_Identity) {
    float data[] = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};

    Bald::Math::Mat4 A(data);

    EXPECT_EQ(A, Bald::Math::Mat4::Identity());
}

TEST(Addition, Mat4_Add) {
    Bald::Math::Mat4 A(2.0f);
    Bald::Math::Mat4 B(3.0f);

    Bald::Math::Mat4 C = A.Add(B);

    EXPECT_EQ(Bald::Math::Mat4(5.0f), C);
}

TEST(Subtraction, Mat4_Subtract) {
    Bald::Math::Mat4 A(2.0f);
    Bald::Math::Mat4 B(3.0f);

    Bald::Math::Mat4 C = A.Subtract(B);

    EXPECT_EQ(Bald::Math::Mat4(-1.0f), C);
}

TEST(Multiplication, Mat4_Multiply) {
    float dataA[] = {1.0f, 3.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
    float dataB[] = {0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 1.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 9.0f};
    float dataC[] = {0.0f, 0.0f, 3.0f, 0.0f, 2.0f, 6.0f, 3.0f, 0.0f, 0.0f, 3.0f, 0.0f, 6.0f, 0.0f, 9.0f, 0.0f, 0.0f};
    Bald::Math::Mat4 A(dataA);
    Bald::Math::Mat4 B(dataB);

    Bald::Math::Mat4 C(dataC);

    EXPECT_EQ(C, A.Multiply(B));
}

TEST(Multiplication, Mat4_MultiplyByVec4) {
    float dataA[] = {1.0f, 3.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
    Bald::Math::Mat4 A(dataA);
    Bald::Math::Vec4 vec(2.0f, 1.0f, 3.0f, 4.0f);


    EXPECT_EQ(Bald::Math::Vec4(2.0f, 11.0f, 9.0f, 2.0f), A.Multiply(vec));
}

TEST(Multiplication, Mat4_MultiplyByVec3) {
    float dataA[] = {1.0f, 3.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
    Bald::Math::Mat4 A(dataA);
    Bald::Math::Vec3 vec(2.0f, 1.0f, 3.0f);


    EXPECT_EQ(Bald::Math::Vec4(2.0f, 8.0f, 9.0f, 2.0f), A.Multiply(vec));
}

TEST(Operator, Mat4_AddOperator) {
    Bald::Math::Mat4 A(2.0f);
    Bald::Math::Mat4 B(3.0f);

    Bald::Math::Mat4 C = A + B;

    EXPECT_EQ(Bald::Math::Mat4(5.0f), C);
}

TEST(Operator, Mat4_SubtractOperator) {
    Bald::Math::Mat4 A(2.0f);
    Bald::Math::Mat4 B(3.0f);

    Bald::Math::Mat4 C = A - B;

    EXPECT_EQ(Bald::Math::Mat4(-1.0f), C);
}

TEST(Operator, Mat4_MultiplyOperator) {
    float dataA[] = {1.0f, 3.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
    float dataB[] = {0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 1.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 9.0f};
    float dataC[] = {0.0f, 0.0f, 3.0f, 0.0f, 2.0f, 6.0f, 3.0f, 0.0f, 0.0f, 3.0f, 0.0f, 6.0f, 0.0f, 9.0f, 0.0f, 0.0f};
    Bald::Math::Mat4 A(dataA);
    Bald::Math::Mat4 B(dataB);

    Bald::Math::Mat4 C(dataC);

    EXPECT_EQ(C, A * B);
}

TEST(Operator, Mat4_BoolOperatorTrue) {
    Bald::Math::Mat4 A(5.0f);
    Bald::Math::Mat4 B(5.0f);

    EXPECT_TRUE(A == B);
}

TEST(Operator, Mat4_BoolOperatorFalse) {
    Bald::Math::Mat4 A(5.0f);
    Bald::Math::Mat4 B(4.0f);

    EXPECT_FALSE(A == B);
}

TEST(Operator, Mat4_NotBoolOperatorTrue) {
    Bald::Math::Mat4 A(5.0f);
    Bald::Math::Mat4 B(4.0f);

    EXPECT_TRUE(A != B);
}

TEST(Operator, Mat4_NotBoolOperatorFalse) {
    Bald::Math::Mat4 A(4.0f);
    Bald::Math::Mat4 B(4.0f);

    EXPECT_FALSE(A != B);
}

TEST(Operator, Mat4_MultiplyEqualsOperator) {
    float dataA[] = {1.0f, 3.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
    float dataB[] = {0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 1.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 9.0f};
    float dataC[] = {0.0f, 0.0f, 3.0f, 0.0f, 2.0f, 6.0f, 3.0f, 0.0f, 0.0f, 3.0f, 0.0f, 6.0f, 0.0f, 9.0f, 0.0f, 0.0f};
    Bald::Math::Mat4 A(dataA);
    Bald::Math::Mat4 B(dataB);

    Bald::Math::Mat4 C(dataC);

    EXPECT_EQ(C, A*=B);
}