//
// Created by blinku on 15.12.18.
//

#include "file_manager.h"

#include "pch.h"
#include <fstream>
#include <sys/mman.h>

namespace Bald::Utils {

    std::string FileManager::ReadFile(const char *filePath, Size size) {
        if (size == SMALL_FILE)
            return ReadSmallFile(filePath);
        return ReadBigFile(filePath);
    }

    std::string FileManager::ReadSmallFile(const char *filePath) {
        FILE *file = fopen(filePath, "r");

        if (!file) {
            CORE_LOG_WARN("Couldn't open the file at path: " + static_cast<std::string>(filePath));
            return std::string("Error!");
        }

        fseek(file, 0, SEEK_END);
        auto stringSize = static_cast<unsigned long>(ftell(file));
        fseek(file, 0, SEEK_SET);

        auto *buffer = new char[stringSize + 1];

        fread(buffer, sizeof(char), stringSize, file);
        buffer[stringSize] = 0;

        std::string result(buffer);

        delete[] buffer;

        fclose(file);

        return result;
    }

    std::string FileManager::ReadBigFile(const char *filePath) {
#ifdef _LINUX
        int fileDescriptor = open(filePath, O_RDONLY, S_IRUSR | S_IWUSR);
        struct stat sb;

        if (fstat(fileDescriptor, &sb) == -1) {
            CORE_LOG_WARN("Couldn't get size of the file. Check if the file exists at path: " + static_cast<std::string>(filePath));
            return std::string("Error!");
        }

        auto *buffer = static_cast<char *>(mmap(nullptr, static_cast<unsigned long>(sb.st_size), PROT_READ, MAP_PRIVATE, fileDescriptor, 0));

        std::string result(buffer);

        munmap(buffer, static_cast<unsigned long>(sb.st_size));

        return result;

#elif _WINDOWS
        CORE_LOG_ERROR("Windows implementation is not done yet! Using slower reading method!");
        ReadSmallFile(filePath);
#endif
    }
}
