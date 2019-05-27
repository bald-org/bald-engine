//
// Created by blinku on 10.05.19.
//

#include "layer_stack.h"

namespace Bald {

    LayerStack::LayerStack() {
        [[maybe_unused]] bool state = Init();
        assert(state);
    }

    LayerStack::~LayerStack() {
        Shutdown();
    }

    void LayerStack::AttachLayers() {
        for(size_t i = 0; i < m_ForAddition.size(); ++i) {
            if(i < m_ForAdditionAmount) {
                CORE_LOG_INFO("[LayerStack] Pushing layer...");
                m_ForAddition[i]->OnAttach();
                m_LayerStack.emplace(m_LayerStack.begin() + m_LayersAmount, m_ForAddition[i]);
                ++m_LayersAmount;
                CORE_LOG_INFO("[LayerStack] Pushing was successful");
            } else {
                CORE_LOG_INFO("[LayerStack] Pushing layer...");
                m_ForAddition[i]->OnAttach();
                m_LayerStack.emplace_back(m_ForAddition[i]);
                CORE_LOG_INFO("[LayerStack] Pushing was successful");
            }
        }

        m_ForAddition.clear();
        m_ForAdditionAmount = 0;
    }

    void LayerStack::DetachLayers() {
        for(size_t i = 0; i < m_ForRemoval.size(); ++i) {
            CORE_LOG_INFO("[LayerStack] Popping layer...");
            auto it = m_LayerStack.begin();

            for(; it != m_LayerStack.end(); ++it) {
                if((*it)->GetType() == m_ForRemoval[i]) {
                    break;
                }
            }

            if(it != m_LayerStack.end()) {
                (*it)->OnDetach();
                delete *it;
                m_LayerStack.erase(it);
                CORE_LOG_INFO("[LayerStack] Popping was successful");
            } else {
                CORE_LOG_WARN("[LayerStack] Could not pop an overlay because such overlay does not exist in layer stack");
            }
        }

        m_ForRemoval.clear();
    }

    bool LayerStack::Init() {
        CORE_LOG_INFO("[LayerStack] Initializing layer stack...");

        CORE_LOG_INFO("[LayerStack] Initialization was successful");

        return true;
    }

    void LayerStack::Shutdown() {
        // TODO: Think if we need to call layer->OnDetach() here!
        CORE_LOG_INFO("[LayerStack] Shutting down layer stack...");

        for(Layer* layer : m_LayerStack) {
            delete layer;
        }

        CORE_LOG_INFO("[LayerStack] Shutdown was successful");
    }

}

