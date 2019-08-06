//
// Created by grzegorz on 01.06.19.
//

#pragma once

#include <string>

namespace Bald::Debug {

    /**
     * @class Logger
     * @brief Prints formatted messages to console.
     */

    class Logger {
    public:

        /**
         * @fn Logger
         * @brief Constructs new logger object.
         * @param name [std::string] -> Name of logger.
         */

        explicit Logger(std::string name): m_Name(std::move(name)) {}

        /**
         * @fn Logger
         * @brief Default constructor of logger class
         */

        explicit Logger() = default;

        /**
         * @fn setName
         * @brief Updates logger's name.
         * @param name
         */

        void SetName(const std::string& name);

        /**
         * @fn trace
         * @brief Prints message with white color.
         * @param mess [std::string] content of the message.
         */

        void trace(const std::string& mess) const noexcept;

        /**
         * @fn info
         * @brief Prints message with green color.
         * @param mess [std::string] content of the message.
         */

        void info(const std::string& mess) const noexcept;

        /**
         * @fn warn
         * @brief Prints message with yellow color.
         * @param mess [std::string] content of the message.
         */

        void warn(const std::string& mess) const noexcept;

        /**
         * @fn error
         * @brief Prints message with red color.
         * @param mess [std::string] content of the message.
         */

        void error(const std::string& mess) const noexcept;

    private:

        /**
         * @fn Print
         * @brief Prints message.
         * @param mess [std::string] content of the message.
         */

        void Print(const std::string& mess) const noexcept;

        /**
         * @fn Red
         * @brief Changes color of the message to red
         */

        static void Red() noexcept;

        /**
         * @fn Yellow
         * @brief Changes color of the message to yellow
         */

        static void Yellow() noexcept;

        /**
         * @fn Green
         * @brief Changes color of the message to green
         */

        static void Green() noexcept;

        /**
         * @fn Reset
         * @brief Changes color of the message to white
         */

        static void Reset() noexcept;

    private:
        std::string m_Name; /*< Name of the logger.*/
    }; //END OF CLASS Logger
} //END OF NAMESPACE Bald::Debug