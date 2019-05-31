//
// Created by grzegorz on 24.05.19.
//

#pragma once

#include <utility>
#include <string>
#include <csignal>
#include <cstdio>
#include "logger.h"

#define BALD_STATIC_ASSERT(expr, mess) static_assert(expr, mess)

#ifdef DEBUG

#include <iostream>

namespace Bald::Debug {

    /**
     * @class SourceInfo
     * @brief Simple class to store information about failed assert
     */

    class SourceInfo {
    public:
        /**
         * @fn SourceInfo
         * @brief Constructs new SourceInfo object
         * @param file [std::string] name of a file where assertion occurred
         * @param line [int] number of line where assertion occurred
         */

        SourceInfo(std::string&& file, int line) :
                _file(std::move(file)), _line(line) { };
        const std::string _file; /**< name of a file where assertion occurred >*/
        const int _line;         /**< number of line where assertion occurred >*/
    };

    /**
     * @class Assert
     * @brief Class which prints information about failed assert
     */

    class Assert {
    public:

        /**
         * @fn Assert
         * @brief Constructs new Asserts objects and prints information about it
         * @tparam Args -> Types of arguments passed to a constructor
         * @param sourceInfo [SourceInfo] Information about the source of the assertion
         * @param format [const char*] Format of a message that will be printed
         * @param args Arguments that will be printed in the message
         */

        template<typename... Args>
        Assert(const SourceInfo& sourceInfo, const char* format, Args... args) {
            CORE_LOG_ERROR(sourceInfo._file + " (" + std::to_string(sourceInfo._line) + ") ");
            printf(format, args...);
            printf("\n");
        }

        /**
         * @fn Variable
         * @brief Prints value and name of a variable
         * @tparam T -> Type of a variable
         * @param name [const char*] Name of a variable
         * @param value [T] A variable which will be printed
         * @return [Assert&] reference to Assert object
         */

        template<typename T>
        Assert& Variable(const char* const name, const T& value) {
            std::cout << name << " = " << value << "\n";
            return *this;
        }

        /**
         * @fn Variable
         * @brief Specialization for bool type
         * @param name [const char*] Name of a variable
         * @param value [bool] A variable which will be printed
         * @return [Assert&] reference to Assert object
         */

        Assert& Variable(const char* const name, bool value) {
            std::cout << name << " = " << ( value ? "true" : "false" );
            return *this;
        }
    };
}

/**
 * @def BALD_BREAKPOINT
 * @brief A macro definition. Instruction that emits SIGTRAP signal.
 */

#define BALD_BREAKPOINT std::raise(SIGTRAP);

/**
 * @def BALD_SOURCE_INFO
 * @brief A macro definition. Creat a SourceInfo object.
 */

#define BALD_SOURCE_INFO ::Bald::Debug::SourceInfo(__FILE__, __LINE__)

/**
 * @def BALD_PP_EXPAND_ARGS_N
 * @brief A macro definitions. Creates N function calls to op
 * @param op -> Function to which calls will be generated
 * @param aN -> Parameter which will be passed to N-th function call
 */

#define BALD_PP_EXPAND_ARGS_1(op, a1)                                op(a1)
#define BALD_PP_EXPAND_ARGS_2(op, a1, a2)                            op(a1) op(a2)
#define BALD_PP_EXPAND_ARGS_3(op, a1, a2, a3)                        op(a1) op(a2) op(a3)
#define BALD_PP_EXPAND_ARGS_4(op, a1, a2, a3, a4)                    op(a1) op(a2) op(a3) op(a4)
#define BALD_PP_EXPAND_ARGS_5(op, a1, a2, a3, a4, a5)                op(a1) op(a2) op(a3) op(a4) op(a5)
#define BALD_PP_EXPAND_ARGS_6(op, a1, a2, a3, a4, a5, a6)            op(a1) op(a2) op(a3) op(a4) op(a5) op(a6)
#define BALD_PP_EXPAND_ARGS_7(op, a1, a2, a3, a4, a5, a6, a7)        op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7)
#define BALD_PP_EXPAND_ARGS_8(op, a1, a2, a3, a4, a5, a6, a7, a8)    op(a1) op(a2) op(a3) op(a4) op(a5) op(a6) op(a7) op(a8)

/**
 * @def BALD_PP_NUM_ARGS
 * @brief A macro definitions. Returns number of arguments passed to a macro, but no more than 10
 */

#define BALD_PP_NUM_ARGS(...)  BALD_PP_NUM_ARGS_HELPER(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define BALD_PP_NUM_ARGS_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...)    N

/**
 * @def BALD_PP_EXPAND_ARGS
 * @brief A macro definition. Expands arguments to function calls.
 */

#define BALD_PP_EXPAND_ARGS(op, ...) BALD_PP_JOIN(BALD_PP_EXPAND_ARGS_, BALD_PP_NUM_ARGS(__VA_ARGS__))(op, __VA_ARGS__)

/**
 * @def BALD_ASSERT_IMPL_VARS
 * @brief A macro definition. Expands arguments and puts a breakpoint after assert is printed
 */

#define BALD_ASSERT_IMPL_VARS(...)                             BALD_PP_EXPAND_ARGS(BALD_ASSERT_IMPL_VAR, __VA_ARGS__), BALD_BREAKPOINT; }

/**
 * @def BALD_ASSERT_IMPL_VAR
 * @brief A macro definition. Generates a call to a function which will print the name and value of the variable
 */

#define BALD_ASSERT_IMPL_VAR(variable)                         .Variable("" #variable "", variable)
#define BALD_ASSERT_IMPL(condition, format, name, message)     if(!(condition))  { ::Bald::Debug::Assert(BALD_SOURCE_INFO, "Assertion \"" #condition "\" failed. " format, name, message) BALD_ASSERT_IMPL_VARS

#define BALD_ASSERT(condition, name, message, ...) BALD_ASSERT_IMPL(condition, "[%s]\n%s ", name, message)(__VA_ARGS__)


#define BALD_PP_JOIN(x, y)                    BALD_JOIN_HELPER(x, y)
#define BALD_JOIN_HELPER(x, y)                x##y


#else

#define BALD_ASSERT(...)
#define BALD_ASSERT_IMPL(...) BALD_ASSERT_IMPL_VARS
#define BALD_ASSERT_IMPL_VARS

#endif




