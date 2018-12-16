//
// Created by blinku on 15.12.18.
//

#include "file_manager.h"

#include <fstream>

namespace Bald::Utils {

    std::string FileManager::ReadFile(const char *filePath, Size size) {
        if (size == SMALL) {
            return ReadSmallFile(filePath);
        }
        else if (size == BIG) {
            return ReadBigFile(filePath);
        }
        else {
            std::cout << "Specify size of your file! (SMALL/BIG)" << std::endl;
            return std::string("Error!");
        }
    }

    std::string FileManager::ReadSmallFile(const char *filePath) {
        FILE *file = fopen(filePath, "r");

        if (!file) {
            std::cout << "Couldn't open the file at path: " << filePath << std::endl;
        }

        fseek(file, 0, SEEK_END);
        unsigned long stringSize = ftell(file);
        fseek(file, 0, SEEK_SET);

        char *buffer = new char[stringSize + 1];

        fread(buffer, sizeof(char), stringSize, file);
        buffer[stringSize] = 0;

        std::string result(buffer);

        delete[] buffer;

        return result;
    }

    std::string FileManager::ReadBigFile(const char* filePath) {
        // TODO: Implement reading huge files;
        exit(1);
    }
}

