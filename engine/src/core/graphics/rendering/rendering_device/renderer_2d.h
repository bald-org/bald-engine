//
// Created by blinku on 07.08.2019.
//

#pragma once

#include <memory>
#include "batch_2d.h"

namespace Bald::Graphics {

    class Sprite;

    class VertexArray;

    class VertexBuffer;

    class IndexBuffer;

    class Shader;

    class Camera2D;

    /**
     * @class Renderer2DStorage
     * @brief Storage for Renderer's 2D state.
     */

    struct Renderer2DStorage {
        static inline std::unique_ptr<Batch2D> m_Batch = nullptr; /**< Batch to be rendered >*/
        static inline const Camera2D* m_Camera = nullptr; /**< Current camera >*/
    };

    /**
     * @class Renderer2D
     * @brief Implementation of 2D renderer.
     */

    class Renderer2D {
    public:
        Renderer2D() = delete;

        Renderer2D(const Renderer2D&) = delete;

        Renderer2D(Renderer2D&&) = delete;

        ~Renderer2D() = delete;

        Renderer2D& operator=(const Renderer2D&) = delete;

        Renderer2D& operator=(Renderer2D&&) = delete;

        /**
         * @fn Init
         * @brief Initializes Renderer2DStorage struct. Has to be called after initialization of OpenGL/GLFW.
         */
        static void Init() noexcept;

        /**
         * @fn Shutdown
         * @brief Releases resources held by Renderer2DStorage struct. Has to be called before deinitialization of OpenGL/GLFW.
         */

        static void Shutdown() noexcept;

        /**
         * @fn Begin
         * @brief Begins scene rendering. Must be called every frame before submitting any data to the renderer.
         * @param camera -> Current scene's camera.
         */

        static void Begin(const Camera2D& camera) noexcept;

        /**
         * @fn Submit
         * @brief Submits a sprite to the batch in Renderer2DStorage. Doesnt' guarantee draw call at the time of submission.
         * @param sprite -> Sprite to be drawn.
         */

        static void Submit(const Sprite& sprite) noexcept;

        /**
         * @fn End
         * @brief Ends scene rendering by drawing what is left in the batch. Must be called at the end of every frame.
         */

        static void End() noexcept;

    private:

        /**
         * @fn Draw
         * @brief Ends batching and draws current batch.
         */

        static void Draw() noexcept;
    }; // END OF CLASS Renderer2D

} // END OF NAMESPACE Bald::Graphics
