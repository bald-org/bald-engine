//
// Created by blinku on 23.05.19.
//

#pragma once

#define DERIVED IS_DERIVED
#define BASE IS_BASE

#define DEF_OVERRIDE(x) DEF_OVERRIDE_##x
#define DEF_OVERRIDE_IS_DERIVED public: \
                                [[nodiscard]] inline unsigned GetType() const override { return Bald::Utils::get_type_id(*this); }
#define DEF_OVERRIDE_IS_BASE public: \
                             [[nodiscard]] virtual unsigned GetType() const = 0;
#define DEF_OVERRIDE_ public: \
                      [[nodiscard]] inline unsigned GetType() const { return Bald::Utils::get_type_id(*this); }

#define GENERATE_BODY(x) DEF_OVERRIDE(x)
