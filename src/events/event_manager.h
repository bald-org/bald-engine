//
// Created by Piotr Moszkowicz on 2019-02-10.
//

#pragma once
#include "pch.h"
#include "event.h"

// TODO: Move to utils or w/e
template<typename T, typename K>
[[nodiscard]] constexpr inline bool isType(const K &k) noexcept {
    return typeid(T) == typeid(k);
}

namespace Bald::Events {
    class EventManager {
    public:
        template <class T>
        constexpr static void bind() noexcept;
        static void flush() noexcept;
        static void run() noexcept;
        template <class T>
        constexpr static void unbind() noexcept;
    private:
        static std::vector<std::unique_ptr<Event>> m_events;
    };

    std::vector<std::unique_ptr<Event>> EventManager::m_events;

    template <class T>
    constexpr void EventManager::bind() noexcept {
        m_events.push_back(std::make_unique<T>());
    }

    void EventManager::flush() noexcept {
        m_events.clear();
    }

    void EventManager::run() noexcept {
        for (auto &event : m_events) {
            event->run();
        }
    }

    template <typename T>
    constexpr void EventManager::unbind() noexcept {
        for (unsigned int i = 0; i < m_events.size(); i++) {
            if (isType<T>(*m_events[i])) {
                m_events.erase(m_events.begin() + i);
                break;
            }
        }
    }
}