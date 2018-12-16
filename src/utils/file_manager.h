//
// Created by blinku on 15.12.18.
//

#pragma once

#include <string>

namespace Bald::Utils {

/**
* @class FileManager
* @brief implementation of file manager system
*/

    class FileManager {
    public:
        enum Size : char {
            SMALL, BIG
        };
    public:

        /**
         * @fn FileManager
         * @brief default constructor
         */
        FileManager() = default;

        /**
         * @fn FileManager
         * @brief default destructor
         */

        ~FileManager() = default;

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
