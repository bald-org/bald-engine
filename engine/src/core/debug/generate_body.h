//
// Created by blinku on 23.05.19.
//

#pragma once

#include "utils.h"

#define DEF_OVERRIDE(x) DEF_OVERRIDE_##x
#define DEF_OVERRIDE_true override
#define DEF_OVERRIDE_false

#define GENERATE_BODY(x) public: \
                         [[nodiscard]] inline unsigned GetType() const DEF_OVERRIDE(Bald::Utils::ConstexprStringCmp((x), "DERIVED")) { return Bald::Utils::get_type_id(*this); }


