//
// Created by blinku on 23.11.2019.
//

#pragma once

#include <memory>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include "graphics/rendering/buffers/vertex_buffer_layout.h"
#include "graphics/rendering/buffers/vertex_array.h"
#include "graphics/rendering/buffers/vertex_buffer.h"
#include "graphics/rendering/buffers/index_buffer.h"
#include "graphics/rendering/shaders/shader.h"

namespace Bald::Graphics {
    class Sprite;

    class Camera2D;

    /**
     * @class SpriteVertexData
     * @brief Helper struct used for buffer mapping.
     */

    struct SpriteVertexData {
        glm::vec3 m_Position;
        glm::vec4 m_Color;
        glm::vec2 m_TextureCoord;
        float m_TextureId;
    };

    struct SpriteVertexPositions {
        static constexpr glm::vec4 vertex1 = glm::vec4{0.0f, 0.0f, 0.0f, 1.0f};
        static constexpr glm::vec4 vertex2 = glm::vec4{0.0f, 1.0f, 0.0f, 1.0f};
        static constexpr glm::vec4 vertex3 = glm::vec4{1.0f, 1.0f, 0.0f, 1.0f};
        static constexpr glm::vec4 vertex4 = glm::vec4{1.0f, 0.0f, 0.0f, 1.0f};
    };

    /**
     * @class Batch2D
     * @brief Abstraction representing single renderable batch of sprites.
     */

    class Batch2D {
        using TEXTURE_ID = uint32_t;

    public:

        Batch2D(const Batch2D&) = delete;

        Batch2D(Batch2D&&) = delete;

        Batch2D& operator=(const Batch2D&) = delete;

        Batch2D& operator=(Batch2D&&) = delete;

        /**
         * @fn Batch2D
         * @brief Default constructor. Acquires resources such as buffers and shaders.
         */

        Batch2D();

        /**
         * @fn ~Batch2D
         * @brief Destructor. Safely unmaps the buffer if it was left mapped by any chance.
         */

        ~Batch2D();

        /**
         * @fn Begin
         * @brief Begins buffer mapping and sets projection view matrix in the sprite shader.
         * @param camera -> Current scene's camera.
         */

        void Begin(const Camera2D& camera, const std::pair<double, double>& mousePos) noexcept;

        /**
         * @fn Submit
         * @brief Submits a sprite into the vertex buffer.
         * @param sprite -> Sprite to be submitted.
         */

        bool Submit(const Sprite& sprite);

        /**
         * @fn End
         * @brief Ends buffer mapping.
         */

        void End() noexcept;

        /**
         * @fn Draw
         * @brief Draws current buffer.
         */

        void Draw() noexcept;

    private:
        SpriteVertexData* m_MappedBuffer = nullptr; /**< Pointer to mapped vertex buffer >*/
        uint32_t m_MaxVertices; /**< Maximum number of vertices that this batch supports >*/
        uint32_t m_UsedVertices; /**< Used number of vertices that this batch supports >*/
        uint32_t m_MaxIndices; /**< Maximum number of indices that this batch supports >*/
        uint32_t m_UsedIndices; /**< Used number of indices that this batch supports >*/
        std::shared_ptr<VertexArray> m_QuadVAO; /**< Vertex array >*/
        std::shared_ptr<VertexBuffer> m_QuadVBO; /**< Vertex buffer >*/
        std::shared_ptr<IndexBuffer> m_QuadIBO; /**< Index buffer >*/
        std::shared_ptr<Shader> m_QuadShader; /**< Sprite shader >*/
        std::vector<TEXTURE_ID> m_Textures; /**< Textures in this batch that are sent to shader >*/
        std::vector<int32_t> m_TextureUnits; /**< Textures units >*/
    }; // END OF CLASS Batch

} // END OF NAMESPACE Bald::Graphics


