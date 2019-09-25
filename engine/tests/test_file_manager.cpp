//
// Created by blinku on 16.12.18.
//

#include "core/pch.h"
#include "gtest/gtest.h"
#include "utils/file_manager.h"

TEST(FileManager, GoodSmallFileOpening) { //NOLINT

    auto file_result = Bald::Utils::FileManager::ReadFile("../engine/test_file_manager.txt", Bald::Utils::FileManager::Size::SMALL_FILE);

    EXPECT_EQ("plik testowy\ndo odczytu", file_result.value());
    EXPECT_TRUE(file_result);
}

TEST(FileManager, GoodBigFileOpening) { //NOLINT

    auto file_result = Bald::Utils::FileManager::ReadFile("../engine/test_file_manager.txt", Bald::Utils::FileManager::Size::BIG_FILE);

    EXPECT_EQ("plik testowy\ndo odczytu", file_result.value());
    EXPECT_TRUE(file_result);
}

TEST(FileManager, WrongSmallFileOpening) { //NOLINT
    using namespace Bald::Utils;
    auto data = FileManager::ReadFile("no_such_file.cpp", Bald::Utils::FileManager::Size::SMALL_FILE);
    EXPECT_EQ(FileManager::Error::CantOpenFile, data.error());
    EXPECT_FALSE(data);
}

TEST(FileManager, WrongBigFileOpening) { //NOLINT
    using namespace Bald::Utils;
    auto data = Bald::Utils::FileManager::ReadFile("no_such_file.cpp", Bald::Utils::FileManager::Size::BIG_FILE);
    EXPECT_EQ(FileManager::Error::CantOpenFile, data.error());
    EXPECT_FALSE(data);
}
