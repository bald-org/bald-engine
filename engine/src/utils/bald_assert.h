//
// Created by grzegorz on 24.05.19.
//

#pragma once

#include <utility>
#include <string>
#include <iostream>
#include <csignal>
#include <cstdio>
#include "logger.h"

#define BALD_STATIC_ASSERT(expr, mess) static_assert(expr, mess)

#ifdef DEBUG


class SourceInfo {
public:
    SourceInfo(std::string file, int line) :
            _file(std::move(file)), _line(line) { };
    const std::string _file;
    const int _line;
};

class Assert {
public:
    // logs the formatted message
    template<typename... Args>
    Assert(const SourceInfo& sourceInfo, const char* format, Args... args) {
        CORE_LOG_ERROR(sourceInfo._file + " (" + std::to_string(sourceInfo._line) + ") ");
        printf(format, args...);
        printf("\n");
    }

    //Assert& Variable(const char* const name, bool var);
    // more overloads for built-in types...

    // generic
    template<typename T>
    Assert& Variable(const char* const name, const T& value) {
        std::cout << name << " = " << value << "\n";
        return *this;
    }

    Assert& Variable(const char* const name, bool value) {
        CORE_LOG_ERROR(std::string(name) + " = " + (value ? "true" : "false"));
        return *this;
    }
    Assert& Variable(const char* const name, int value) {
        CORE_LOG_ERROR(std::string(name) + " = " + std::to_string(value));
        return *this;
    }
    Assert& Variable(const char* const name, double value) {
        CORE_LOG_ERROR(std::string(name) + " = " + std::to_string(value));
        return *this;
    }
    Assert& Variable(const char* const name, float value) {
        CORE_LOG_ERROR(std::string(name) + " = " + std::to_string(value));
        return *this;
    }
    Assert& Variable(const char* const name, const char* value) {
        CORE_LOG_ERROR(std::string(name) + " = " + std::string(value));
        return *this;
    }
    Assert& Variable(const char* const name, size_t value) {
        CORE_LOG_ERROR(std::string(name) + " = " + std::to_string(value));
        return *this;
    }
};

#define BALD_BREAKPOINT std::raise(SIGTRAP);
#define BALD_SOURCE_INFO SourceInfo(__FILE__, __LINE__)

#define BALD_PP_EXPAND_ARGS_1(op, a1)                op(a1)
#define BALD_PP_EXPAND_ARGS_2(op, a1, a2)            op(a1) op(a2)
#define BALD_PP_EXPAND_ARGS_3(op, a1, a2, a3)        op(a1) op(a2) op(a3)
#define BALD_PP_EXPAND_ARGS_4(op, a1, a2, a3, a4)    op(a1) op(a2) op(a3) op(a4)

#define BALD_PP_NUM_ARGS(...)                        BALD_PP_NUM_ARGS_HELPER(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define BALD_PP_NUM_ARGS_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...)    N
#define BALD_PP_EXPAND_ARGS(op, ...) BALD_PP_JOIN(BALD_PP_EXPAND_ARGS_, BALD_PP_NUM_ARGS(__VA_ARGS__))(op, __VA_ARGS__)


#define BALD_ASSERT_IMPL_VARS(...)                   BALD_PP_EXPAND_ARGS(BALD_ASSERT_IMPL_VAR, __VA_ARGS__), BALD_BREAKPOINT; }
#define BALD_ASSERT_IMPL(condition, format, ...)     if(!(condition))  { Assert(BALD_SOURCE_INFO, "Assertion \"" #condition "\" failed. " format, __VA_ARGS__) BALD_ASSERT_IMPL_VARS
#define BALD_ASSERT_IMPL_VAR(variable)               .Variable("" #variable "", variable)

#define BALD_ASSERT(condition, name, message, ...) BALD_ASSERT_IMPL(condition, "[%s] %s ", name, message)(__VA_ARGS__)


#define BALD_PP_JOIN(x, y)                    BALD_JOIN_HELPER(x, y)
#define BALD_JOIN_HELPER(x, y)                BALD_JOIN_HELPER_HELPER(x, y)
#define BALD_JOIN_HELPER_HELPER(x, y)         x##y


#else

#define BALD_ASSERT(...)

#endif




