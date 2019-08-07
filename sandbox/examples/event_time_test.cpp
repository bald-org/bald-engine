//
// Created by grzegorz on 10.05.19.
//

#include "events/event_manager.h"
#include "events/key_events.h"
#include "events/window_events.h"
#include "input/input_manager.h"
#include "core/utils/time/timer.h"
#include "core/debug/logger/log_manager.h"

#include <iostream>

#define N 10000
#define E 1000

void sub(const Bald::Event&, int& i) {
    i++;
}

struct A {
    void met(const Bald::Event&) { i++; };
    int i = 0;
};

int main() {

    using namespace Bald;
    using namespace Debug;
    LogManager::Init();

    EventManager em;
    int x = 0;
    A a;
    em.Subscribe<KeyEvent>(HandleType::SYNC, sub, std::reference_wrapper(x));
    em.Subscribe<KeyEvent>(HandleType::SYNC, &A::met, &a);

    Utils::Timer timer;
    timer.Start();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < E; j++) {
            EventManager::Emit<KeyEvent>(static_cast<unsigned >(GLFW_KEY_0));
        }
        em.Flush();
        EventManager::ClearEventQueue();
    }

    timer.Stop();

    std::cout << std::to_string(N) << " events -> " << std::to_string(2 * E) << " times took: " << timer.ElapsedSeconds()
              << " s\n";
}
