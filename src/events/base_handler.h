//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once
#include "event.h"

namespace Bald::Events {
    class BaseHandler {
    public:
        virtual ~BaseHandler() = default;
        void exec(Event* e) noexcept {
            call(e);
        }
    protected:
        virtual void call(Event* e) const noexcept = 0;
    };
}
