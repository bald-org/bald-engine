//
// Created by blinku on 29.07.2019.
//

#pragma once

#include "pch.h"

namespace Bald::Graphics {

    class Texture {
    public:
        static Texture* Create(const std::string& filepath);

        explicit Texture(std::string filepath) : m_Filepath(std::move(filepath)) {}

        virtual ~Texture() = default;

        virtual void Bind() const noexcept = 0;
        virtual void Unbind() const noexcept = 0;

        [[nodiscard]] inline const std::string& GetFilepath() const noexcept { return m_Filepath; }

        [[nodiscard]] inline int32_t GetWidth() const noexcept { return m_Width; }

        [[nodiscard]] inline int32_t GetHeight() const noexcept { return m_Height; }

        [[nodiscard]] inline int32_t GetNrChannels() const noexcept { return m_NrChannels; }

    protected:
        const std::string m_Filepath;
        int32_t m_Width = 0;
        int32_t m_Height = 0;
        int32_t m_NrChannels = 0;
        unsigned char* m_Data = nullptr;

    }; // END OF CLASS Texture

} // END OF NAMESPACE Bald::Graphics