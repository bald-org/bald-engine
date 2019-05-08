//
// Created by grzegorz on 19.02.19.
//

#include "event_manager.h"

namespace Bald {

    std::deque<Bald::KeyEvent*> EventManager::m_KeyEventQueue;
    std::deque<Bald::KeyPressedEvent*> EventManager::m_KeyPressedEventQueue;
    std::deque<Bald::KeyTypedEvent*> EventManager::m_KeyTypedEventQueue;
    std::deque<Bald::KeyReleasedEvent*> EventManager::m_KeyReleasedEventQueue;

    std::deque<Bald::MouseEvent*> EventManager::m_MouseEventQueue;
    std::deque<Bald::MouseButtonTypedEvent*> EventManager::m_MouseButtonTypedEventQueue;
    std::deque<Bald::MouseButtonPressedEvent*> EventManager::m_MouseButtonPressedEventQueue;
    std::deque<Bald::MouseMovedEvent*> EventManager::m_MouseMovedEventQueue;
    std::deque<Bald::MouseScrolledEvent*> EventManager::m_MouseScrolledEventQueue;

    std::deque<Bald::WindowEvent*> EventManager::m_WindowEventQueue;
    std::deque<Bald::WindowResizedEvent*> EventManager::m_WindowResizedEventQueue;
    std::deque<Bald::WindowClosedEvent*> EventManager::m_WindowClosedEventQueue;

    void EventManager::Call() noexcept {

    }

    void EventManager::Flush(int n) noexcept {
        std::cout << n << "\n";
    }

    void EventManager::CleanUp() noexcept {

    }

} //END OF NAMESPACE Bald
