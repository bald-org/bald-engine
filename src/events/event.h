//
// Created by grzegorz on 19.02.19.
//

#pragma once

#include <typeindex>

namespace Bald {

    class Event {
    protected:
        Event() = default;
    public:
        virtual ~Event() = default;

    public:
        virtual void EmitConnectedEvents() const = 0;
        [[nodiscard]] virtual std::type_index Type() const = 0;

    }; //END OF CLASS Event

} //END OF NAMESPACE Bald
