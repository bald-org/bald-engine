#include <iostream>
#include <string>


#include "src/utils/file_manager.h"

int main() {

    std::string file = Bald::Utils::FileManager::ReadFile("/home/blinku/CLionProjects/BALD/bald-engine/main.cpp", Bald::Utils::FileManager::SMALL);

    std::cout << file << std::endl;

    return 0;
}