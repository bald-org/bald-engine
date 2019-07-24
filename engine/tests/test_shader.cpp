//
// Created by blinku on 28.05.19.
//

#include "pch.h"
#include "gtest/gtest.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "src/core/graphics/rendering/shaders/shader.h"

TEST(Shader, ShaderInitialization) { //NOLINT

    using namespace Bald::Graphics;

    if(!glfwInit()) {
        std::cout << "Failed to initialize GLFW!" << std::endl;
        exit(1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* m_Window = glfwCreateWindow(800, 600, "test_shader", nullptr, nullptr);
    if(!m_Window) {
        glfwTerminate();
        exit(1);
    }
    glfwMakeContextCurrent(m_Window);

    if(!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(1);
    }

    std::unique_ptr<Shader> shader(Shader::Create("../engine/res/shaders/basic.vert", "../engine/res/shaders/basic.frag"));

    EXPECT_TRUE(shader->GetID());
}

TEST(Shader, WrongShaderInitialization) { //NOLINT

    using namespace Bald::Graphics;

    if(!glfwInit()) {
        std::cout << "Failed to initialize GLFW!" << std::endl;
        exit(1);
    }


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* m_Window = glfwCreateWindow(800, 600, "test_shader", nullptr, nullptr);
    if(!m_Window) {
        glfwTerminate();
        exit(1);
    }
    glfwMakeContextCurrent(m_Window);

    if(!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(1);
    }

    std::unique_ptr<Shader> shader(Shader::Create("../engine/res/shaders/no_such_shader.vert", "../engine/res/shaders/no_such_shader.frag"));
    EXPECT_FALSE(shader->GetID());
}
