//
// Created by grzegorz on 08.02.19.
//

#include "gtest/gtest.h"

#include "graphics/rendering/buffers/index_buffer.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

TEST(index_buffer, index_buffer_initialisation_Test) {
    using namespace Bald;
    using namespace Graphics;

    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));

    unsigned short data[4] = {
        1, 2, 3, 4
    };

    auto buf = IndexBuffer::Create(data, 4);
    buf->Bind();
    buf->Unbind();

    EXPECT_EQ(4, buf->GetCount());
    EXPECT_TRUE(buf->GetID());

    glfwDestroyWindow(window);
}
