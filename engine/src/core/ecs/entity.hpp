//
// Created by blinku on 26.02.2020.
//

#pragma once

#include "utils/generate_body.h"

namespace Bald::Ecs {

    struct Entity {
        using SignatureType = std::uint32_t;

        static inline SignatureType m_Signature{};
    };

    struct Model : Entity {
    };

    struct Camera : Entity {
    };

} // END OF NAMESPACE Bald::Ecs