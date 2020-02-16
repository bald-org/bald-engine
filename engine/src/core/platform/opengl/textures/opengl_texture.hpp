//
// Created by blinku on 29.07.2019.
//

#pragma once

#include "pch.hpp"
#include "graphics/rendering/textures/texture.hpp"

namespace Bald::Platform::Graphics {

class OpenGLTexture : public Bald::Graphics::Texture {
    friend class ::Bald::Graphics::Texture;
    private:
        explicit OpenGLTexture(int32_t width, int32_t height);
        explicit OpenGLTexture(std::string filepath);

    public:

        /**
        * @fn OpenGLTexture
        * @brief Default constructor deleted.
        */

        OpenGLTexture() = delete;

        /**
        * @fn ~OpenGLTexture
        * @brief Destructor.
        */

        ~OpenGLTexture() override;

        /**
        * @fn Bind
        * @brief Binds the texture.
        */

        void Bind() const noexcept override;

        /**
        * @fn Unbind
        * @brief Unbinds the texture.
        */

        void Unbind() const noexcept override;

        /**
        * @fn Activate
        * @brief Activates the texture.
        */

        void Activate(uint8_t index) const noexcept override;

        /**
        * @fn SetWrapping
        * @brief Sets wrapping mode for the texture.
        */

        void SetWrapping(Bald::Graphics::TextureCoordinate texCoord, Bald::Graphics::TextureWrapMode wrappingMode) override;

        /**
        * @fn SetFiltering
        * @brief Sets filtering mode for the texture.
        */

        void SetFiltering(Bald::Graphics::TextureFilterMode filterMode, Bald::Graphics::TextureFilterMethod filterMethod) override;

        /**
        * @fn GetID
        * @brief Returns texture's ID.
        * @return int32_t texture ID.
        */
        [[nodiscard]] int32_t GetID() const noexcept override { return static_cast<int32_t>(m_ID); };

private:

    /**
     * @fn Init
     * @brief Attempts to initialize the texture and returns success result (true/false).
     * @return [bool] true -> texture was initialized successfully.
     *                false -> texture wasn't initialized successfully.
     */

    [[nodiscard]] bool Init() noexcept;

    /**
     * @fn Shutdown
     * @brief Destroys the texture.
     */

    void Shutdown();

    private:
        uint32_t m_ID; /**< Texture id. >*/
    };

}


