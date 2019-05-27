//
// Created by blinku on 08.05.19.
//

#pragma once

#include <vector>
#include <algorithm>

#include "layer.h"
#include "core/debug/logger.h"

#include "layer_events.h"

namespace Bald {

    /**
     * @class LayerStack
     * @brief Simple wrapper for std::vector which behaves like a layer stack.
     */

    class LayerStack {
    GENERATE_BODY()
    public:

        /**
         * @fn LayerStack
         * @brief Layer stack constructor.
         */

        LayerStack();

        /**
         * @fn ~LayerStack
         * @brief Layer stack destructor.
         */

        ~LayerStack();

        /**
         * @fn PushLayer
         * @brief Templated method which pushes a layer onto the layer stack.
         *        It does it at the AFTER all OnUpdate/RunEvent calls.
         * @tparam [L] This template parameter must be a class derived from Layer class.
         * @tparam [... Args] This template parameter is optional. It is used to pass right arguments to the Layer's constructor.
         * @param [Args&& ...] args -> This parameter is optional. Variadic number of arguments for Layer's constructor.
         */

        template<typename L, typename ... Args>
        void PushLayer(Args&& ... args);

        /**
         * @fn PushOverlay
         * @brief Templated method which pushes an overlay onto the layer stack.
         *        It does it at the AFTER all OnUpdate/RunEvent calls.
         * @tparam [L] This template parameter must be a class derived from Layer class.
         * @tparam [... Args] This template parameter is optional. It is used to pass right arguments to the Layer's constructor.
         * @param [Args&& ...] args -> This parameter is optional. Variadic number of arguments for Layer's constructor.
         */

        template<typename L, typename ... Args>
        void PushOverlay(Args&& ... args);

        /**
         * @fn PopLayer
         * @brief Templated method which pops a layer from the layer stack.
         *        It does it at the AFTER all OnUpdate/RunEvent calls.
         * @tparam [L] This template parameter must be a class derived from Layer class.
         */

        template<typename L>
        void PopLayer();

        /**
         * @fn PopOverlay
         * @brief Templated method which pops an overlay from the layer stack.
         *        It does it at the AFTER all OnUpdate/RunEvent calls.
         * @tparam [L] This template parameter must be a class derived from Layer class.
         */

        template<typename L>
        void PopOverlay();

        /**
         * @fn PushLayerImmediately
         * @brief Templated method which pushes a layer onto the layer stack as soon as the method is called.
         * @tparam [L] This template parameter must be a class derived from Layer class.
         * @tparam [... Args] This template parameter is optional. It is used to pass right arguments to the Layer's constructor.
         * @param [Args&& ...] args -> This parameter is optional. Variadic number of arguments for Layer's constructor.
         */

        template<typename L, typename ... Args>
        void PushLayerImmediately(Args&& ... args);

        /**
         * @fn PushOverlayImmediately
         * @brief Templated method which pushes an overlay onto the layer stack as soon as the method is called.
         * @tparam [L] This template parameter must be a class derived from Layer class.
         * @tparam [... Args] This template parameter is optional. It is used to pass right arguments to the Layer's constructor.
         * @param [Args&& ...] args -> This parameter is optional. Variadic number of arguments for Layer's constructor.
         */

        template<typename L, typename ... Args>
        void PushOverlayImmediately(Args&& ... args);

        /**
         * @fn PopLayerImmediately
         * @brief Templated method which pops a layer from the layer stack as soon as the method is called.
         * @tparam [L] This template parameter must be a class derived from Layer class.
         */

        template<typename L>
        void PopLayerImmediately();

        /**
         * @fn PopOverlayImmediately
         * @brief Templated method which pops an overlay from the layer stack as soon as the method is called.
         * @tparam [L] This template parameter must be a class derived from Layer class.
         */

        template<typename L>
        void PopOverlayImmediately();

        /**
         * @fn AttachLayers
         * @brief Method which pushes all layers and overlays from m_ForAddition stack to the main m_LayerStack.
         */

        void AttachLayers();

        /**
         * @fn DetachLayers
         * @brief Method which pops all layers and overlays which were added to m_ForRemoval stack from the main m_LayerStack.
         */

        void DetachLayers();

        /**
         * @fn GetSize
         * @brief Size getter.
         * @return [size_t] Current size of layer stack.
         */

        [[nodiscard]] inline size_t GetSize() const noexcept { return m_LayerStack.size(); }

        /**
         * @fn begin
         * @brief Begin iterator getter.
         * @return [std::vector<Layer*>::iterator] Begin iterator.
         */

        inline std::vector<Layer*>::iterator begin() noexcept { return m_LayerStack.begin(); }

