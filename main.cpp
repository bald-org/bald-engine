#include <iostream>
#include <string>


#include "src/utils/file_manager.h"

int main() {

    std::string file = ENGINE::UTILS::FileManager::ReadFile("/home/blinku/CLionProjects/BALD/bald-engine/main.cpp", ENGINE::UTILS::FileManager::SMALL);

    std::cout << file << std::endl;

    return 0;
};