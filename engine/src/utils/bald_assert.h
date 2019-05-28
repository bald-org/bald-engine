#include <utility>

//
// Created by grzegorz on 24.05.19.
//

#pragma once

#include <string>
#include <iostream>
#include <csignal>
#include <cstdio>

#define BALD_STATIC_ASSERT(expr, mess) static_assert(expr, mess)

void Fail(const std::string& file, int line, const std::string& mess);

#ifdef DEBUG


class SourceInfo {
public:
    SourceInfo(std::string  file, int line): _file(std::move(file)), _line(line) {};
    const std::string _file;
    const int _line;
};

class Assert
{
public:
    // logs the formatted message
    Assert() = default;
    Assert(const SourceInfo& sourceInfo, const char* format, const char* args ...){
        printf("%s (%d) ", sourceInfo._file.c_str(), sourceInfo._line);
        printf(format, args);
        printf("\n");
    };

    //Assert& Variable(const char* const name, bool var);
    // more overloads for built-in types...

    // generic
    template <typename T>
    Assert& Variable(const char* const name, const T& value){
        std::cout << name << " = " << value << "\n";
        return *this;
    }
};

#define ME_BREAKPOINT std::raise(SIGINT);
#define ME_SOURCE_INFO SourceInfo(__FILE__, __LINE__)
#define ME_UNUSED Assert{}

#define ME_PP_EXPAND_ARGS_1(op, a1)                op(a1)
#define ME_PP_EXPAND_ARGS_2(op, a1, a2)            op(a1) op(a2)
#define ME_PP_EXPAND_ARGS_3(op, a1, a2, a3)        op(a1) op(a2) op(a3)
#define ME_PP_EXPAND_ARGS_4(op, a1, a2, a3, a4)    op(a1) op(a2) op(a3) op(a4)

#define ME_PP_NUM_ARGS(...)                        ME_PP_NUM_ARGS_HELPER(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define ME_PP_NUM_ARGS_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...)    N
#define ME_PP_EXPAND_ARGS(op, ...) ME_PP_JOIN(ME_PP_EXPAND_ARGS_, ME_PP_NUM_ARGS(__VA_ARGS__))(op, __VA_ARGS__)


#define ME_ASSERT_IMPL_VARS(...)              ME_PP_EXPAND_ARGS(ME_ASSERT_IMPL_VAR, __VA_ARGS__), ME_BREAKPOINT; }
#define BALD_ASSERT(condition, format, ...)     if(condition) { } else { Assert(ME_SOURCE_INFO, "Assertion \"" #condition "\" failed. " format, __VA_ARGS__) ME_ASSERT_IMPL_VARS
#define ME_ASSERT_IMPL_VAR(variable)          .Variable("" #variable "", variable)



#define ME_PP_JOIN(x, y)                    ME_JOIN_HELPER(x, y)
#define ME_JOIN_HELPER(x, y)             ME_JOIN_HELPER_HELPER(x, y)
#define ME_JOIN_HELPER_HELPER(x, y)      x##y


#else

#define BALD_ASSERT(condition, format, ...)

#endif




