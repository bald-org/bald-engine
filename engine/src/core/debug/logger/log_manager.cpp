//
// Created by grzegorz on 15.12.18.
//

#include "log_manager.h"

namespace Bald::Debug {

    std::shared_ptr<Logger> LogManager::m_CoreLogger;
    std::shared_ptr<Logger> LogManager::m_GameLogger;

    void LogManager::Init() {
        m_CoreLogger = std::make_shared<Logger>();
        m_GameLogger = std::make_shared<Logger>();

        m_CoreLogger->SetName("BALD");
        m_GameLogger->SetName("App");
    }

}