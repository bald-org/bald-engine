//
// Created by Piotr Moszkowicz on 2018-12-16.
//

#include "split_string.h"

#include "pch.h"

namespace Bald::Utils {
    std::vector<std::string> split_string(const char* str_to_split, char splitter) {
        std::vector<std::string> result;
        std::string temp;
        auto str = static_cast<std::string>(str_to_split);
        std::istringstream stream(str);

        while (std::getline(stream, temp, splitter)) {
            result.push_back(temp);
        }
        return result;
    }
}