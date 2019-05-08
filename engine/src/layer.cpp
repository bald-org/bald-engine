//
// Created by blinku on 08.05.19.
//

#include "layer.h"
#include "event_manager.h"

namespace Bald {

    void Layer::Enable() noexcept {
        m_IsEnabled = true;
    }

    void Layer::Disable() noexcept {
        m_IsEnabled = false;
    }

    void Layer::RunEvents() {
        EventManager::Flush();
    }

}

