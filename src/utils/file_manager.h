//
// Created by blinku on 15.12.18.
//

#pragma once

#include <string>

namespace Bald::Utils {

/**
* @class FileManager
* @brief implementation of file manager system, if you are on Windows add -D_WINDOWS definition, if on Linux add -D_LINUX definition
*/

    class FileManager {
    public:
        enum Size : char {
            SMALL_FILE, BIG_FILE
        };
    public:

        /**
         * @fn FileManager
         * @brief default constructor deleted
         */
        FileManager() = delete;

        /**
         * @fn FileManager
         * @brief default destructor deleted
         */

        ~FileManager() = delete;

        /**
         * @fn ReadFile
         * @brief use to read files
         * @return string
         */

        [[nodiscard]] static std::string ReadFile(const char* filePath, Size size);
    private:
        [[nodiscard]] static std::string ReadSmallFile(const char* filePath); /** used to read small files, same implementation on windows and linux*/
        [[nodiscard]] static std::string ReadBigFile(const char* filePath); /** used to read big files, different implementation for windows and linux*/
    };
}
