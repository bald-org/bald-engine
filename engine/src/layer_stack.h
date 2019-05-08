//
// Created by blinku on 08.05.19.
//

#pragma once

#include <vector>
#include <algorithm>

#include "layer.h"
#include "Log.h"

namespace Bald {

    class LayerStack {
    public:
        LayerStack() = default;

        ~LayerStack() = default;

        void PushLayer(Layer* layer);

        void PushOverlay(Layer* overlay);

        void PopLayer(Layer* layer);

        void PopOverlay(Layer* overlay);

        inline std::vector<Layer*>::iterator begin();

        inline std::vector<Layer*>::iterator end();

    private:
        std::vector<Layer*> m_LayerStack;
        unsigned m_LayersAmount = 0;
    }; // END OF CLASS LayerStack

    inline std::vector<Layer*>::iterator LayerStack::begin() {
        return m_LayerStack.begin();
    }

    inline std::vector<Layer*>::iterator LayerStack::end() {
        return m_LayerStack.end();
    }

} // END OF NAMESPACE Bald

