//
// Created by grzegorz on 10.05.19.
//

#include "core/debug/logger/log_manager.hpp"
#include "events/event_bus.hpp"
#include "events/key_events.hpp"
#include "input/input_manager.hpp"
#include "src/core/models/timer.hpp"

#include <iostream>

#define N 10000
#define E 1000

void sub(const Bald::Events::Event &, int &i) { i++; }

struct A {
  void met(const Bald::Events::Event &) const { i++; };
  mutable int i = 0;
};

int main() {

  using namespace Bald;
  using namespace Bald::Events;
  using namespace Debug;
  LogManager::Init();

  int x = 0;
  const A a;
  EventBus::Subscribe<KeyEvent>(sub, std::reference_wrapper(x));
  EventBus::Subscribe<KeyEvent>(&A::met, a);
  EventBus::Subscribe<KeyEvent>(&A::met, &a);

  Models::Timer timer;
  timer.Start();

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < E; j++) {
      EventBus::Emit<KeyEvent>(static_cast<unsigned>(BALD_KEY_0));
    }
  }

  timer.Stop();

  std::cout << std::to_string(N) << " events -> " << std::to_string(2 * E)
            << " times took: " << timer.ElapsedSeconds() << " s\n";
}
