//
// Created by blinku on 29.07.2019.
//

#pragma once

#include "pch.h"
#include <memory>

namespace Bald::Graphics {

    enum class TextureWrapMode : uint8_t {
        Unknown = 0, Repeat, MirroredRepeat, ClampToEdge, ClampToBorder
    };

    enum class TextureFilterMethod : uint8_t {
        Unknown = 0, Nearest, Linear, NearestMipmapNearest, NearestMipmapLinear, LinearMipmapNearest, LinearMipmapLinear
    };

    enum class TextureFilterMode : uint8_t {
        Unknown = 0, Min, Mag
    };

    enum class TextureCoordinate : uint8_t {
        Unknown = 0, S, T
    };

    class Texture {
    public:
        static std::shared_ptr<Texture> Create(const std::string& filepath);

        explicit Texture(std::string filepath) : m_Filepath(std::move(filepath)) {}

        virtual ~Texture() = default;

        virtual void Bind() const noexcept = 0;
        virtual void Unbind() const noexcept = 0;
        virtual void Activate(uint8_t index) const noexcept = 0;
        virtual void SetWrapping(TextureCoordinate texCoord, TextureWrapMode wrappingMode) = 0;
        virtual void SetFiltering(TextureFilterMode filterMode, TextureFilterMethod filterMethod) = 0;

        [[nodiscard]] inline const std::string& GetFilepath() const noexcept { return m_Filepath; }

        [[nodiscard]] inline int32_t GetWidth() const noexcept { return m_Width; }

        [[nodiscard]] inline int32_t GetHeight() const noexcept { return m_Height; }

        [[nodiscard]] inline int32_t GetNrChannels() const noexcept { return m_NrChannels; }

    protected:
        const std::string m_Filepath;
        int32_t m_Width = 0;
        int32_t m_Height = 0;
        int32_t m_NrChannels = 0;
        u_char* m_Data = nullptr;

    }; // END OF CLASS Texture

} // END OF NAMESPACE Bald::Graphics