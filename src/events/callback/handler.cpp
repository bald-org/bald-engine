//
// Created by grzegorz on 21.02.19.
//

#include "handler.h"

namespace Bald {

    std::vector<bool> Handler::m_TakenID;

    Handler::~Handler() {
        m_TakenID[m_ID - 1] = false;
    }

} //END OF NAMESPACE Bald
