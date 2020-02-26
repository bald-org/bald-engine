//
// Created by grzegorz on 22.07.19.
//
#include "core/pch.hpp"
#include "gtest/gtest.h"

#include "events/event_bus.hpp"
#include "events/key_events.hpp"
#include "input_manager.hpp"

struct A {
    A() : m_id(count++) {}

    A(const A&) : m_id(count++) {}

    A(A&&) noexcept : m_id(count++) {}

    bool operator==(const A& other) const {
        return other.m_id == m_id;
    }

    void IsTheSame(const Bald::Events::Event&, bool& result, const A& other) const {
        result = operator==(other);
    }

    void onKeyEvent(const Bald::Events::KeyEvent& e) const {
        CORE_LOG_TRACE("Key event" + std::to_string(e.GetKeyCode()));
    }

    static int count;
    int m_id;
};

int A::count = 0;

TEST(Event_system, is_method_called_on_correct_object) {
    using namespace Bald::Events;
    bool result = false;
    const A a;

    EventBus::Subscribe<KeyEvent>(&A::IsTheSame, &a, std::reference_wrapper(result),
                                  std::reference_wrapper(a));

    EventBus::Subscribe<KeyEvent>(&A::IsTheSame, std::reference_wrapper(a), std::reference_wrapper(result),
                                  std::reference_wrapper(a));

    EventBus::Subscribe<KeyEvent>(
        []([[maybe_unused]] const KeyEvent& e, [[maybe_unused]] bool& result, [[maybe_unused]] const A& other) {
        }, std::reference_wrapper(result), std::reference_wrapper(a));

    EventBus::Emit<KeyEvent>(KeyEvent{static_cast<unsigned >(BALD_KEY_0)});

    EXPECT_TRUE(result);
}
