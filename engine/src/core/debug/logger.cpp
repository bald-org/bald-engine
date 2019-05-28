//
// Created by grzegorz on 15.12.18.
//

#include "logger.h"

namespace Bald {

    std::shared_ptr<spdlog::logger> Logger::m_CoreLogger;
    std::shared_ptr<spdlog::logger> Logger::m_GameLogger;

    void Logger::Init() {

        spdlog::set_pattern("%^[%T] %n: %v%$"); /** < sets pattern %^ [start color range], %T [time HH::MM::SS], %n [logger name], %v [text to log] %$[ends color range]*/

        m_CoreLogger = spdlog::stdout_color_mt("BALD");
        m_CoreLogger->set_level(spdlog::level::trace);

        m_GameLogger = spdlog::stdout_color_mt("APP");
        m_GameLogger->set_level(spdlog::level::trace);

    }

} // END OF NAMESPACE Bald