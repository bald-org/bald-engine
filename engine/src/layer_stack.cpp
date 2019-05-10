//
// Created by blinku on 10.05.19.
//

#include "layer_stack.h"

namespace Bald {

    LayerStack::~LayerStack() {
        Shutdown();
    }

    void LayerStack::Shutdown() {
        for(Layer* layer : m_LayerStack) {
            delete layer;
        }
    }

}

