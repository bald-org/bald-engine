//
// Created by blinku on 26.02.2020.
//

#pragma once

namespace Bald::Ecs {

    struct Component {
    };

    struct PositionComponent : Component {
        float m_X;
        float m_Y;
        float m_Z;
    };

    struct RotationComponent : Component {
        float m_RotationX;
        float m_RotationY;
        float m_RotationZ;
    };

} // END OF NAMESPACE Bald::Ecs