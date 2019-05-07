//
// Created by blinku on 07.05.19.
//

#include "bald.h"

class InputExample : public Bald::Application {
public:
    InputExample() = default;
    ~InputExample() override = default;
};

Bald::Application* Bald::Application::Create() noexcept {
    return new InputExample();
}