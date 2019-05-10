//
// Created by grzegorz on 08.05.19.
//
#include "event_handler_interface.h"

namespace Bald {

    std::vector<bool> EventHandlerInterface::m_TakenID;

    EventHandlerInterface::EventHandlerInterface()
            :   m_ID(0) {
        for (unsigned int i = 1; i < UINT32_MAX; ++i) {
            if (i <= m_TakenID.size() && m_TakenID[i - 1] == false) {
                m_TakenID[i - 1] = true;
                m_ID = i;
                break;
            } else if (i > m_TakenID.size()) {
                m_TakenID.push_back(true);
                m_ID = i;
                break;
            }
        }
    }

    EventHandlerInterface::~EventHandlerInterface() {
        m_TakenID[m_ID - 1] = false;
    }
}
