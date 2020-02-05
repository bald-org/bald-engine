//
// Created by blinku on 18.12.2019.
//

#pragma once

#include "src/core/models/timer.h"

namespace Bald::Controllers {

    /**
     * @class TimeController
     * @brief This class is responsible for handling a Timer.
     */

    class TimeController {
    public:

        /**
         * @fn TimeController
         * @brief Starts the timer.
         */

        inline TimeController();

        /**
         * @fn ~TimeController
         * @brief Starts the timer.
         */

        inline ~TimeController();

        /**
         * @fn GetDeltaTimeInSeconds
         * @brief Delta time getter.
         * @return float Delta time.
         */

        [[nodiscard]] inline float GetDeltaTimeInSeconds() noexcept;

        /**
         * @fn GetDeltaTimeInMilliseconds
         * @brief Delta time getter.
         * @return float Delta time.
         */

        [[nodiscard]] inline float GetDeltaTimeInMilliseconds() noexcept;

        /**
         * @fn GetDeltaTimeInMicroseconds
         * @brief Delta time getter.
         * @return float Delta time.
         */

        [[nodiscard]] inline float GetDeltaTimeInMicroseconds() noexcept;

    private:

        /**
         * @fn StartTimer
         * @brief Starts the timer.
         */

        inline void StartTimer() noexcept;

        /**
         * @fn StopTimer
         * @brief Stops the timer.
         */

        inline void StopTimer() noexcept;

        /**
         * @fn ResetTimer
         * @brief Resets the timer.
         */

        inline void ResetTimer() noexcept;

        /**
         * @fn IsTimerRunning
         * @brief Checks whether or not the timer is currently running.
         * @return bool true -> timer is currently running.
         *              false -> timer is currently not running.
         */

        [[nodiscard]] inline bool IsTimerRunning() const noexcept;

        /**
         * @fn GetElapsedMicroseconds
         * @brief Helper method that retrieves elapsed time in microseconds.
         * @return uint32_t Elapsed microseconds since start of the timer or last reset.
         */

        [[nodiscard]] inline uint32_t GetElapsedMicroseconds() noexcept;

    private:
        Models::Timer m_Timer; /**< Timer managed by this controller. */
    }; // END OF CLASS TimeController

    inline TimeController::TimeController() {
        StartTimer();
    }

    inline TimeController::~TimeController() {
        StopTimer();
    }

    inline float TimeController::GetDeltaTimeInSeconds() noexcept {
        return GetDeltaTimeInMilliseconds() / 1000.0f;
    }

    inline float TimeController::GetDeltaTimeInMilliseconds() noexcept {
        return GetDeltaTimeInMicroseconds() / 1000.0f;
    }

    inline float TimeController::GetDeltaTimeInMicroseconds() noexcept {
        auto deltaTime = static_cast<float>(GetElapsedMicroseconds());
        ResetTimer();
        return deltaTime;
    }

    inline void TimeController::StartTimer() noexcept {
        m_Timer.Start();
    }

    inline void TimeController::StopTimer() noexcept {
        m_Timer.Stop();
    }

    inline void TimeController::ResetTimer() noexcept {
        m_Timer.Reset();
    }

    inline bool TimeController::IsTimerRunning() const noexcept {
        return m_Timer.IsRunning();
    }

    inline uint32_t TimeController::GetElapsedMicroseconds() noexcept {
        return m_Timer.ElapsedMicroseconds();
    }

} // END OF NAMESPACE Bald::Controllers



