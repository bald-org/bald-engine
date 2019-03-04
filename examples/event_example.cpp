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
        EventBus::subscribe(this, &Resizer::onWindowResizeEvent, HandlerType::SyncHandler);
    }

    void deinit() {
        EventBus::unsubscribe(this, &Resizer::onWindowResizeEvent);
    }

    void onWindowResizeEvent(WindowResizeEvent* wre) {
        std::cout << wre->x << " " << wre->y << std::endl;
    }
};


int main() {
    auto r = new Resizer();
    r->init();

    EventBus::emit(new WindowResizeEvent(800, 600));

    r->deinit();

    EventBus::emit(new WindowResizeEvent(400, 200));

    EventBus::flush();
    delete r;

    return 0;
}