        /**
         * @fn rbegin
         * @brief Reverse begin iterator getter.
         * @return [std::vector<Layer*>::reverse_iterator] Reverse begin iterator.
         */

        inline std::vector<Layer*>::reverse_iterator rbegin() noexcept { return m_LayerStack.rbegin(); }

        /**
         * @fn end
         * @brief End iterator getter.
         * @return [std::vector<Layer*>::iterator] End iterator.
         */

        inline std::vector<Layer*>::iterator end() noexcept { return m_LayerStack.end(); }

        /**
         * @fn rend
         * @brief Reverse end iterator getter.
         * @return [std::vector<Layer*>::reverse_iterator] Reverse end iterator.
         */

        inline std::vector<Layer*>::reverse_iterator rend() noexcept { return m_LayerStack.rend(); }

        /**
         * @fn operator[]
         * @brief Overloaded operator[].
         * @param [int] index -> unique identifier.
         * @return [Layer*] Pointer to layer at given index.
         */

        [[nodiscard]] inline Layer* operator[](size_t index);

        /**
         * @fn operator[]
         * @brief Overloaded operator[].
         * @param [int] index -> unique identifier.
         * @return [const Layer*] Pointer to const layer at given index.
         */

        [[nodiscard]] inline const Layer* operator[](size_t index) const;

    private:

        /**
         * @fn Init
         * @brief A method which attempts to initialize the LayerStack and returns success result (true/false).
         * @return [bool] true -> layer stack has been initialized successfully.
         *                false -> layer stack wasn't initialized.
         */

        [[nodiscard]] bool Init();

        /**
         * @fn Shutdown
         * @brief Destroys the application
         */

        void Shutdown();

    private:
        std::vector<Layer*> m_LayerStack; /**< Main layer stack */
        unsigned m_LayersAmount = 0; /**< Current number of layers in main layer stack */

    private:
        std::vector<Layer*> m_ForAddition; /**< Temp layer stack used for holding layers so that they will be pushed AFTER main loop tick */
        unsigned m_ForAdditionAmount = 0; /**< Current number of layers in temp layer stack */

        std::vector<unsigned> m_ForRemoval; /**< Temp layer stack used for holding type ids of layers that will be popped AFTER main loop tick */

    }; // END OF CLASS LayerStack

    template<typename L, typename ... Args>
    void LayerStack::PushLayer(Args&& ... args) {
        static_assert(std::is_base_of<Layer, L>::value, "Layer is not the base of L");
        m_ForAddition.emplace(m_ForAddition.begin() + m_ForAdditionAmount, new L{args ...});
        ++m_ForAdditionAmount;
        EventManager::Emit<LayerPushedEvent>();
    }

    template<typename L, typename ... Args>
    void LayerStack::PushOverlay(Args&& ... args) {
        static_assert(std::is_base_of<Layer, L>::value, "Layer is not the base of L");
        m_ForAddition.emplace_back(new L{args ...});
        EventManager::Emit<LayerPushedEvent>();
    }

    template<typename L>
    void LayerStack::PopLayer() {
        static_assert(std::is_base_of<Layer, L>::value, "Layer is not the base of L");
        m_ForRemoval.emplace_back(Utils::get_type_id<L>());
        EventManager::Emit<LayerPoppedEvent>();
    }

    template<typename L>
    void LayerStack::PopOverlay() {
        static_assert(std::is_base_of<Layer, L>::value, "Overlay is not the base of L");
        m_ForRemoval.emplace_back(Utils::get_type_id<L>());
        EventManager::Emit<LayerPoppedEvent>();
    }

    template<typename L, typename ... Args>
    void LayerStack::PushLayerImmediately(Args&& ... args) {
        CORE_LOG_INFO("[LayerStack] Pushing layer immediately...");

        static_assert(std::is_base_of<Layer, L>::value, "Layer is not the base of L");
        auto* layer = new L{args ...};
        layer->OnAttach();
        m_LayerStack.emplace(m_LayerStack.begin() + m_LayersAmount, layer);
        ++m_LayersAmount;

        CORE_LOG_INFO("[LayerStack] Pushing immediately was successful");
    }

    template<typename L, typename ... Args>
    void LayerStack::PushOverlayImmediately(Args&& ... args) {
        CORE_LOG_INFO("[LayerStack] Pushing overlay immediately...");

        static_assert(std::is_base_of<Layer, L>::value, "Overlay is not the base of L");
        auto* overlay = new L{args ...};
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
            if((*it)->GetType() == Utils::get_type_id<L>()) {
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
            if((*it)->GetType() == Utils::get_type_id<L>()) {
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

    inline const Layer* LayerStack::operator[](size_t index) const {
        assert(index < m_LayerStack.size());
        return m_LayerStack[index];
    }

} // END OF NAMESPACE Bald
