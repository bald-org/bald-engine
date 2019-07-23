//
// Created by grzegorz on 01.06.19.
//

#pragma once

#include "timer.h"
#include <string>

namespace Bald::Utils {

    class Time {
    public:
        Time(int h, int m, int s) :
                m_Hour(h), m_Min(m), m_Sec(s) { }

        [[nodiscard]] static Time GetCurrentTime();

        [[nodiscard]] inline int Hours() const noexcept { return m_Hour; }

        [[nodiscard]] inline int Minutes() const noexcept { return m_Min; }

        [[nodiscard]] inline int Seconds() const noexcept { return m_Sec; }

        explicit operator std::string() const;

    private:
        int m_Hour;
        int m_Min;
        int m_Sec;
    };

    Time Time::GetCurrentTime() {
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





