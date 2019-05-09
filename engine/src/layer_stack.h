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

        template<typename L>
        void PushLayer();

        template<typename L>
        void PushOverlay();

        template<typename L>
        void PopLayer();

        template<typename L>
        void PopOverlay();

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

    template<typename L>
    void LayerStack::PushLayer() {
        CORE_LOG_INFO("[LayerStack] Pushing layer...");

        static_assert(std::is_base_of<Layer, L>::value, "Layer is not the base of L");
        auto* layer = new L{};
        layer->OnAttach();
        m_LayerStack.emplace(m_LayerStack.begin() + m_LayersAmount, layer);
        ++m_LayersAmount;

        CORE_LOG_INFO("[LayerStack] Pushing was successful");
    }

    template<typename L>
    void LayerStack::PushOverlay() {
        CORE_LOG_INFO("[LayerStack] Pushing overlay...");

        static_assert(std::is_base_of<Layer, L>::value, "Overlay is not the base of L");
        auto* overlay = new L{};
        overlay->OnAttach();
        m_LayerStack.emplace_back(overlay);

        CORE_LOG_INFO("[LayerStack] Pushing was successful");
    }

    template<typename L>
    void LayerStack::PopLayer() {
        CORE_LOG_INFO("[LayerStack] Popping layer...");

        static_assert(std::is_base_of<Layer, L>::value, "Layer is not the base of L");

        auto it = m_LayerStack.begin();

        for(; it != m_LayerStack.end(); ++it) {
            if((*it)->GetType() == typeid(L)) {
                break;
            }
        }

        if(it != m_LayerStack.end()) {
            delete *it;
            m_LayerStack.erase(it);
            --m_LayersAmount;
            CORE_LOG_INFO("[LayerStack] Popping was successful");
        } else {
            CORE_LOG_WARN("[LayerStack] Could not pop a layer because such layer does not exist in layer stack");
        }
    }

    template<typename L>
    void LayerStack::PopOverlay() {
        CORE_LOG_INFO("[LayerStack] Popping overlay...");

        static_assert(std::is_base_of<Layer, L>::value, "Overlay is not the base of L");

        auto it = m_LayerStack.begin();

        for(; it != m_LayerStack.end(); ++it) {
            if((*it)->GetType() == typeid(L)) {
                break;
            }
        }

        if(it != m_LayerStack.end()) {
            (*it)->OnDetach();
            delete *it;
            m_LayerStack.erase(it);
            CORE_LOG_INFO("[LayerStack] Popping was successful");
        } else {
            CORE_LOG_WARN("[LayerStack] Could not pop an overlay because such overlayer does not exist in layer stack");
        }
    }

} // END OF NAMESPACE Bald

