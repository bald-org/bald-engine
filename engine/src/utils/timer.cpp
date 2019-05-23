//
// Created by blinku on 22.05.19.
//

#include "timer.h"

namespace Bald::Utils {

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

    double Timer::ElapsedSeconds() const noexcept {
        return static_cast<double>(ElapsedMilliseconds()) / 1000.0;
    }

    long Timer::ElapsedMilliseconds() const noexcept {
        std::chrono::time_point<std::chrono::system_clock> endTime;

        m_IsRunning ? endTime = std::chrono::system_clock::now() : endTime = m_EndTime;

        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
    }

    bool Timer::IsRunning() const noexcept {
        return m_IsRunning;
    }

} // END OF NAMESPACE Bald::Utils