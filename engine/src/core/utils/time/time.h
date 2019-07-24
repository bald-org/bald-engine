//
// Created by grzegorz on 01.06.19.
//

#pragma once

#include "timer.h"
#include <string>

namespace Bald::Utils {

    /**
     * @class Time
     * @brief Simple class for time handling.
     */

    class Time {
    public:

        /**
         * @fn Time
         * @brief Constructs new Time object.
         * @param h [int] -> hours
         * @param m [int] -> minutes
         * @param s [int] -> seconds
         */

        Time(int h, int m, int s) :
                m_Hour(h), m_Min(m), m_Sec(s)
                { }

        /**
         * @fn GetCurrentTime
         * @return New Time object which holds current time.
         */

        [[nodiscard]] static Time GetCurrentTime() noexcept;

        /**
         * @fn Hours
         * @brief Getter for hours.
         * @return [int] Hours
         */

        [[nodiscard]] inline int Hours() const noexcept { return m_Hour; }

        /**
         * @fn Minutes
         * @brief Getter for minutes.
         * @return [int] Minutes
         */

        [[nodiscard]] inline int Minutes() const noexcept { return m_Min; }

        /**
         * @fn Seconds
         * @brief Getter for seconds.
         * @return [int] Seconds
         */

        [[nodiscard]] inline int Seconds() const noexcept { return m_Sec; }

        /**
         * @fn operator std::string()
         * @brief Converts time in to standard string.
         * @return [std::string] time in format 00:00:00.
         */

        explicit operator std::string() const;

    private:
        int m_Hour;
        int m_Min;
        int m_Sec;
    };

    Time Time::GetCurrentTime() noexcept {
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        auto time = std::localtime(&now_c);
        return Time(time->tm_hour, time->tm_min, time->tm_sec);
    }

    Time::operator std::string() const {
        std::string result;

        if (Hours() <= 9) result += "0";
        result += std::to_string(Hours()) + ":";

        if (Minutes() <= 9) result += "0";
        result += std::to_string(Minutes()) + ":";

        if (Seconds() <= 9) result += "0";
        result += std::to_string(Seconds());

        return result;
    }

}





