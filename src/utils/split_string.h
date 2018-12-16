//
// Created by Piotr Moszkowicz on 2018-12-16.
//

#pragma once

#include <string>
#include <vector>

namespace Bald::Utils {
    [[nodiscard]] std::vector<std::string> split_string(const char* str_to_split, char splitter);
}
