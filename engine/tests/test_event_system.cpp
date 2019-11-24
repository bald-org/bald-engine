//
// Created by grzegorz on 22.07.19.
//
#include "core/pch.h"
#include "gtest/gtest.h"

#include "event_manager.h"
#include "events/key_events.h"
#include "input_manager.h"

struct A {
    A(): m_id(count++) {}
    A(const A&): m_id(count++) {}
    A(A&&) noexcept : m_id(count++) {}
    bool operator==(const A& other) const {
        return other.m_id == m_id;
    }
    void IsTheSame(const Bald::Event&, bool& result, const A& other) const {
        result = operator==(other);
    }

    static int count;
    int m_id;
};

int A::count = 0;

TEST(Event_system, is_method_called_on_correct_object) {
    using namespace Bald;
    EventManager em;
    bool result = false;
    A a;
    em.Subscribe<KeyEvent>(HandleType::SYNC, &A::IsTheSame, a, std::reference_wrapper(result), std::reference_wrapper(a));
    EventManager::Emit<KeyEvent>(static_cast<unsigned >(BALD_KEY_0));
    em.Flush();
    EventManager::ClearEventQueue();
    EXPECT_TRUE(result);
}
