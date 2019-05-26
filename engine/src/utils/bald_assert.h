//
// Created by grzegorz on 24.05.19.
//

#pragma once

#include <string>

#define BALD_STATIC_ASSERT(expr, mess) static_assert(expr, mess)

void Fail(const std::string& file, int line, const std::string& mess);

#ifdef DEBUG

#define BALD_ASSERT(expr, mess) if(!(expr)) { Fail(__FILE__, __LINE__, mess); } //TODO: should be defined only in debug

#else

#define BALD_ASSERT(expr, mess)

#endif




