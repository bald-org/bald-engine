//
// Created by grzegorz on 01.06.19.
//

#include <cstdio>

#include "logger.h"
#include "core/utils/time/time.h"

namespace Bald::Debug {

    void red () {
        printf("\033[1;31m");
    }

    void yellow() {
        printf("\033[1;33m");
    }

    void green() {
        printf("\033[1;32m");
    }

    void reset () {
        printf("\033[0m");
    }

    void Logger::trace(const std::string& mess) const noexcept {
        reset();
        print(mess);
    }

    void Logger::info(const std::string& mess) const noexcept {
        green();
        print(mess);
    }

    void Logger::warn(const std::string& mess) const noexcept {
        yellow();
        print(mess);
    }

    void Logger::error(const std::string& mess) const noexcept {
        red();
        print(mess);
    }

    void Logger::print(const std::string& mess) const noexcept {
        std::string time = static_cast<std::string>(Utils::Time::GetCurrentTime());
        printf("[%s] ", time.c_str());
        printf("%s: %s\n", m_Name.c_str(), mess.c_str()); //TODO: Log time
        reset();
    }

    void Logger::setName(const std::string& name) {
        m_Name = name;
    }

}