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

TEST(Inverse, Mat4_ZeroDetInverse) {
    Bald::Math::Mat4 A(0.0f);

    A.Inverse();

    ASSERT_FLOAT_EQ(1.0f, A.Det());
}

TEST(Identity, Mat4_Identity) {
    float data[] = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};

    Bald::Math::Mat4 A(data);

    EXPECT_EQ(A, Bald::Math::Mat4::Identity());
}


TEST(Translation, Mat4_Translation) {
    Bald::Math::Mat4 A = Bald::Math::Mat4::Translation(Bald::Math::Vec3(2.0f, 3.0f, 1.0f));
    Bald::Math::Vec3 vec(1.0f, 1.0f, 1.0f);

    Bald::Math::Vec4 translatedVec = A * vec;

    EXPECT_EQ(Bald::Math::Vec4(3.0f, 4.0f, 2.0f, 1.0f), translatedVec);
}

TEST(Scale, Mat4_Scale) {
    Bald::Math::Mat4 A = Bald::Math::Mat4::Scale(Bald::Math::Vec3(3.0, 3.0f, 1.0f));
    Bald::Math::Vec3 vec(1.0f, 1.0f, 1.0f);

    Bald::Math::Vec4 scaledVec = A * vec;

    EXPECT_EQ(Bald::Math::Vec4(3.0f, 3.0f, 1.0f, 1.0f), scaledVec);
}

TEST(Rotation, Mat4_Rotation) {
    Bald::Math::Mat4 A = Bald::Math::Mat4::Rotation(90.0f, Bald::Math::Vec3(0.0f, 0.0f, 1.0f));
    Bald::Math::Vec3 vec(5.0f, 1.0f, 0.0f);

    Bald::Math::Vec4 rotatedVec = A * vec;

    EXPECT_FLOAT_EQ(-1.0f, rotatedVec.GetX());
    EXPECT_FLOAT_EQ( 5.0f, rotatedVec.GetY());
    EXPECT_FLOAT_EQ( 0.0f, rotatedVec.GetZ());
    EXPECT_FLOAT_EQ( 1.0f, rotatedVec.GetW());
}

TEST(OrthogonalProjection, Mat4_OrthogonalProjection) {
    Bald::Math::Vec3 lightSource(0.0f, 10.0f, 0.0f);
    Bald::Math::Vec3 normal(0.0f, 1.0f, 0.0f);
    float offset = 0.0f;

    Bald::Math::Mat4 A = Bald::Math::Mat4::OrthogonalProjection(lightSource, normal, offset);

    Bald::Math::Vec4 outcome = A * Bald::Math::Vec3(5.0f, 5.0f, 0.0f);
    outcome.Homogenize();

    EXPECT_TRUE(outcome == Bald::Math::Vec4(10.0f, 0.0f, 0.0f, 1.0f));
}

TEST(Orthographic, Mat4_Orthographic) {
    Bald::Math::Mat4 A = Bald::Math::Mat4::Orthographic(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
    float correctOrthographicData[] = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    Bald::Math::Mat4 B(correctOrthographicData);

    EXPECT_TRUE(A == B);
}

TEST(Perspective, Mat4_Perspective) {
    Bald::Math::Mat4 A = Bald::Math::Mat4::Orthographic(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
    float correctOrthographicData[] = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    Bald::Math::Mat4 B(correctOrthographicData);

    EXPECT_TRUE(A == B);
}

TEST(Addition, Mat4_Add) {
    Bald::Math::Mat4 A(2.0f);
    Bald::Math::Mat4 B(3.0f);

    Bald::Math::Mat4 C = A + B;

    EXPECT_EQ(Bald::Math::Mat4(5.0f), C);
}

TEST(Subtraction, Mat4_Subtract) {
    Bald::Math::Mat4 A(2.0f);
    Bald::Math::Mat4 B(3.0f);

    Bald::Math::Mat4 C = A - B;

    EXPECT_EQ(Bald::Math::Mat4(-1.0f), C);
}

TEST(Multiplication, Mat4_MultiplyByScalar) {
    float dataA[] = {1.0f, 3.0f, 0.0f, 10.0f, 6.0f, 1.0f, 0.0f, 2.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
    float scalar = 5.0f;
    Bald::Math::Mat4 A(dataA);
    A = A * scalar;

    float dataB[] = {5.0f, 15.0f, 0.0f, 50.0f, 30.0f, 5.0f, 0.0f, 10.0f, 0.0f, 0.0f, 15.0f, 0.0f, 0.0f, 5.0f, 0.0f, 0.0f};
    Bald::Math::Mat4 B(dataB);

    EXPECT_EQ(A, B);
}

TEST(Multiplication, Mat4_MultiplyByMatrix) {
    float dataA[] = {1.0f, 3.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
    float dataB[] = {0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 1.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 9.0f};
    float dataC[] = {0.0f, 0.0f, 3.0f, 0.0f, 2.0f, 6.0f, 3.0f, 0.0f, 0.0f, 3.0f, 0.0f, 6.0f, 0.0f, 9.0f, 0.0f, 0.0f};
    Bald::Math::Mat4 A(dataA);
    Bald::Math::Mat4 B(dataB);

    Bald::Math::Mat4 C(dataC);

    EXPECT_EQ(C, A * B);
}

TEST(Multiplication, Mat4_MultiplyByVec4) {
    float dataA[] = {1.0f, 3.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
    Bald::Math::Mat4 A(dataA);
    Bald::Math::Vec4 vec(2.0f, 1.0f, 3.0f, 4.0f);


    EXPECT_EQ(Bald::Math::Vec4(2.0f, 11.0f, 9.0f, 2.0f), A * vec);
}

TEST(Multiplication, Mat4_MultiplyByVec3) {
    float dataA[] = {1.0f, 3.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
    Bald::Math::Mat4 A(dataA);
    Bald::Math::Vec3 vec(2.0f, 1.0f, 3.0f);


    EXPECT_EQ(Bald::Math::Vec4(2.0f, 8.0f, 9.0f, 2.0f), A * vec);
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

TEST(Operator, Mat4_MultiplyEqualsScalarOperator) {
    float dataA[] = {1.0f, 3.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
    float dataB[] = {5.0f, 15.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f, 10.0f, 0.0f, 0.0f, 15.0f, 0.0f, 0.0f, 5.0f, 0.0f, 0.0f};
    float scalar = 5.0f;
    Bald::Math::Mat4 A(dataA);
    Bald::Math::Mat4 B(dataB);

    EXPECT_EQ(B, A*=scalar);
}

TEST(Operator, Mat4_MultiplyScalarMatrixOperator) {
    float dataA[] = {1.0f, 3.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
    float dataB[] = {5.0f, 15.0f, 0.0f, 0.0f, 0.0f, 5.0f, 0.0f, 10.0f, 0.0f, 0.0f, 15.0f, 0.0f, 0.0f, 5.0f, 0.0f, 0.0f};
    float scalar = 5.0f;
    Bald::Math::Mat4 A(dataA);
    Bald::Math::Mat4 B(dataB);

    EXPECT_EQ(B, scalar * A);
}