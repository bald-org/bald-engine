//
// Created by blinku on 18.12.2019.
//

#pragma once

#include "utils/time/timer.h"

namespace Bald::Controllers {

    class TimeController {
    public:

        inline TimeController();

        [[nodiscard]] inline double GetDeltaTimeInSeconds() noexcept;

        [[nodiscard]] inline float GetDeltaTimeInMilliseconds() noexcept;

        [[nodiscard]] inline float GetDeltaTimeInMicroseconds() noexcept;

    private:
        inline void StartTimer();

        inline void StopTimer();

        inline void ResetTimer() noexcept;

        [[nodiscard]] inline bool IsTimerRunning() const noexcept;

        [[nodiscard]] inline long GetElapsedMicroseconds() noexcept;

    private:
        Utils::Timer m_Timer;
    }; // END OF CLASS TimeController

    TimeController::TimeController() {
        StartTimer();
    }

    inline double TimeController::GetDeltaTimeInSeconds() noexcept {
        return static_cast<double>(GetDeltaTimeInMilliseconds()) / 1000.0;
    }

    float TimeController::GetDeltaTimeInMilliseconds() noexcept {
        return GetDeltaTimeInMicroseconds() / 1000.0f;
    }

    float TimeController::GetDeltaTimeInMicroseconds() noexcept {
        StopTimer();
        auto deltaTime = static_cast<float>(GetElapsedMicroseconds());
        ResetTimer();
        return deltaTime;
    }

    inline void TimeController::StartTimer() {
        m_Timer.Start();
    }

    inline void TimeController::StopTimer() {
        m_Timer.Stop();
    }

    inline void TimeController::ResetTimer() noexcept {
        m_Timer.Reset();
    }

    inline bool TimeController::IsTimerRunning() const noexcept {
        return m_Timer.IsRunning();
    }

    inline long TimeController::GetElapsedMicroseconds() noexcept {
        return m_Timer.ElapsedMicroseconds();
    }

} // END OF NAMESPACE Bald::Controllers



