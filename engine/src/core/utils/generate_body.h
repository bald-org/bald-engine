//
// Created by blinku on 23.05.19.
//

#pragma once

#define DERIVED IS_DERIVED

#define DEF_OVERRIDE(x) DEF_OVERRIDE_##x
#define DEF_OVERRIDE_IS_DERIVED override
#define DEF_OVERRIDE_

#define GENERATE_BODY(x) public: \
                         [[nodiscard]] inline unsigned GetType() const DEF_OVERRIDE(x) { return Bald::Utils::get_type_id(*this); }
