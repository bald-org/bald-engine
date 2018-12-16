//
// Created by Piotr Moszkowicz on 2018-12-16.
//

#include "pch.h"
#include "gtest/gtest.h"
#include "utils/file_manager.h"

int main(int argc, char **argv) {

    Bald::Log::Init();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}