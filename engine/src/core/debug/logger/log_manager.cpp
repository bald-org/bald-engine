//
// Created by grzegorz on 15.12.18.
//

#include "log_manager.h"

namespace Bald::Debug {

    std::shared_ptr<Logger> LogManager::m_CoreLogger;
    std::shared_ptr<Logger> LogManager::m_GameLogger;

    void LogManager::Init() {

        /** < sets pattern %^ [start color range], %T [time HH::MM::SS], %n [logger name], %v [text to log] %$[ends color range]*/
        m_CoreLogger = std::make_shared<Logger>();
        m_GameLogger = std::make_shared<Logger>();

        m_CoreLogger->setName("BALD");

        m_GameLogger->setName("App");


    }

} // END OF NAMESPACE Bald