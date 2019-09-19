//
// Created by blinku on 15.12.18.
//

#include "file_manager.h"
#include "core/pch.h"
#include <fstream>

#ifdef LINUX
    #include <sys/mman.h>
    #include <sys/stat.h>
    #include <fcntl.h>
#endif


namespace Bald::Utils {

    expected<std::string, std::string> FileManager::ReadFile(const char* filePath, Size size) {
        if (size == Size::SMALL_FILE)
            return ReadSmallFile(filePath);
        return ReadBigFile(filePath);
    }

    expected<std::string, std::string> FileManager::ReadSmallFile(const char* filePath) {
        FILE* file = fopen(filePath, "rb");

        if (!file) {
            CORE_LOG_WARN("[FileManager] Couldn't open the file at path: " + static_cast<std::string>(filePath));
            return unexpected("[FileManager] Couldn't open the file at path: " + static_cast<std::string>(filePath));
        }

        fseek(file, 0, SEEK_END);
        auto stringSize = static_cast<unsigned long>(ftell(file));
        fseek(file, 0, SEEK_SET);
        std::string result;
        try {
            result.resize(stringSize);
        }
        catch (std::bad_alloc& ba) {
            CORE_LOG_ERROR("[FileManager] bad_alloc caught: " + static_cast<std::string>(ba.what()));
            return unexpected(std::string("Error!"));
        }

        if (fread(result.data(), sizeof(char), stringSize, file) < stringSize) {
            fclose(file);
            CORE_LOG_ERROR("[FileManager] Could not read whole file: " + static_cast<std::string>(filePath));
            return unexpected("[FileManager] Could not read whole file: " + static_cast<std::string>(filePath));
        }

        fclose(file);
        return result;
    }

#ifdef LINUX

    expected<std::string, std::string> FileManager::ReadBigFile(const char* filePath) {
        int fileDescriptor = open(filePath, O_RDONLY, S_IRUSR | S_IWUSR);
        struct stat sb{};

        if (fstat(fileDescriptor, &sb) == -1) {
            CORE_LOG_WARN("[FileManager] Couldn't get size of the file. Check if the file exists at path: " + static_cast<std::string>(filePath));
            return unexpected("[FileManager] Couldn't get size of the file. Check if the file exists at path: " + static_cast<std::string>(filePath));
        }

        auto* buffer = static_cast<char*>(mmap(nullptr, static_cast<unsigned long>(sb.st_size), PROT_READ, MAP_PRIVATE, fileDescriptor, 0));

        std::string result(buffer);

        munmap(buffer, static_cast<unsigned long>(sb.st_size));

        return result;
    }

#elif WINDOWS
    expected<std::string, std::string> FileManager::ReadBigFile(const char *filePath) {
        CORE_LOG_INFO("[FILE_MANAGER] Error: Windows implementation is not done yet! Using slower reading method!");
        ReadSmallFile(filePath);
    }
#endif

} // END OF NAMESPACE Bald::Utils
