#include <utility>

//
// Created by grzegorz on 01.06.19.
//

#pragma once

#include <string>

namespace Bald::Debug {

    class Logger {
    public:
        explicit Logger(std::string name): m_Name(std::move(name)) {}
        explicit Logger() = default;

        void setName(const std::string& name);

        void trace(const std::string& mess) const noexcept;
        void info(const std::string& mess) const noexcept;
        void warn(const std::string& mess) const noexcept;
        void error(const std::string& mess) const noexcept;

    private:
        void print(const std::string& mess) const noexcept;

    private:
        std::string m_Name;
    };

}





