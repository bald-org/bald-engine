//
// Created by grzegorz on 11.05.19.
//

#pragma once

#include <cstdlib>
#include <memory>
#include <cxxabi.h>
#include <typeindex>

template <typename T>
std::string type_name(){
    const char* name = typeid(T).name();
    int status = 0;
    std::unique_ptr<char, void(*)(void*)> result {
        abi::__cxa_demangle(name, nullptr, nullptr, & status),
        std::free
    };
    return (status == 0) ? result.get() : name;
}

template <typename T>
std::string type_name(const T&){
    const char* name = typeid(T).name();
    int status = 0;
    std::unique_ptr<char, void(*)(void*)> result {
            abi::__cxa_demangle(name, nullptr, nullptr, & status),
            std::free
    };
    return (status == 0) ? result.get() : name;
}
