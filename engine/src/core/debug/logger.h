//
// Created by grzegorz on 15.12.18.
//

#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Bald {

/**
 * @class Logger
 * @brief implementation of basic logging system
 * */

    class Logger {
    public:

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

        [[nodiscard]] constexpr inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() noexcept;

        /**
         * @fn GetGameLogger
         * @brief Use to get access to Game Logger.
         * @return Reference to Game Logger.
         */

        [[nodiscard]] constexpr inline static std::shared_ptr<spdlog::logger> &GetGameLogger() noexcept;

    private:
        static std::shared_ptr<spdlog::logger> m_CoreLogger;  /**< Pointer to core logger. */
        static std::shared_ptr<spdlog::logger> m_GameLogger;  /**< Pointer to user logger. */
    };


    constexpr std::shared_ptr<spdlog::logger> &Logger::GetCoreLogger() noexcept { return m_CoreLogger; }

    constexpr std::shared_ptr<spdlog::logger> &Logger::GetGameLogger() noexcept { return m_GameLogger; }


#ifdef DEBUG
#define CORE_LOG_TRACE(...) ::Bald::Logger::GetCoreLogger()->trace(__VA_ARGS__)   /**< Print info in Core Logger. */
#define CORE_LOG_INFO(...)  ::Bald::Logger::GetCoreLogger()->info(__VA_ARGS__)    /**< Print info in Core Logger. */
#define CORE_LOG_WARN(...)  ::Bald::Logger::GetCoreLogger()->warn(__VA_ARGS__)    /**< Print warning in Core Logger. */
#define CORE_LOG_ERROR(...) ::Bald::Logger::GetCoreLogger()->error(__VA_ARGS__)   /**< Print error in Core Logger. */

#define GAME_LOG_TRACE(...) ::Bald::Logger::GetGameLogger()->trace(__VA_ARGS__)   /**< Print info in Game Logger. */
#define GAME_LOG_INFO(...)  ::Bald::Logger::GetGameLogger()->info(__VA_ARGS__)    /**< Print info in Game Logger. */
#define GAME_LOG_WARN(...)  ::Bald::Logger::GetGameLogger()->warn(__VA_ARGS__)    /**< Print warning in Game Logger. */
#define GAME_LOG_ERROR(...) ::Bald::Logger::GetGameLogger()->error(__VA_ARGS__)   /**< Print error in Game Logger. */

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
