//
// Created by blinku on 16.12.18.
//

#include "pch.h"
#include "gtest/gtest.h"
#include "utils/file_manager.h"

TEST(FileManager, GoodFileOpening) { //NOLINT

    std::string file_result = Bald::Utils::FileManager::ReadFile("test_file_manager.txt", Bald::Utils::FileManager::SMALL);

    EXPECT_EQ("plik testowy\n"
              "do odczytu", file_result);
}

TEST(FileManager, WrongFileOpening) { //NOLINT

    std::string file_result = Bald::Utils::FileManager::ReadFile("no_such_file.cpp", Bald::Utils::FileManager::SMALL);

    EXPECT_EQ(std::string("Couldn't open the file at path: no_such_file.cpp") , file_result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}