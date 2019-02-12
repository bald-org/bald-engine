//
// Created by ajer on 11.02.19.
//

#include "pch.h"
#include "gtest/gtest.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Window.h"


TEST(Getter, Window_GetTitle) { //NOLINT

    Bald::Graphics::Window A(nullptr, "TestPassed", 1500, 752, true);

    EXPECT_EQ(A.GetTitle(), "TestPassed");
}


TEST(Getter, Window_GetWidth) { //NOLINT

    Bald::Graphics::Window B(nullptr, "kochampizze", 1337, 600, false);

    EXPECT_EQ(B.GetWidth(), 1337);
}


TEST(Getter, Window_GetHeight) { //NOLINT

    Bald::Graphics::Window C(nullptr, "ikebabatez", 800, 1998, false);

    EXPECT_EQ(C.GetHeight(), 1998);
}

TEST(Getter, Window_VSync) { //NOLINT

    Bald::Graphics::Window D(nullptr, "Window", 800, 600, false);

    EXPECT_EQ(D.GetVSync(), false);
}


TEST(AspectRatio, Window_GetAspectRatio) { //NOLINT

    Bald::Graphics::Window E(nullptr, "Window", 1500, 600, false);

    ASSERT_FLOAT_EQ(E.GetAspectRatio(), 2.5f);
}