//
// Created by blinku on 07.05.19.
//

#include "bald.h"

#include "graphics/rendering/rendering_device/batch_2d.h"

using namespace Bald;
using namespace Graphics;

class GameLayer : public Layer {
GENERATE_BODY(DERIVED)

public:

    GameLayer() = default;

    ~GameLayer() override = default;

    void OnAttach() noexcept override {
        Renderer2D::Init();
        m_Sprite1.SetSize({50.0f, 50.0f});
        m_Sprite2.SetSize({50.0f, 50.0f});
        m_Sprite3.SetSize({50.0f, 50.0f});
        m_Sprite4.SetSize({50.0f, 50.0f});
        m_Sprite5.SetSize({50.0f, 50.0f});
        m_Sprite6.SetSize({50.0f, 50.0f});
        m_Sprite7.SetSize({50.0f, 50.0f});
        m_Sprite8.SetSize({50.0f, 50.0f});
        m_Sprite9.SetSize({50.0f, 50.0f});
        m_Sprite10.SetSize({50.0f, 50.0f});
        m_Sprite11.SetSize({50.0f, 50.0f});
        m_Sprite12.SetSize({50.0f, 50.0f});
        m_Sprite13.SetSize({50.0f, 50.0f});
        m_Sprite14.SetSize({50.0f, 50.0f});
        m_Sprite15.SetSize({50.0f, 50.0f});
        m_Sprite16.SetSize({50.0f, 50.0f});
        m_Sprite17.SetSize({50.0f, 50.0f});
        m_Sprite18.SetSize({50.0f, 50.0f});
        m_Sprite19.SetSize({50.0f, 50.0f});
        m_Sprite20.SetSize({50.0f, 50.0f});
        m_Sprite21.SetSize({50.0f, 50.0f});
        m_Sprite22.SetSize({50.0f, 50.0f});
        m_Sprite23.SetSize({50.0f, 50.0f});
        m_Sprite24.SetSize({50.0f, 50.0f});
        m_Sprite25.SetSize({50.0f, 50.0f});
        m_Sprite26.SetSize({50.0f, 50.0f});
        m_Sprite27.SetSize({50.0f, 50.0f});
        m_Sprite28.SetSize({50.0f, 50.0f});
        m_Sprite29.SetSize({50.0f, 50.0f});
        m_Sprite30.SetSize({50.0f, 50.0f});
        m_Sprite31.SetSize({50.0f, 50.0f});
        m_Sprite32.SetSize({50.0f, 50.0f});
        m_Sprite33.SetSize({50.0f, 50.0f});
        m_Sprite34.SetSize({50.0f, 50.0f});
    }

    void OnDetach() noexcept override {
        Renderer2D::Shutdown();
    }

