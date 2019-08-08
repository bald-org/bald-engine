//
// Created by blinku on 22.05.19.
//

#pragma once

#include <chrono>

namespace Bald::Utils {

    /**
     * @class Timer
     * @brief Simple timer class.
     */

    class Timer {
    public:

        /**
         * @fn Timer
         * @brief Timer constructor.
         */

        constexpr Timer() : m_IsRunning(false) {}

        /**
         * @fn ~Timer
         * @brief Timer destructor.
         */

        ~Timer() = default;

        /**
         * @fn Start
         * @brief A method which starts timer.
         */

        void Start() noexcept;

        /**
         * @fn Stop
         * @brief A method which stops timer.
         */

        void Stop() noexcept;

        /**
         * @fn Reset
         * @brief A method which resets timer.
         */

        void Reset() noexcept;

        /**
         * @fn ElapsedSeconds
         * @brief A method which returns the amount of elapsed seconds since the start of the timer.
         * @return [double] Amount of seconds as double.
         */

        [[nodiscard]] double ElapsedSeconds() const noexcept;

        /**
         * @fn ElapsedMilliseconds
         * @brief A method which returns the amount of elapsed milliseconds since the start of the timer.
         * @return [double] Amount of milliseconds as long.
         */

        [[nodiscard]] long ElapsedMilliseconds() const noexcept;

        /**
         * @fn IsRunning
         * @brief A method which returns the state of the timer.
         * @return [bool] true -> timer is currently running
         *                false -> timer isn't currently running
         */

        [[nodiscard]] bool IsRunning() const noexcept;

    private:
        std::chrono::time_point<std::chrono::system_clock> m_StartTime; /**< Start time of the timer */
        std::chrono::time_point<std::chrono::system_clock> m_EndTime; /**< Stop time of the timer */
        bool m_IsRunning; /**< State of the timer */

    }; // END OF CLASS Timer

} // END OF NAMESPACE Bald::Utils
