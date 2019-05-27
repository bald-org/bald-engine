//
// Created by blinku on 07.05.19.
//

#include "bald.h"

class EventsExample : public Bald::Application {
GENERATE_BODY(DERIVED)
public:
    EventsExample() = default;
    ~EventsExample() override = default;
};

Bald::Application* Bald::Application::Create() noexcept {
    return new EventsExample();
}
