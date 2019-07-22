//
// Created by Piotr Moszkowicz on 2018-12-16.
//

#include "split_string.h"

#include "core/pch.h"

namespace Bald::Utils {

    std::vector<std::string> split_string(const char* str_to_split, char delimiter) {
        std::vector<std::string> result;
        std::string temp;
        std::string str(str_to_split);
        std::istringstream stream(str);

        while (std::getline(stream, temp, delimiter)) {
            result.push_back(temp);
        }
        return result;
    }
}// END OF NAMESPACE Bald::Utils