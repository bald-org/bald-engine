//
// Created by grzegorz on 07.05.19.
//

#include "key_events.h"

namespace Bald {
    std::vector<FunctionHandler < KeyEvent>*> KeyEvent::callbacks;
    std::vector<AsyncFunctionHandler < KeyEvent>*> KeyEvent::async_callbacks;

    std::vector<FunctionHandler < KeyPressedEvent>*> KeyPressedEvent::callbacks;
    std::vector<AsyncFunctionHandler < KeyPressedEvent>*> KeyPressedEvent::async_callbacks;

    std::vector<FunctionHandler < KeyReleasedEvent>*> KeyReleasedEvent::callbacks;
    std::vector<AsyncFunctionHandler < KeyReleasedEvent>*> KeyReleasedEvent::async_callbacks;

    std::vector<FunctionHandler < KeyTypedEvent>*> KeyTypedEvent::callbacks;
    std::vector<AsyncFunctionHandler < KeyTypedEvent>*> KeyTypedEvent::async_callbacks;
}