//
// Created by grzegorz on 01.06.19.
//

#include <cstdio>

#include "logger.h"
#include "core/utils/time/time.h"

namespace Bald::Debug {

    void Logger::red() noexcept {
        printf("\033[1;31m");
    }

    void Logger::yellow() noexcept {
        printf("\033[1;33m");
    }

    void Logger::green() noexcept {
        printf("\033[1;32m");
    }

    void Logger::reset() noexcept {
        printf("\033[0m");
    }

    void Logger::trace(const std::string& mess) const noexcept {
        reset();
        Print(mess);
    }

    void Logger::info(const std::string& mess) const noexcept {
        green();
        Print(mess);
    }

    void Logger::warn(const std::string& mess) const noexcept {
        yellow();
        Print(mess);
    }

    void Logger::error(const std::string& mess) const noexcept {
        red();
        Print(mess);
    }

    void Logger::Print(const std::string& mess) const noexcept {
        const std::string time = static_cast<std::string>(Utils::Time::GetCurrentTime());
        printf("[%s] ", time.c_str());
        printf("%s: %s\n", m_Name.c_str(), mess.c_str());
        reset();
    }

    void Logger::SetName(const std::string& name) {
        m_Name = name;
    }

}