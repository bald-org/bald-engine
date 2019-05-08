//
// Created by blinku on 08.05.19.
//

#include "layer.h"
#include "event_manager.h"

namespace Bald {

    void Layer::Attach() noexcept {
        m_Attached = true;
    }

    void Layer::Detach() noexcept {
        m_Attached = false;
    }

    void Layer::RunEvents() {
        EventManager::Flush();
    }

    bool Layer::IsAttached() const noexcept {
        return m_Attached;
    }

}

