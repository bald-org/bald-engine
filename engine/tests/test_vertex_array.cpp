//
// Created by grzegorz on 12.02.19.
//

#include "gtest/gtest.h"

#include "graphics/rendering/buffers/vertex_buffer.h"
#include "graphics/rendering/buffers/vertex_array.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

TEST(vertex_array, vertex_array_init_Test) {
    using namespace Bald;
    using namespace Graphics;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, 1);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));

    float data[4] = {
        1.0f, 2.0f, 3.0f, 4.0f
    };

    auto buf = VertexBuffer::Create(data, 4);
    buf->Bind();
    buf->Unbind();

    std::shared_ptr<VertexArray> VAO{VertexArray::Create()};
    std::shared_ptr<VertexBuffer> VBO{VertexBuffer::Create(data, sizeof(data))};

    VAO->Bind();
    VAO->Unbind();

    glfwDestroyWindow(window);
}
