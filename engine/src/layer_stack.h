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

        ~LayerStack();

        template<typename L>
        void PushLayerImmediately();

        template<typename L>
        void PushOverlayImmediately();

        template<typename L>
        void PopLayerImmediately();

        template<typename L>
        void PopOverlayImmediately();

        [[nodiscard]] inline size_t GetSize() const noexcept;

        inline std::vector<Layer*>::iterator begin();

        inline std::vector<Layer*>::reverse_iterator rbegin();

        inline std::vector<Layer*>::iterator end();

        inline std::vector<Layer*>::reverse_iterator rend();

        [[nodiscard]] inline Layer* operator[](size_t i);

    private:

        bool Init();

        void Shutdown();

    private:
        std::vector<Layer*> m_LayerStack;
        unsigned m_LayersAmount = 0;
    }; // END OF CLASS LayerStack

    inline size_t LayerStack::GetSize() const noexcept {
        return m_LayerStack.size();
    }

    inline std::vector<Layer*>::iterator LayerStack::begin() {
        return m_LayerStack.begin();
    }

    inline std::vector<Layer*>::reverse_iterator LayerStack::rbegin() {
        return m_LayerStack.rbegin();
    }

    inline std::vector<Layer*>::iterator LayerStack::LayerStack::end() {
        return m_LayerStack.end();
    }

    inline std::vector<Layer*>::reverse_iterator LayerStack::rend() {
        return m_LayerStack.rend();
    }

    inline Layer* LayerStack::operator[](size_t i) {
        return m_LayerStack[i];
    }

    template<typename L>
    void LayerStack::PushLayerImmediately() {
        CORE_LOG_INFO("[LayerStack] Pushing layer immediatly...");

        static_assert(std::is_base_of<Layer, L>::value, "Layer is not the base of L");
        auto* layer = new L{};
        layer->OnAttach();
        m_LayerStack.emplace(m_LayerStack.begin() + m_LayersAmount, layer);
        ++m_LayersAmount;

        CORE_LOG_INFO("[LayerStack] Pushing immediatly was successful");
    }

    template<typename L>
    void LayerStack::PushOverlayImmediately() {
        CORE_LOG_INFO("[LayerStack] Pushing overlay immediatly...");

        static_assert(std::is_base_of<Layer, L>::value, "Overlay is not the base of L");
        auto* overlay = new L{};
        overlay->OnAttach();
        m_LayerStack.emplace_back(overlay);

        CORE_LOG_INFO("[LayerStack] Pushing immediatly was successful");
    }

    template<typename L>
    void LayerStack::PopLayerImmediately() {
        CORE_LOG_INFO("[LayerStack] Popping layer immediatly...");

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
            CORE_LOG_INFO("[LayerStack] Popping immediatly was successful");
        } else {
            CORE_LOG_WARN("[LayerStack] Could not pop a layer because such layer does not exist in layer stack");
        }
    }

    template<typename L>
    void LayerStack::PopOverlayImmediately() {
        CORE_LOG_INFO("[LayerStack] Popping overlay immediatly...");

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
            CORE_LOG_INFO("[LayerStack] Popping immediatly was successful");
        } else {
            CORE_LOG_WARN("[LayerStack] Could not pop an overlay because such overlay does not exist in layer stack");
        }
    }

} // END OF NAMESPACE Bald

