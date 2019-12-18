//
// Created by blinku on 08.08.2019.
//

#pragma once

#include "glm/glm.hpp"

namespace Bald::Graphics {

    /**
     * @class Camera2D
     * @brief Implementation of 2D camera.
     */

    class Camera2D {
    public:

        /**
         * @fn Camera2D
         * @brief Constructs a 2d camera object.
         * @param orthoProjection -> Orthographic projection matrix.
         */

        explicit Camera2D(const glm::mat4& orthoProjection = glm::mat4(1.0f));

        /**
         * @fn SetPosition
         * @brief Sets camera position and recalculates projection view matrix.
         * @param position -> New position of the camera.
         */

        inline void SetPosition(const glm::vec2& position) { SetPosition({position.x, position.y, 0.0f}); }

        /**
         * @fn SetPosition
         * @brief Sets camera position and recalculates projection view matrix.
         * @param position -> New position of the camera.
         */

        inline void SetPosition(const glm::vec3& position) {
            m_Position = position;
            CalculateProjectionViewMatrix();
        }

        /**
         * @fn GetPosition
         * @brief Camera's position getter.
         * @return const glm::vec3& Position.
         */

        [[nodiscard]] const glm::vec3& GetPosition() const noexcept { return m_Position; }

        /**
         * @fn GetProjectionMatrix
         * @brief Camera's projection matrix getter.
         * @return const glm::mat4& Projection matrix.
         */

        [[nodiscard]] const glm::mat4& GetProjectionMatrix() const noexcept { return m_Projection; }

        /**
         * @fn GetViewMatrix
         * @brief Camera's view matrix getter.
         * @return const glm::mat4& View matrix.
         */

        [[nodiscard]] const glm::mat4& GetViewMatrix() const noexcept { return m_View; }

        /**
         * @fn GetProjectionViewMatrix
         * @brief Camera's projection view matrix getter.
         * @return const glm::mat4& Projection view matrix.
         */

        [[nodiscard]] const glm::mat4& GetProjectionViewMatrix() const noexcept { return m_ProjectionView; }

    private:

        /**
         * @fn CalculateProjectionViewMatrix
         * @brief Recalculates projection view matrix.
         */

        void CalculateProjectionViewMatrix();

    private:
        glm::vec3 m_Position; /**< Camera position >*/
        glm::mat4 m_Projection; /**< Projection matrix >*/
        glm::mat4 m_View; /**< View matrix >*/
        glm::mat4 m_ProjectionView; /**< Projection view matrix >*/

    }; // END OF CLASS Camera2D

} // END OF NAMESPACE Bald::Graphics
