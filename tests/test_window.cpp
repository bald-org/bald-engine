//
// Created by ajer on 11.02.19.
//

#include "gtest/gtest.h"
#include "window.h"


TEST(Getter, Window_GetTitle) { //NOLINT

    Bald::Graphics::Window A("TestPassed", 1500, 752, true);

    EXPECT_EQ(A.GetTitle(), "TestPassed");
}


TEST(Getter, Window_GetWidth) { //NOLINT

    Bald::Graphics::Window B("kochampizze", 1337, 600, false);

    EXPECT_EQ(B.GetWidth(), 1337);
}


TEST(Getter, Window_GetHeight) { //NOLINT

    Bald::Graphics::Window C("ikebabatez", 800, 1998, false);

    EXPECT_EQ(C.GetHeight(), 1998);
}

TEST(Getter, Window_VSync) { //NOLINT

    Bald::Graphics::Window D("Window", 800, 600, false);

    EXPECT_EQ(D.GetVSync(), false);
}


TEST(AspectRatio, Window_GetAspectRatio) { //NOLINT

    Bald::Graphics::Window E("Window", 1500, 600, false);

    ASSERT_FLOAT_EQ(E.GetAspectRatio(), 2.5f);
}