    void OnUpdate() noexcept override {
        if(Input::InputManager::IsKeyPressed(BALD_KEY_A)) {
            m_Position.x -= m_CameraSpeed;
        } else if(Input::InputManager::IsKeyPressed(BALD_KEY_D)) {
            m_Position.x += m_CameraSpeed;
        }

        if(Input::InputManager::IsKeyPressed(BALD_KEY_W)) {
            m_Position.y += m_CameraSpeed;
        } else if(Input::InputManager::IsKeyPressed(BALD_KEY_S)) {
            m_Position.y -= m_CameraSpeed;
        }

        m_Camera.SetPosition({m_Position.x, m_Position.y});

        // Begin sprite rendering
        Renderer2D::Begin(m_Camera);

        for(std::size_t i = 0; i < 20; i++) {
            m_Sprite1.SetPosition({0, i * 50});
            m_Sprite2.SetPosition({50, i * 50});
            m_Sprite3.SetPosition({2 * 50, i * 50});
            m_Sprite4.SetPosition({3 * 50, i * 50});
            m_Sprite5.SetPosition({4 * 50, i * 50});
            m_Sprite6.SetPosition({5 * 50, i * 50});
            m_Sprite7.SetPosition({6 * 50, i * 50});
            m_Sprite8.SetPosition({7 * 50, i * 50});
            m_Sprite9.SetPosition({8 * 50, i * 50});
            m_Sprite10.SetPosition({9 * 50, i * 50});
            m_Sprite11.SetPosition({10 * 50, i * 50});
            m_Sprite12.SetPosition({11 * 50, i * 50});
            m_Sprite13.SetPosition({12 * 50, i * 50});
            m_Sprite14.SetPosition({13 * 50, i * 50});
            m_Sprite15.SetPosition({14 * 50, i * 50});
            m_Sprite16.SetPosition({15 * 50, i * 50});
            m_Sprite17.SetPosition({16 * 50, i * 50});
            m_Sprite18.SetPosition({17 * 50, i * 50});
            m_Sprite19.SetPosition({18 * 50, i * 50});
            m_Sprite20.SetPosition({19 * 50, i * 50});
            m_Sprite22.SetPosition({20 * 50, i * 50});
            m_Sprite23.SetPosition({21 * 50, i * 50});
            m_Sprite21.SetPosition({22 * 50, i * 50});
            m_Sprite24.SetPosition({23 * 50, i * 50});
            m_Sprite25.SetPosition({24 * 50, i * 50});
            m_Sprite26.SetPosition({25 * 50, i * 50});
            m_Sprite27.SetPosition({26 * 50, i * 50});
            m_Sprite28.SetPosition({27 * 50, i * 50});
            m_Sprite29.SetPosition({28 * 50, i * 50});
            m_Sprite30.SetPosition({29 * 50, i * 50});
            m_Sprite31.SetPosition({30 * 50, i * 50});
            m_Sprite32.SetPosition({31 * 50, i * 50});
            m_Sprite33.SetPosition({32 * 50, i * 50});
            m_Sprite34.SetPosition({33 * 50, i * 50});

            Renderer2D::Submit(m_Sprite1);
            Renderer2D::Submit(m_Sprite2);
            Renderer2D::Submit(m_Sprite3);
            Renderer2D::Submit(m_Sprite4);
            Renderer2D::Submit(m_Sprite5);
            Renderer2D::Submit(m_Sprite6);
            Renderer2D::Submit(m_Sprite7);
            Renderer2D::Submit(m_Sprite8);
            Renderer2D::Submit(m_Sprite9);
            Renderer2D::Submit(m_Sprite10);
            Renderer2D::Submit(m_Sprite11);
            Renderer2D::Submit(m_Sprite12);
            Renderer2D::Submit(m_Sprite13);
            Renderer2D::Submit(m_Sprite14);
            Renderer2D::Submit(m_Sprite15);
            Renderer2D::Submit(m_Sprite16);
            Renderer2D::Submit(m_Sprite17);
            Renderer2D::Submit(m_Sprite18);
            Renderer2D::Submit(m_Sprite19);
            Renderer2D::Submit(m_Sprite20);
            Renderer2D::Submit(m_Sprite21);
            Renderer2D::Submit(m_Sprite22);
            Renderer2D::Submit(m_Sprite23);
            Renderer2D::Submit(m_Sprite24);
            Renderer2D::Submit(m_Sprite25);
            Renderer2D::Submit(m_Sprite26);
            Renderer2D::Submit(m_Sprite27);
            Renderer2D::Submit(m_Sprite28);
            Renderer2D::Submit(m_Sprite29);
            Renderer2D::Submit(m_Sprite30);
            Renderer2D::Submit(m_Sprite31);
            Renderer2D::Submit(m_Sprite32);
            Renderer2D::Submit(m_Sprite33);
            Renderer2D::Submit(m_Sprite34);
        }

        Renderer2D::End();
        // End sprite rendering
    }

