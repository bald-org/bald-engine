//
// Created by blinku on 10.05.19.
//

#include "layer.h"

namespace Bald {

    void Layer::Shutdown() {
        m_EventManager.RemoveAllCallbacks();
    }

}