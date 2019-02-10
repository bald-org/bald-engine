//
// Created by Piotr Moszkowicz on 2019-02-10.
//

#pragma once
#include "pch.h"
#include "event.h"

// TODO: Move to utils
template<typename Base, typename T>
inline bool instanceof(const T*) {
    return std::is_base_of<Base, T>::value;
}

namespace Bald::Events {
    class EventManager {
    public:
        template <class T>
        static void bind(T* new_event);
        static void flush();
        static void run();
        template <class T>
        static void unbind(T);
    private:
        static std::vector<std::unique_ptr<Event>> m_events;
    };
}

template <class T>
void Bald::Events::EventManager::bind(T* new_event) {
    m_events.push_back(std::make_unique<T>(new_event));
}

void Bald::Events::EventManager::flush() {
    m_events.clear();
}

void Bald::Events::EventManager::run() {
    for (auto &event : m_events) {
        event->run();
    }
}

template <class T>
void Bald::Events::EventManager::unbind(T) {
    for (unsigned int i = 0; i < m_events.size(); i++) {
        if (instanceof<T>(m_events[i])) {
            m_events.erase(m_events.begin() + i);
            break;
        }
    }
}