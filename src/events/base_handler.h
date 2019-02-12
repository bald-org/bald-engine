//
// Created by Piotr Moszkowicz on 2019-02-12.
//

#pragma once
#include "event.h"

namespace Bald::Events {
    class BaseHandler {
    public:
        void exec(Event* e) {
            call(e);
        }
        virtual bool operator ==(const BaseHandler* &h) const noexcept = 0;
    private:
        virtual void call(Event* e) = 0;
    };
}

