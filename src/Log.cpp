//
// Created by grzegorz on 15.12.18.
//

#include "Log.h"

namespace Bald{
    std::shared_ptr<spdlog::logger> Log::m_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::m_GameLogger;

    void Log::Init() {
        m_CoreLogger = spdlog::stdout_color_mt("BALD");
        m_GameLogger = spdlog::stdout_color_mt("App");
        spdlog::set_pattern("%^[%T] %n: %v%$"); /** < sets pattern %^ [start color range], %T [time HH::MM::SS], %n [logger name], %v [text to log] %$[ends color range]*/
    }

}