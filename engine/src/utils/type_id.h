//
// Created by grzegorz on 10.05.19.
//

#pragma once

namespace Bald {
    inline unsigned generator_id() {
        static unsigned id = 0;
        return id++;
    }

    template <typename T>
    struct TypeInfo {
        static unsigned type_id() {
            return id;
        }

        static const int id;
    };

    template <typename T>
    int const TypeInfo<T>::id = generator_id();

    template <typename T>
    unsigned get_type_id(){
        return TypeInfo<T>::type_id()
    }

    template <typename T>
    unsigned get_type_id(const T&){

    }

}
