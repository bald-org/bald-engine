//
// Created by grzegorz on 30.09.19.
//

#include "bald.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace Bald;
using namespace Bald::Graphics;

class ExampleLayer : public Bald::Layer {
GENERATE_BODY(DERIVED)

public:
    ExampleLayer()  :
            m_Shader(Shader::Create("../sandbox/res/model_example/shaders/basic.vert", "../sandbox/res/model_example/shaders/basic.frag")),
            m_Nano("nanosuit.obj") {}

    ~ExampleLayer() override = default;

    void OnAttach() noexcept override {}

    void OnDetach() noexcept override {}
    float  x = 45.0f;
    void OnUpdate() noexcept override {
        m_Shader->Bind();
        glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), Application::GetApplication().GetWindow()->GetAspectRatio(), 0.1f, 1000.0f);
        glm::mat4 view = glm::lookAt(pos, pos + front, up);
        m_Shader->SetUniformMat4f("projection", projection);
        m_Shader->SetUniformMat4f("view", view);

        // render the loaded model
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, -5.0f)); // translate it down so it's at the center of the scene
        model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// it's a bit too big for our scene, so scale it down
        x += 1.0f / 3600;
//        model = glm::rotate(model, x, glm::vec3(0, 1, 0));
        model = glm::rotate(model, x, up);
        m_Shader->SetUniformMat4f("model", model);

        m_Nano.Draw(*m_Shader);
    }

    void OnRender() noexcept override {}

private:
    std::shared_ptr<Shader> m_Shader;
    Platform::Graphics::Model m_Nano;
};

class ApplicationExample : public Bald::Application {
GENERATE_BODY(DERIVED)

public:
    ApplicationExample() {
            PushLayer<ExampleLayer>();
    }

    ~ApplicationExample() override = default;


};

Bald::Application* Bald::Application::Create() noexcept {
    return new ApplicationExample();
}
