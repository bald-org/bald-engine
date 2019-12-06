//
// Created by blinku on 15.12.18.
//

#pragma once

#include <string>
#include "error/expected.h"

namespace Bald::Utils {

/**
* @class FileManager
* @brief implementation of file manager system, if you are on Windows add -D_WINDOWS definition, if on Linux add -D_LINUX definition
*/

    class FileManager {
    public:
        /**
         * ENUM which determines size of file and therefor methods, which will be used to read it
         */
        enum class Size : uint8_t {
            SMALL_FILE, BIG_FILE
        };

        enum class Error : uint8_t {
            Fail,
            CantOpenFile,
            TooBigFile
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
         * @param filePath          Path to file
         * @param size              Size of file
         * @return string
         */

        [[nodiscard]] static expected<std::string, Error> ReadFile(const char* filePath, Size size = Size::SMALL_FILE);
    private:

        /**
         * @fn ReadSmallFile
         * @brief used by public function ReadFile to read smaller files, platform independent
         * @param filePath          Path to file
         * @return string
         */
        [[nodiscard]] static expected<std::string, Error> ReadSmallFile(const char* filePath);

        /**
         * @fn ReadBigFile
         * @brief used by public function ReadFile to read bigger files, platform dependant
         * @param filePath          Path to file
         * @return string
         */
        [[nodiscard]] static expected<std::string, Error> ReadBigFile(const char* filePath);
    };

} // END OF NAMESPACE Bald::Utils
