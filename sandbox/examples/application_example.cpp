//
// Created by blinku on 07.05.19.
//

#include "bald.h"

class ApplicationExample : public Bald::Application {
GENERATE_BODY(DERIVED)
public:
    ApplicationExample() = default;
    ~ApplicationExample() override = default;
};

Bald::Application* Bald::Application::Create() noexcept {
    return new ApplicationExample();
}
