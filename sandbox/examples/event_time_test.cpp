//
// Created by grzegorz on 10.05.19.
//

#include "events/event_manager.h"
#include "events/key_events.h"
#include "events/window_events.h"
#include "input/input_manager.h"
#include "utils/timer.h"
#include "core/debug/logger.h"

#include <iostream>

#define N 10000
#define E 1000

void sub(const Bald::Event&, int& i) {
    i++;
}

int main() {

    using namespace Bald;

    Logger::Init();

    EventManager em;
    int x = 0;
    em.Subscribe<KeyEvent>(HandleType::SYNC, sub, std::reference_wrapper(x));

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

    std::cout << std::to_string(N) << " events -> " << std::to_string(E) << " times took: " << timer.ElapsedSeconds()
              << " s\n";
}
