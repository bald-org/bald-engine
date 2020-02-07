//
// Created by blinku on 22.05.19.
//

#include "timer.h"

namespace Bald::Models {

    void Timer::Start() noexcept {
        m_StartTime = std::chrono::system_clock::now();
        m_IsRunning = true;
    }

    void Timer::Stop() noexcept {
        m_EndTime = std::chrono::system_clock::now();
        m_IsRunning = false;
    }

    void Timer::Reset() noexcept {
        m_StartTime = std::chrono::system_clock::now();
        m_IsRunning = true;
    }

    float Timer::ElapsedSeconds() const noexcept {
        return static_cast<float>(ElapsedMilliseconds()) / 1000.0f;
    }

    uint32_t Timer::ElapsedMilliseconds() const noexcept {
        return ElapsedMicroseconds() / 1000;
    }

    uint32_t Timer::ElapsedMicroseconds() const noexcept {
        std::chrono::time_point<std::chrono::system_clock> endTime;

        m_IsRunning ? endTime = std::chrono::system_clock::now() : endTime = m_EndTime;

        return static_cast<uint32_t>(std::chrono::duration_cast<std::chrono::microseconds>(endTime - m_StartTime).count());
    }

    bool Timer::IsRunning() const noexcept {
        return m_IsRunning;
    }

} // END OF NAMESPACE Bald::Models