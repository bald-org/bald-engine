//
// Created by grzegorz on 24.05.19.
//

#pragma once

#include <iostream>


#define BALD_STATIC_ASSERT(expr, mess) static_assert(expr, mess)

inline void Fail(const std::string& file, int line, const std::string& mess) {
    std::cout << file << " " << line << " " << mess << "\n"; //TODO: use our logger
}

#define BALD_ASSERT(expr, mess) if(!(expr)) { Fail(__FILE__, __LINE__, mess); } //TODO: should be defined only in debug

//TODO: refactor our classes to use them


