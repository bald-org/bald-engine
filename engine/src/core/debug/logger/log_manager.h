//
// Created by grzegorz on 15.12.18.
//

#pragma once

#include "logger.h"
#include <memory>

namespace Bald::Debug {

/**
 * @class Logger
 * @brief Implementation of basic logging system.
 * */

    class LogManager {
    public:

        LogManager() = delete;

        /**
         * @fn Init
         * @brief Initialize Core Logger and User Logger.
         */

        static void Init();

        /**
         * @fn GetCoreLogger
         * @brief Use to get access to Core Logger.
         * @return Reference to Core Logger.
         */

        [[nodiscard]] constexpr inline static std::shared_ptr<Logger> &GetCoreLogger() noexcept;

        /**
         * @fn GetGameLogger
         * @brief Use to get access to Game Logger.
         * @return Reference to Game Logger.
         */

        [[nodiscard]] constexpr inline static std::shared_ptr<Logger> &GetGameLogger() noexcept;

    private:
        static std::shared_ptr<Logger> m_CoreLogger;  /**< Pointer to core logger. */
        static std::shared_ptr<Logger> m_GameLogger;  /**< Pointer to user logger. */
    };


    constexpr std::shared_ptr<Logger> &LogManager::GetCoreLogger() noexcept { return m_CoreLogger; }

    constexpr std::shared_ptr<Logger> &LogManager::GetGameLogger() noexcept { return m_GameLogger; }


#ifdef DEBUG
#define CORE_LOG_TRACE(...) ::Bald::Debug::LogManager::GetCoreLogger()->trace(__VA_ARGS__)   /**< Print info in Core Logger. */
#define CORE_LOG_INFO(...)  ::Bald::Debug::LogManager::GetCoreLogger()->info(__VA_ARGS__)    /**< Print info in Core Logger. */
#define CORE_LOG_WARN(...)  ::Bald::Debug::LogManager::GetCoreLogger()->warn(__VA_ARGS__)    /**< Print warning in Core Logger. */
#define CORE_LOG_ERROR(...) ::Bald::Debug::LogManager::GetCoreLogger()->error(__VA_ARGS__)   /**< Print error in Core Logger. */

#define GAME_LOG_TRACE(...) ::Bald::Debug::LogManager::GetGameLogger()->trace(__VA_ARGS__)   /**< Print info in Game Logger. */
#define GAME_LOG_INFO(...)  ::Bald::Debug::Logger::GetGameLogger()->info(__VA_ARGS__)    /**< Print info in Game Logger. */
#define GAME_LOG_WARN(...)  ::Bald::Debug::Logger::GetGameLogger()->warn(__VA_ARGS__)    /**< Print warning in Game Logger. */
#define GAME_LOG_ERROR(...) ::Bald::Debug::Logger::GetGameLogger()->error(__VA_ARGS__)   /**< Print error in Game Logger. */

#else
#define CORE_LOG_TRACE(...) /**< Empty instruction. */
#define CORE_LOG_INFO(...)  /**< Empty instruction. */
#define CORE_LOG_WARN(...)  /**< Empty instruction. */
#define CORE_LOG_ERROR(...) /**< Empty instruction. */

#define GAME_LOG_TRACE(...) /**< Empty instruction. */
#define GAME_LOG_INFO(...)  /**< Empty instruction. */
#define GAME_LOG_WARN(...)  /**< Empty instruction. */
#define GAME_LOG_ERROR(...) /**< Empty instruction. */
#endif
} // END OF NAMESPACE Bald
