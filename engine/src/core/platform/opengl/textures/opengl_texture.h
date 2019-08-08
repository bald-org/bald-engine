//
// Created by blinku on 29.07.2019.
//

#pragma once

#include "pch.h"
#include "graphics/rendering/textures/texture.h"

namespace Bald::Platform::Graphics {

class OpenGLTexture : public Bald::Graphics::Texture {
    friend class Texture;
    private:
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


