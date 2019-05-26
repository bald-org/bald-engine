//
// Created by grzegorz on 25.05.19.
//

#include "bald_assert.h"
#include "pch.h"

void Fail(const std::string& file, int line, const std::string& mess) {
    CORE_LOG_ERROR("Assertion failed in " + file + " in line: " + std::to_string(line) + " " + mess);
}

