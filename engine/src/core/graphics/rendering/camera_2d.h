//
// Created by blinku on 08.08.2019.
//

#pragma once

#include "glm/glm.hpp"

namespace Bald::Graphics {

    class Camera2D {
    public:
        explicit Camera2D(const glm::mat4& orthoProjection = glm::mat4(1.0f));

        inline void SetPosition(const glm::vec2 position) { m_Position = position; CalculateProjectionViewMatrix(); }

        [[nodiscard]] const glm::vec2& GetPosition() const noexcept { return m_Position; }
        [[nodiscard]] const glm::mat4& GetProjectionMatrix() const noexcept { return m_Projection; }
        [[nodiscard]] const glm::mat4& GetViewMatrix() const noexcept { return m_View; }
        [[nodiscard]] const glm::mat4& GetProjectionViewMatrix() const noexcept { return m_ProjectionView; }

    private:
        void CalculateProjectionViewMatrix();

    private:
        glm::vec2 m_Position;
        glm::mat4 m_Projection;
        glm::mat4 m_View;
        glm::mat4 m_ProjectionView;

    }; // END OF CLASS Camera2D

} // END OF NAMESPACE Bald::Graphics
