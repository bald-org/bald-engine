//
// Created by Piotr Moszkowicz on 2018-12-16.
//

#include "core/pch.hpp"
#include "gtest/gtest.h"

int main(int argc, char** argv) {

    Bald::Debug::LogManager::Init();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}