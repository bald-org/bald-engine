//
// Created by blinku on 16.12.18.
//

#include "pch.h"
#include "gtest/gtest.h"
#include "utils/file_manager.h"

TEST(FileManager, GoodSmallFileOpening) { //NOLINT

    std::string file_result = Bald::Utils::FileManager::ReadFile("../engine/test_file_manager.txt", Bald::Utils::FileManager::Size::SMALL_FILE);

    EXPECT_EQ("plik testowy\ndo odczytu", file_result);
}

TEST(FileManager, GoodBigFileOpening) { //NOLINT

    std::string file_result = Bald::Utils::FileManager::ReadFile("../engine/test_file_manager.txt", Bald::Utils::FileManager::Size::BIG_FILE);

    EXPECT_EQ("plik testowy\ndo odczytu", file_result);
}


TEST(FileManager, WrongSmallFileOpening) { //NOLINT

    std::string file_result = Bald::Utils::FileManager::ReadFile("no_such_file.cpp", Bald::Utils::FileManager::Size::SMALL_FILE);

    EXPECT_EQ("Error!", file_result);
}

TEST(FileManager, WrongBigFileOpening) { //NOLINT

    std::string file_result = Bald::Utils::FileManager::ReadFile("no_such_file.cpp", Bald::Utils::FileManager::Size::BIG_FILE);

    EXPECT_EQ("Error!", file_result);
}