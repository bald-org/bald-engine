//
// Created by blinku on 09.08.2019.
//

#pragma once

#include "glm/glm.hpp"
#include "graphics/rendering/textures/texture.h"

namespace Bald::Graphics {

    class Sprite {
    public:
        /**
         * @fn Sprite
         * @brief Constructor.
         * @param std::shared_ptr<Texture> Texture to be used with sprite.
         */

        explicit Sprite(std::shared_ptr<Texture> texture);

        /**
         * @fn SetPosition
         * @brief Sets position of the sprite.
         * @param const glm::vec2& Position.
         */

        inline void SetPosition(const glm::vec2& position) noexcept { m_Position = position; }

        /**
         * @fn SetSize
         * @brief Sets size of the sprite.
         * @param const glm::vec2& Size.
         */

        inline void SetSize(const glm::vec2& size) noexcept { m_Size = size; }

        /**
         * @fn SetColor
         * @brief Sets color of the sprite.
         * @param const glm::vec2& Color.
         */

        inline void SetColor(const glm::vec4& color) noexcept { m_Color = color; }

        /**
         * @fn SetTexture
         * @brief Sets texture of the sprite.
         * @param std::shared_ptr<Texture> Texture.
         */

        inline void SetTexture(std::shared_ptr<Texture> texture ) noexcept { m_Texture = std::move(texture); }

        /**
         * @fn GetPosition
         * @brief Position getter.
         * @return const glm::vec2& Position.
         */

        [[nodiscard]] inline const glm::vec2& GetPosition() const noexcept { return m_Position; }

        /**
         * @fn GetSize
         * @brief Size getter.
         * @return const glm::vec2& Size.
         */

        [[nodiscard]] inline const glm::vec2& GetSize() const noexcept { return m_Size; }

        /**
         * @fn GetColor
         * @brief Color getter.
         * @return const glm::vec4& Color.
         */

        [[nodiscard]] inline const glm::vec4& GetColor() const noexcept { return m_Color; }

        /**
         * @fn GetTexture
         * @brief Texture getter.
         * @return std::weak_ptr<Texture> Texture.
         */

        [[nodiscard]] inline std::weak_ptr<Texture> GetTexture() const noexcept { return m_Texture; }

    private:
        float m_Rotation; /**< Rotation around Z axis. */
        glm::vec2 m_Position; /**< Position */
        glm::vec2 m_Size; /**< Size */
        glm::vec4 m_Color; /**< Color */
        std::shared_ptr<Texture> m_Texture; /**< Texture */
    }; // END OF CLASS Sprite


} // END OF NAMESPACE Bald::Graphics
