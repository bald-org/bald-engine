//
// Created by blinku on 23.05.19.
//

#pragma once

/*
 * @def DERIVED
 * @brief A macro definition. It is used as a flag to mark that the class inherits from another one.
 */
#define DERIVED IS_DERIVED

/*
 * @def DERIVED
 * @brief A macro definition. It is used as a flag to mark that the class is a base for another ones.
 */

#define BASE IS_BASE

/*
 * @def DEF_CLASS_TYPE
 * @brief A macro definition. It defines other macro depending on the argument
 * @param x -> Flag which will be concatenated to macro
 */

#define DEF_CLASS_TYPE(x) DEF_CLASS_TYPE_##x

/*
 * @def DEF_CLASS_TYPE_IS_DERIVED
 * @brief A macro definition. It defines function/functions which derived class needs.
 */

#define DEF_CLASS_TYPE_IS_DERIVED public: \
                                [[nodiscard]] inline unsigned GetType() const noexcept override { return Bald::Utils::get_type_id(*this); }

/*
* @def DEF_CLASS_TYPE_IS_BASE
* @brief A macro definition. It defines function/functions which base class needs.
*/

#define DEF_CLASS_TYPE_IS_BASE public: \
                             [[nodiscard]] virtual unsigned GetType() const noexcept = 0;

/*
* @def DEF_CLASS_TYPE_
* @brief A macro definition. It defines function/functions which ordinary class needs.
*/

#define DEF_CLASS_TYPE_ public: \
                      [[nodiscard]] inline unsigned GetType() const noexcept { return Bald::Utils::get_type_id(*this); }

/*
* @def GENERATE_BODY
* @brief A macro definition. It defines function/functions a class needs.
* @param x -> Flag which is used to determine appropriate functions for certain type of class.
*/

#define GENERATE_BODY(x) DEF_CLASS_TYPE(x)
