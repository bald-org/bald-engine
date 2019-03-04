//
// Created by Piotr Moszkowicz on 2019-02-11.
//

#include "events.h"
#include "pch.h"
#include <iostream>

using namespace Bald;
using namespace Events;

class Resizer {
public:
    void init() {
        hId = EventBus::subscribe(this, &Resizer::onWindowResizeEvent, HandlerType::SyncHandler);
    }

    void deinit() {
        EventBus::unsubscribe<WindowResizeEvent>(hId);
    }

    void onWindowResizeEvent(WindowResizeEvent* wre) {
        std::cout << wre->x << " " << wre->y << std::endl;
    }

    unsigned int hId;
};


int main() {
    auto r = new Resizer();
    r->init();

    EventBus::emit(new WindowResizeEvent(800, 600));
    std::cout << EventBus::isEventInQueue(Events::WindowResizeEvent::eventId) << std::endl;
    EventBus::runEventQueue();

    r->deinit();

    EventBus::emit(new WindowResizeEvent(400, 200));
    EventBus::runEventQueue();

    EventBus::cleanUp();
    std::cout << EventBus::isEventInQueue(Events::WindowResizeEvent::eventId) << std::endl;
    delete r;

    return 0;
}
