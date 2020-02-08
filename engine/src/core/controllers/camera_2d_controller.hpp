//
// Created by blinku on 07.02.2020.
//

#pragma once

#include <memory>
#include "graphics/rendering/camera_2d.h"

namespace Bald::Controllers {

    /**
     * @class Camera2DController
     * @brief This class is responsible for handling a Camera2D.
     */

    class Camera2DController {
    public:

        /**
         * @fn Camera2DController
         * @brief Takes ownership of certain Camera2D.
         */

        explicit Camera2DController(std::unique_ptr<Graphics::Camera2D> camera);

        Camera2DController(const Camera2DController&) = delete;

        Camera2DController(Camera2DController&&) noexcept = delete;

        Camera2DController& operator=(const Camera2DController&) = delete;

        Camera2DController& operator=(Camera2DController&&) = delete;

        /**
         * @fn GetCamera
         * @brief Getter.
         * @return const Graphics::Camera2D& Camera.
         */

        [[nodiscard]] const Graphics::Camera2D& GetCamera() const noexcept { return *m_Camera; }

        /**
         * @fn GetCamera
         * @brief This method is called once every frame.
         * @param deltaTime -> Time elapsed since last frame.
         */

        void OnUpdate(float deltaTime) noexcept;

    private:
        std::unique_ptr<Graphics::Camera2D> m_Camera; /**< Camera2D managed by this controller. */
        glm::vec2 m_Position; /**< Current camera position. */
        float m_CameraSpeed; /**< Current camera speed. */
    }; // END OF CLASS Camera2DController

} // END OF NAMESPACE Bald::Controllers
