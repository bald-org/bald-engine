//
// Created by Piotr Moszkowicz on 2018-12-16.
//

#pragma once

#include <string>
#include <vector>

namespace Bald::Utils {

    /**
     * Functions which splits string into pieces by splitter
     * @param str_to_split      String, which needs to be splitted
     * @param delimiter         Char, which delimits split
     * @return                  Vector, with splitted strings
     */
    [[nodiscard]] std::vector<std::string> split_string(const char* str_to_split, char delimiter);

} // END OF NAMESPACE Bald::Utils
