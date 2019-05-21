//
// Created by grzegorz on 10.05.19.
//

#include <event_manager.h>
#include <event.h>
#include <key_events.h>
#include <Log.h>
#include <chrono>
#include <iostream>
#include <input_manager.h>
#include <events/window_events.h>

#define N 10000
#define E 1000

void sub(const Bald::Event&, int& i) {
    i++;
}

int main() {
    using namespace std::chrono;
    Bald::Log::Init();
    Bald::EventManager em;
    int x = 0;
    em.Subscribe<Bald::KeyEvent>(Bald::HandleType::SYNC, sub, std::reference_wrapper(x));
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < E; j++) {
            Bald::EventManager::Emit<Bald::KeyEvent>(static_cast<unsigned >(GLFW_KEY_0));
        }
        em.Flush();
        Bald::EventManager::ClearEventQueue();
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    std::cout << std::to_string(N) << " events -> " << std::to_string(E) << " times took: "
              << duration_cast<duration<double>>(t2 - t1).count() << " s\n\n";
}
