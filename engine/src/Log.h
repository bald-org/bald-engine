//
// Created by grzegorz on 15.12.18.
//

#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Bald {

/**
 * @class Log
 * @brief implementation of basic logging system
 * */

    class Log {
    public:

        /**
         * @fn Init
         * @brief Initialize Core Logger and User Logger
         */

        static void Init(); //should be called in some default defined Game class but for now probably in Window Constructor or manually in every test and sample

        /**
         * @fn GetCoreLogger
         * @brief use to get access to Core Logger
         * @return reference to Core Logger
         */

        [[nodiscard]] constexpr inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() noexcept;

        /**
         * @fn GetGameLogger
         * @brief use to get access to Game Logger
         * @return reference to Game Logger
         */

        [[nodiscard]] constexpr inline static std::shared_ptr<spdlog::logger> &GetGameLogger() noexcept;

    private:
        static std::shared_ptr<spdlog::logger> m_CoreLogger;  /**< pointer to core logger */
        static std::shared_ptr<spdlog::logger> m_GameLogger;  /**< pointer to user logger */
    };


    constexpr std::shared_ptr<spdlog::logger> &Log::GetCoreLogger() noexcept { return m_CoreLogger; }

    constexpr std::shared_ptr<spdlog::logger> &Log::GetGameLogger() noexcept { return m_GameLogger; }


#ifdef DEBUG
#define CORE_LOG_TRACE(...) ::Bald::Log::GetCoreLogger()->trace(__VA_ARGS__)   /**< print info in Core Logger */
#define CORE_LOG_INFO(...)  ::Bald::Log::GetCoreLogger()->info(__VA_ARGS__)    /**< print info in Core Logger */
#define CORE_LOG_WARN(...)  ::Bald::Log::GetCoreLogger()->warn(__VA_ARGS__)    /**< print warning in Core Logger */
#define CORE_LOG_ERROR(...) ::Bald::Log::GetCoreLogger()->error(__VA_ARGS__)   /**< print error in Core Logger */

#define GAME_LOG_TRACE(...) ::Bald::Log::GetGameLogger()->trace(__VA_ARGS__)   /**< print info in Game Logger */
#define GAME_LOG_INFO(...)  ::Bald::Log::GetGameLogger()->info(__VA_ARGS__)    /**< print info in Game Logger */
#define GAME_LOG_WARN(...)  ::Bald::Log::GetGameLogger()->warn(__VA_ARGS__)    /**< print warning in Game Logger */
#define GAME_LOG_ERROR(...) ::Bald::Log::GetGameLogger()->error(__VA_ARGS__)   /**< print error in Game Logger */

#else
#define CORE_LOG_TRACE(...) /**< empty instruction */
#define CORE_LOG_INFO(...)  /**< empty instruction */
#define CORE_LOG_WARN(...)  /**< empty instruction */
#define CORE_LOG_ERROR(...) /**< empty instruction */

#define GAME_LOG_TRACE(...) /**< empty instruction */
#define GAME_LOG_INFO(...)  /**< empty instruction */
#define GAME_LOG_WARN(...)  /**< empty instruction */
#define GAME_LOG_ERROR(...) /**< empty instruction */
#endif
} // END OF NAMESPACE Bald
