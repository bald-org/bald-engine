//
// Created by grzegorz on 10.05.19.
//

#pragma once

namespace Bald {

    /**
     * @fn generator_id
     * @brief Function that generate unique id
     * @return [unsigned int] Generated id
     */

    inline unsigned generator_id() noexcept {
        static unsigned id = 0;
        return id++;
    }

    /**
     * @struct TypeInfo
     * @brief Simple structure for id of specific type T
     * @tparam T Type for which structure holds id
     */

    template<typename T>
    struct TypeInfo {
        TypeInfo() = delete;

        /**
         * @fn type_id
         * @brief Static function which returns
         * @return
         */

        static inline unsigned type_id() noexcept {
            return id;
        }

    private:
        static const int id;
    };

    template<typename T>
    int const TypeInfo<T>::id = generator_id();

    /**
     * @fn get_type_id
     * @brief Function that returns the id of type T
     * @tparam T Type of which we want to get the id
     * @return id of type T
     */

    template<typename T>
    inline unsigned get_type_id() {
        return TypeInfo<T>::type_id();
    }

    /**
     * @fn get_type_id(const T&)
     * @brief Function that returns the id of type of object which was passed
     * @param T -> Object of which type you want to get id
     * @return [unsigned int] Id of type of object
     */

    template<typename T>
    inline unsigned get_type_id(const T&) {
        return TypeInfo<T>::type_id();
    }

}
