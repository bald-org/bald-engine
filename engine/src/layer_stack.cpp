//
// Created by blinku on 10.05.19.
//

#include "layer_stack.h"

namespace Bald {

    LayerStack::~LayerStack() {
        Shutdown();
    }

    void LayerStack::Shutdown() {
        // TODO: Think if we need to call layer->OnDetach() here!
        for(Layer* layer : m_LayerStack) {
            delete layer;
        }
    }

}

