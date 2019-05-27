//
// Created by Piotr Moszkowicz on 2018-12-16.
//

#include "core/pch.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "utils/split_string.h"

using testing::ElementsAre;

TEST(SplitString, SplitByDot) { //NOLINT
    std::vector<std::string> result = Bald::Utils::split_string("test.test", '.');

    ASSERT_THAT(result, ElementsAre("test", "test"));
}

TEST(SplitString, DoubleSplitByDot) { //NOLINT
    std::vector<std::string> result = Bald::Utils::split_string("asdf.test.test", '.');

    ASSERT_THAT(result, ElementsAre("asdf", "test", "test"));
}

TEST(SplitString, NoNeededSplit) { //NOLINT
    std::vector<std::string> result = Bald::Utils::split_string("asdftest", '.');

    ASSERT_THAT(result, ElementsAre("asdftest"));
}
