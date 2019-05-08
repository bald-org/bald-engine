//
// Created by blinku on 08.05.19.
//

#include "layer_stack.h"

namespace Bald {

    void LayerStack::PushLayer(Layer* layer) {
        m_LayerStack.emplace(m_LayerStack.begin() + m_LayersAmount, layer);
        layer->OnAttach();
        ++m_LayersAmount;
    }

    void LayerStack::PushOverlay(Layer* overlay) {
        m_LayerStack.emplace_back(overlay);
        overlay->OnAttach();
    }

    void LayerStack::PopLayer(Layer* layer) {
        CORE_LOG_INFO("[LayerStack] Popping layer...");

        layer->OnDetach();

        auto it = std::find(m_LayerStack.begin(), m_LayerStack.end(), layer);

        if(it != m_LayerStack.end()) {
            m_LayerStack.erase(it);
            delete *it;
            --m_LayersAmount;
            CORE_LOG_INFO("[LayerStack] Popping was successful...");
        } else {
            CORE_LOG_WARN("[LayerStack] Could not pop a layer because such layer does not exist in layer stack");
        }
    }

    void LayerStack::PopOverlay(Layer* overlay) {
        CORE_LOG_INFO("[LayerStack] Popping overlay...");

        overlay->OnDetach();

        auto it = std::find(m_LayerStack.begin(), m_LayerStack.end(), overlay);

        if(it != m_LayerStack.end()) {
            m_LayerStack.erase(it);
            delete *it;
            CORE_LOG_INFO("[LayerStack] Popping was successful...");
        } else {
            CORE_LOG_WARN("[LayerStack] Could not pop an overlay because such overlayer does not exist in layer stack");
        }
    }

} // END OF NAMESPACE Bald