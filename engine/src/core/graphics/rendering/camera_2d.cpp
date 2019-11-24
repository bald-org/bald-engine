//
// Created by blinku on 08.08.2019.
//

#include "camera_2d.h"
#include "glm/gtc/matrix_transform.hpp"

namespace Bald::Graphics {

    Camera2D::Camera2D(const glm::mat4& orthoProjection)
        : m_Position(0.0f), m_Projection(orthoProjection), m_View(glm::mat4(1.0f)), m_ProjectionView(m_Projection)
    {}

    void Camera2D::CalculateProjectionViewMatrix() {
        m_View = glm::translate(glm::mat4(1.0f), {-m_Position.x, -m_Position.y, -m_Position.z});
        m_ProjectionView = m_Projection * m_View;
    }
}