    void OnRender() noexcept override {}

private:
    Camera2D m_Camera{glm::ortho(0.0f, 1920.0f, 0.0f, 1080.0f)};
    Sprite m_Sprite1{Texture::Create("../engine/res/textures/lena.jpg")};
    Sprite m_Sprite2{Texture::Create("../engine/res/textures/fabric.jpg")};
    Sprite m_Sprite3{Texture::Create("../engine/res/textures/pixel_textures/Bricks/BIGBRICKS.png")};
    Sprite m_Sprite4{Texture::Create("../engine/res/textures/pixel_textures/Bricks/CASTLEBRICKS.png")};
    Sprite m_Sprite5{Texture::Create("../engine/res/textures/pixel_textures/Bricks/CLAYBRICKS.png")};
    Sprite m_Sprite6{Texture::Create("../engine/res/textures/pixel_textures/Bricks/DUNGEONBRICKS.png")};
    Sprite m_Sprite7{Texture::Create("../engine/res/textures/pixel_textures/Bricks/DUNGEONCELL.png")};
    Sprite m_Sprite8{Texture::Create("../engine/res/textures/pixel_textures/Bricks/GOOBRICKS.png")};
    Sprite m_Sprite9{Texture::Create("../engine/res/textures/pixel_textures/Bricks/PORCELAINBRICKS.png")};
    Sprite m_Sprite10{Texture::Create("../engine/res/textures/pixel_textures/Bricks/REDBRICKS.png")};
    Sprite m_Sprite11{Texture::Create("../engine/res/textures/pixel_textures/Bricks/ROUNDBRICKS.png")};
    Sprite m_Sprite12{Texture::Create("../engine/res/textures/pixel_textures/Bricks/SLIMBRICKS.png")};
    Sprite m_Sprite13{Texture::Create("../engine/res/textures/pixel_textures/Elements/BIGLEAVES.png")};
    Sprite m_Sprite14{Texture::Create("../engine/res/textures/pixel_textures/Elements/LAVA.png")};
    Sprite m_Sprite15{Texture::Create("../engine/res/textures/pixel_textures/Elements/RAPIDS.png")};
    Sprite m_Sprite16{Texture::Create("../engine/res/textures/pixel_textures/Elements/SAND.png")};
    Sprite m_Sprite17{Texture::Create("../engine/res/textures/pixel_textures/Elements/SANDMARKS.png")};
    Sprite m_Sprite18{Texture::Create("../engine/res/textures/pixel_textures/Elements/SNOW.png")};
    Sprite m_Sprite19{Texture::Create("../engine/res/textures/pixel_textures/Elements/TALLGRASS.png")};
    Sprite m_Sprite20{Texture::Create("../engine/res/textures/pixel_textures/Elements/TINYLEAVES.png")};
    Sprite m_Sprite21{Texture::Create("../engine/res/textures/pixel_textures/Elements/WATER.png")};
    Sprite m_Sprite22{Texture::Create("../engine/res/textures/pixel_textures/Industrial/CROSSCUBE.png")};
    Sprite m_Sprite23{Texture::Create("../engine/res/textures/pixel_textures/Industrial/CROSSWALL.png")};
    Sprite m_Sprite24{Texture::Create("../engine/res/textures/pixel_textures/Industrial/METALTILE.png")};
    Sprite m_Sprite25{Texture::Create("../engine/res/textures/pixel_textures/Industrial/PIPES.png")};
    Sprite m_Sprite26{Texture::Create("../engine/res/textures/pixel_textures/Industrial/STORAGE.png")};
    Sprite m_Sprite27{Texture::Create("../engine/res/textures/pixel_textures/Industrial/SUPPORT.png")};
    Sprite m_Sprite28{Texture::Create("../engine/res/textures/pixel_textures/Rocks/DIRT.png")};
    Sprite m_Sprite29{Texture::Create("../engine/res/textures/pixel_textures/Rocks/FLATSTONES.png")};
    Sprite m_Sprite30{Texture::Create("../engine/res/textures/pixel_textures/Rocks/GOLDROCKS.png")};
    Sprite m_Sprite31{Texture::Create("../engine/res/textures/pixel_textures/Rocks/ICEYROCKS.png")};
    Sprite m_Sprite32{Texture::Create("../engine/res/textures/pixel_textures/Rocks/LAVAROCKS.png")};
    Sprite m_Sprite33{Texture::Create("../engine/res/textures/pixel_textures/Rocks/PATHROCKS.png")};
    Sprite m_Sprite34{Texture::Create("../engine/res/textures/pixel_textures/Rocks/SLIMROCKS.png")};

    float m_CameraSpeed = 0.5f;
    glm::vec2 m_Position{0.0f};
};

class Sandbox : public Application {
GENERATE_BODY(DERIVED)

public:

    Sandbox() {
        PushLayer<GameLayer>();
    }

    ~Sandbox() override = default;

};

Application* Application::Create() noexcept {
    return new Sandbox();
}
