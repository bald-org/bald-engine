//
// Created by grzegorz on 21.02.19.
//

#include "handler.h"

namespace Bald {

    std::vector<unsigned> Handler::m_TakenID;

    Handler::~Handler() {
        auto iter = std::find(m_TakenID.begin(), m_TakenID.end(), m_ID);
        m_TakenID.erase(iter);
    }

} //END OF NAMESPACE Bald
