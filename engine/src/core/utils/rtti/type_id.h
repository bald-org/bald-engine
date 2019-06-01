//
// Created by grzegorz on 10.05.19.
//

#pragma once

namespace Bald::Utils {

    /**
     * @fn generator_id
     * @brief Function that generates a unique id
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
         * @brief Static function which returns the id of a specific type
         * @return The id of a specific type
         */

        static inline unsigned type_id() noexcept { return id; }

    private:
        static const unsigned int id;
    };

    template<typename T>
    unsigned int const TypeInfo<T>::id = generator_id();

    /**
     * @fn get_type_id
     * @brief Function that returns the id of type T
     * @tparam T The type that is queried for id
     * @return id of type T
     */

    template<typename T>
    inline unsigned get_type_id() noexcept { return TypeInfo<T>::type_id(); }

    /**
     * @fn get_type_id(const T&)
     * @brief Function that returns the id of type of object which was passed
     * @param T -> Object of which type you want to get id
     * @return [unsigned int] Id of type of object
     */

    template<typename T>
    inline unsigned get_type_id(const T&) noexcept {
        return TypeInfo<T>::type_id();
    }

}
