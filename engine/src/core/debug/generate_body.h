//
// Created by blinku on 23.05.19.
//

#pragma once

#include "utils.h"

#define DEF_OVERRIDE(x) DEF_OVERRIDE_##x
#define DEF_OVERRIDE_true [[nodiscard]] inline unsigned GetType() const override { return Bald::Utils::get_type_id(*this); }
#define DEF_OVERRIDE_false [[nodiscard]] inline unsigned GetType() const { return Bald::Utils::get_type_id(*this); }

#define GENERATE_BODY(...) public: \
                         DEF_OVERRIDE(Bald::Utils::ConstexprStringCmp(__VA_ARGS__, "DERIVED");)
