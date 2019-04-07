//
// Created by grzegorz on 21.02.19.
//

#include "callback.h"

namespace Bald {

    std::vector<unsigned> Callback::_takenId;

    Callback::~Callback() {
        auto iter = std::find(_takenId.begin(), _takenId.end(), _id);
        _takenId.erase(iter);
    }

} //END OF NAMESPACE Bald