//
// Created by blinku on 07.05.19.
//

#include "bald.h"

class Sandbox : public Bald::Application {
public:
    Sandbox() = default;
    ~Sandbox() override = default;
};

Bald::Application* Bald::Application::Create() noexcept {
    return new Sandbox();
}