//
// Created by blinku on 29.07.2019.
//

#pragma once

#include "utils/image.h"

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
    protected:

        /**
        * @fn Texture
        * @brief Constructor
        * @param std::string Filepath.
        */

        explicit Texture(std::string filepath) : m_Image(std::move(filepath)) {}

    public:

        /**
        * @fn Create
        * @brief Creates texture based on currently chosen rendering API.
        * @param const std::string& Filepath.
        * @return std::shared_ptr<Texture> Pointer to the texture object.
        */

        static std::shared_ptr<Texture> Create(const std::string& filepath);

        /**
        * @fn !Texture
        * @brief Default virtual destructor.
        */

        virtual ~Texture() = default;

        /**
        * @fn Bind
        * @brief Pure virtual method used for binding the texture.
        */

        virtual void Bind() const noexcept = 0;

        /**
        * @fn Unbind
        * @brief Pure virtual method used for unbinding the texture.
        */

        virtual void Unbind() const noexcept = 0;

        /**
        * @fn Activate
        * @brief Pure virtual method used for activating the texture.
        */

        virtual void Activate(uint8_t index) const noexcept = 0;

        /**
        * @fn SetWrapping
        * @brief Pure virtual method used for setting the wrapping mode for the texture.
        */

        virtual void SetWrapping(TextureCoordinate texCoord, TextureWrapMode wrappingMode) = 0;

        /**
        * @fn SetFiltering
        * @brief Pure virtual method used for setting the filtering mode for the texture.
        */

        virtual void SetFiltering(TextureFilterMode filterMode, TextureFilterMethod filterMethod) = 0;

        /**
        * @fn GetFilepath
        * @brief Filepath getter.
        */

        [[nodiscard]] inline const std::string& GetFilepath() const noexcept { return m_Image.GetFilepath(); }

        /**
        * @fn GetWidth
        * @brief Width getter.
        */

        [[nodiscard]] inline int32_t GetWidth() const noexcept { return m_Image.GetWidth(); }

        /**
        * @fn GetHeight
        * @brief Height getter.
        */

        [[nodiscard]] inline int32_t GetHeight() const noexcept { return m_Image.GetHeight(); }

        /**
        * @fn GetNrChannels
        * @brief Number of channels getter.
        */

        [[nodiscard]] inline int32_t GetNrChannels() const noexcept { return m_Image.GetNrChannels(); }

    protected:
        Utils::Image m_Image; /**< Texture bitmap. >*/

    }; // END OF CLASS Texture

} // END OF NAMESPACE Bald::Graphics