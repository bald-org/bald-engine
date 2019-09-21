//
// Created by grzegorz on 11.05.19.
//

#pragma once

#include <cstdlib>
#include <string>

#ifdef __GNUG__

#include <memory>
#include <cxxabi.h>
#include <typeindex>

namespace Bald::Utils {

    /**
     * @fn type_name
     * @brief Function that demangles name of type T
     * @tparam T Type of which we want to demangle name
     * @return [std::string] -> Name of type T
     */

    template<typename T>
    std::string type_name() {
        const char* name = typeid(T).name();
        int status = 0;
        std::unique_ptr<char, void (*)(void*)> result{
                abi::__cxa_demangle(name, nullptr, nullptr, &status),
                std::free
        };
        return ( status == 0 ) ? result.get() : name;
    }

    /**
     * @fn type_name(const T&)
     * @brief Function that demangles name of type of object passed to it
     * @param T Object which type name we want to demangle
     * @return [std::string] -> Name of type of object
     */

    template<typename T>
    std::string type_name(const T&) {
        const char* name = typeid(T).name();
        int status = 0;
        std::unique_ptr<char, void (*)(void*)> result{
                abi::__cxa_demangle(name, nullptr, nullptr, &status),
                std::free
        };
        return ( status == 0 ) ? result.get() : name;
    }
} // END OF NAMESPACE Bald

#else

namespace Bald::Utils {

    /**
     * @fn type_name
     * @brif function that returns raw type name of type T because our demangling is compiler specific
     */

    template <typename T>
    std::string type_name(){
        return typeid(T).name();
    }

    /**
     * @fn type_name
     * @brif function that returns raw type name of object passed to it because our demangling is compiler specific
     */

    template <typename T>
    std::string type_name(const T&){
        return typeid(T).name();
    }
} // END OF NAMESPACE Bald

#endif
