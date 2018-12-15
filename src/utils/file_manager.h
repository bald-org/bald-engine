//
// Created by blinku on 15.12.18.
//

#pragma once

#include <iostream>
#include <string>
#include <fstream>

namespace ENGINE::UTILS {

    class FileManager {
    public:
        enum Size : char {
            SMALL, BIG
        };
    public:
        FileManager() = default;
        ~FileManager() = default;

        static std::string ReadFile(const char* filePath, Size size);
    private:
        static std::string ReadSmallFile(const char* filePath);
        static std::string ReadBigFile(const char* filePath);
    };
}