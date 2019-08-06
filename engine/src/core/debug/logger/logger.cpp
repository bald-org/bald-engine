//
// Created by grzegorz on 01.06.19.
//

#include <cstdio>

#include "logger.h"
#include "core/utils/time/time.h"

namespace Bald::Debug {

    void Logger::Red() noexcept {
        printf("\033[1;31m");
    }

    void Logger::Yellow() noexcept {
        printf("\033[1;33m");
    }

    void Logger::Green() noexcept {
        printf("\033[1;32m");
    }

    void Logger::Reset() noexcept {
        printf("\033[0m");
    }

    void Logger::trace(const std::string& mess) const noexcept {
        Reset();
        Print(mess);
    }

    void Logger::info(const std::string& mess) const noexcept {
        Green();
        Print(mess);
    }

    void Logger::warn(const std::string& mess) const noexcept {
        Yellow();
        Print(mess);
    }

    void Logger::error(const std::string& mess) const noexcept {
        Red();
        Print(mess);
    }

    void Logger::Print(const std::string& mess) const noexcept {
        const std::string time = static_cast<std::string>(Utils::Time::GetCurrentTime());
        printf("[%s] ", time.c_str());
        printf("%s: %s\n", m_Name.c_str(), mess.c_str());
        Reset();
    }

    void Logger::SetName(const std::string& name) {
        m_Name = name;
    }

}