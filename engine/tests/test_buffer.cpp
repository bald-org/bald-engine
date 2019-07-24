//
// Created by grzegorz on 08.02.19.
//

#include "gtest/gtest.h"

#include "graphics/rendering/buffers/vertex_buffer.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

TEST(buffer, buffer_initialisation_Test) {
    using namespace Bald;
    using namespace Graphics;

    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));

    float data[4] = {
        1.0f, 2.0f, 3.0f, 4.0f
    };

    auto buf = Bald::Graphics::VertexBuffer::Create(data, 4, 1);
    buf->Bind();
    buf->Unbind();

    EXPECT_EQ(1, buf->GetComponentCount());
    EXPECT_TRUE(buf->GetID());

    glfwDestroyWindow(window);
}
