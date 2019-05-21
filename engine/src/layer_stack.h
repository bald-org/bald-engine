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
        LayerStack();

        ~LayerStack();

        template<typename L>
        void PushLayer();

        template<typename L>
        void PushOverlay();

        template<typename L>
        void PopLayer();

        template<typename L>
        void PopOverlay();

        template<typename L>
        void PushLayerImmediately();

        template<typename L>
        void PushOverlayImmediately();

        template<typename L>
        void PopLayerImmediately();

        template<typename L>
        void PopOverlayImmediately();

        void AttachDetachLayers();

        [[nodiscard]] inline size_t GetSize() const noexcept { return m_LayerStack.size(); }

        inline std::vector<Layer*>::iterator begin() noexcept { return m_LayerStack.begin(); }

        inline std::vector<Layer*>::reverse_iterator rbegin() noexcept { return m_LayerStack.rbegin(); }

        inline std::vector<Layer*>::iterator end() noexcept { return m_LayerStack.end(); }

        inline std::vector<Layer*>::reverse_iterator rend() noexcept { return m_LayerStack.rend(); }

        [[nodiscard]] inline Layer* operator[](size_t index);

    private:

        bool Init();

        void Shutdown();

    private:
        std::vector<Layer*> m_LayerStack; /**< Main layer stack */
        unsigned m_LayersAmount = 0; /**< Current number of layers in main layer stack */

    private:
        std::vector<Layer*> m_ForAddition; /**< Temp layer stack used for holding layers so that they will be pushed AFTER main loop tick */
        unsigned m_ForAdditionAmount = 0; /**< Current number of layers in temp layer stack */

        std::vector<std::type_index> m_ForRemoval;


    }; // END OF CLASS LayerStack

    template<typename L>
    void LayerStack::PushLayer() {
        static_assert(std::is_base_of<Layer, L>::value, "Layer is not the base of L");
        m_ForAddition.emplace(m_ForAddition.begin() + m_ForAdditionAmount, new L{});
        ++m_ForAdditionAmount;
    }

    template<typename L>
    void LayerStack::PushOverlay() {
        static_assert(std::is_base_of<Layer, L>::value, "Layer is not the base of L");
        m_ForAddition.emplace_back(new L{});
    }

    template<typename L>
    void LayerStack::PopLayer() {
        static_assert(std::is_base_of<Layer, L>::value, "Layer is not the base of L");
        m_ForRemoval.emplace_back(typeid(L));
    }

    template<typename L>
    void LayerStack::PopOverlay() {
        static_assert(std::is_base_of<Layer, L>::value, "Overlay is not the base of L");
        m_ForRemoval.emplace_back(typeid(L));
    }

    template<typename L>
    void LayerStack::PushLayerImmediately() {
        CORE_LOG_INFO("[LayerStack] Pushing layer immediately...");

        static_assert(std::is_base_of<Layer, L>::value, "Layer is not the base of L");
        auto* layer = new L{};
        layer->OnAttach();
        m_LayerStack.emplace(m_LayerStack.begin() + m_LayersAmount, layer);
        ++m_LayersAmount;

        CORE_LOG_INFO("[LayerStack] Pushing immediately was successful");
    }

    template<typename L>
    void LayerStack::PushOverlayImmediately() {
        CORE_LOG_INFO("[LayerStack] Pushing overlay immediately...");

        static_assert(std::is_base_of<Layer, L>::value, "Overlay is not the base of L");
        auto* overlay = new L{};
        overlay->OnAttach();
        m_LayerStack.emplace_back(overlay);

        CORE_LOG_INFO("[LayerStack] Pushing immediately was successful");
    }

    template<typename L>
    void LayerStack::PopLayerImmediately() {
        CORE_LOG_INFO("[LayerStack] Popping layer immediately...");

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
            CORE_LOG_INFO("[LayerStack] Popping immediately was successful");
        } else {
            CORE_LOG_WARN("[LayerStack] Could not pop a layer because such layer does not exist in layer stack");
        }
    }

    template<typename L>
    void LayerStack::PopOverlayImmediately() {
        CORE_LOG_INFO("[LayerStack] Popping overlay immediately...");

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
            CORE_LOG_INFO("[LayerStack] Popping immediately was successful");
        } else {
            CORE_LOG_WARN("[LayerStack] Could not pop an overlay because such overlay does not exist in layer stack");
        }
    }

    inline Layer* LayerStack::operator[](size_t index) {
        assert(index < m_LayerStack.size());
        return m_LayerStack[index];
    }

} // END OF NAMESPACE Bald

