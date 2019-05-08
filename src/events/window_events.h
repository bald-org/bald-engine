//
// Created by blinku on 02.04.19.
//

#pragma once

#include <utility>
#include "event.h"

namespace Bald {

    /**
     * @class WindowEvent
     * @brief Specific event implementation which also provides an API for even more specific window events
     */

    struct WindowEvent : public Event {
        /**
        * @fn                   EmitConnectedEvents
        * @brief                This method is left blank because KeyEvent does not emit any associated events
        */

        void EmitConnectedEvents() const override {}

        /**
        * @fn                           Type
        * @brief                        This method returns type index of this specific class. This is used for polymorphism
        * @return [std::type_index]     Type index
        */

        static std::vector<FunctionHandler < WindowEvent>*> callbacks;
        static std::vector<AsyncFunctionHandler < WindowEvent>*> async_callbacks;
    }; // END OF CLASS WindowEvent

    /**
     * @class WindowEvent
     * @brief Specific event implementation for window resized type event
     */

    struct WindowResizedEvent : public WindowEvent {

        /**
        * @fn                   WindowResizedEvent
        * @brief                Constructor
        * @param [int]          width  -> Window's width
        * @param [int]          height -> Window's height
        */

        explicit WindowResizedEvent(int windowWidth, int windowHeight)
            : m_WindowSize{windowWidth, windowHeight} {}


        /**
        * @fn                   EmitConnectedEvents
        * @brief                This method is emits additional WindowEvent
        */

        void EmitConnectedEvents() const override {  }

        /**
        * @fn                   GetWidth
        * @brief                Width getter
        * @return [int]         Window's width during event emission
        */

        [[nodiscard]] inline int GetWidth() const noexcept { return m_WindowSize.first; }

        /**
        * @fn                   GetHeight
        * @brief                Height getter
        * @return [int]         Window's height during event emission
        */

        [[nodiscard]] inline int GetHeight() const noexcept { return m_WindowSize.second; }

        /**
        * @fn                               GetSize
        * @brief                            Returns window's width and height as pair
        * @return [std::pair<int,int>]      width, height coordinates as pair
        */

        [[nodiscard]] inline std::pair<int, int> GetSize() const noexcept { return m_WindowSize; }

        const std::pair<int, int> m_WindowSize; /* < Window's width, height */
        static std::vector<FunctionHandler < WindowResizedEvent>*> callbacks;
        static std::vector<AsyncFunctionHandler < WindowResizedEvent>*> async_callbacks;
    }; // END OF CLASS WindowResizedEvent

    /**
     * @class WindowEvent
     * @brief Specific event implementation for window closed type event
     */

    struct WindowClosedEvent : public WindowEvent {

        /**
        * @fn                   EmitConnectedEvents
        * @brief                This method is emits additional WindowEvent
        */

        void EmitConnectedEvents() const override {  }

        /**
        * @fn                           Type
        * @brief                        This method returns type index of this specific class. This is used for polymorphism
        * @return [std::type_index]     Type index
        */

        static std::vector<FunctionHandler < WindowClosedEvent>*> callbacks;
        static std::vector<AsyncFunctionHandler < WindowClosedEvent>*> async_callbacks;
    }; // END OF CLASS WindowClosedEvent

} // END OF NAMESPACE Bald
