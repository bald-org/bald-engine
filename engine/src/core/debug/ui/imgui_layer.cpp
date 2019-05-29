//
// Created by blinku on 29.05.19.
//

#include "imgui_layer.h"
#include "imgui.h"
#include "platform/graphics/opengl/imgui/imgui_impl_opengl3.h"
#include "application.h"

#include "GLFW/glfw3.h"

namespace Bald {

    void ImGuiLayer::OnAttach() noexcept {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;         // We can honor GetMouseCursor() values (optional)
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;          // We can honor io.WantSetMousePos requests (optional, rarely used)

        // Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array.
        io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
        io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
        io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
        io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
        io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
        io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
        io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
        io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
        io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
        io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
        io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
        io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
        io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
        io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
        io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
        io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
        io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
        io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
        io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
        io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
        io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

        ImGui_ImplOpenGL3_Init("#version 330");

        m_EventManager.Subscribe<Bald::KeyPressedEvent>(Bald::HandleType::SYNC, [this](const KeyPressedEvent& e) { OnKeyPressedEvent(e); });
        m_EventManager.Subscribe<Bald::KeyTypedEvent>(Bald::HandleType::SYNC, [this](const KeyTypedEvent& e) { OnKeyTypedEvent(e); });
        m_EventManager.Subscribe<Bald::KeyReleasedEvent>(Bald::HandleType::SYNC, [this](const KeyReleasedEvent& e) { OnKeyReleasedEvent(e); });

        m_EventManager.Subscribe<Bald::MouseButtonPressedEvent>(Bald::HandleType::SYNC, [this](const MouseButtonPressedEvent& e) { OnMouseButtonPressedEvent(e); });
        m_EventManager.Subscribe<Bald::MouseButtonReleasedEvent>(Bald::HandleType::SYNC, [this](const MouseButtonReleasedEvent& e) { OnMouseButtonReleasedEvent(e); });
        m_EventManager.Subscribe<Bald::MouseScrolledEvent>(Bald::HandleType::SYNC, [this](const MouseScrolledEvent& e) { OnMouseScrolledEvent(e); });
        m_EventManager.Subscribe<Bald::MouseMovedEvent>(Bald::HandleType::SYNC, [this](const MouseMovedEvent& e) { OnMouseMovedEvent(e); });

        m_EventManager.Subscribe<Bald::WindowResizedEvent>(Bald::HandleType::SYNC, [this](const WindowResizedEvent& e) { OnWindowResizedEvent(e); });
    }

    void ImGuiLayer::OnDetach() noexcept {}

    void ImGuiLayer::OnUpdate() noexcept {
        static float sTime = 0.0f;
        static bool show = true;

        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::GetApplication();
        io.DisplaySize = ImVec2(static_cast<float>(app.GetWindow()->GetWidth()), static_cast<float>(app.GetWindow()->GetHeight()));

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        auto time = static_cast<float>(glfwGetTime());
        io.DeltaTime = sTime > 0.0f ? (time - sTime) : (1.0f / 60.0f);
        sTime = time;

        ImGui::ShowDemoWindow(&show);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::OnKeyPressedEvent([[maybe_unused]] const KeyPressedEvent& e) {
        [[maybe_unused]] ImGuiIO& io = ImGui::GetIO();
        io.KeysDown[e.GetKeyCode()] = true;

        io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
        io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
        io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
        io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
    }

    void ImGuiLayer::OnKeyTypedEvent([[maybe_unused]] const KeyTypedEvent& e) {
        [[maybe_unused]] ImGuiIO& io = ImGui::GetIO();
        io.AddInputCharacter(static_cast<unsigned short>(e.GetKeyCode()));
    }

    void ImGuiLayer::OnKeyReleasedEvent([[maybe_unused]] const KeyReleasedEvent& e) {
        [[maybe_unused]] ImGuiIO& io = ImGui::GetIO();
        io.KeysDown[e.GetKeyCode()] = false;
    }

    void ImGuiLayer::OnMouseButtonPressedEvent(const MouseButtonPressedEvent& e) {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[e.GetKeyCode()] = true;
    }

    void ImGuiLayer::OnMouseButtonReleasedEvent(const MouseButtonReleasedEvent& e) {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[e.GetKeyCode()] = false;
    }

    void ImGuiLayer::OnMouseScrolledEvent(const MouseScrolledEvent& e) {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseWheel += static_cast<float>(e.GetOffsetY());
        io.MouseWheelH += static_cast<float>(e.GetOffsetX());
    }

    void ImGuiLayer::OnMouseMovedEvent(const MouseMovedEvent& e) {
        ImGuiIO& io = ImGui::GetIO();
        io.MousePos = ImVec2(static_cast<float>(e.GetX()), static_cast<float>(e.GetY()));
    }

    void ImGuiLayer::OnWindowResizedEvent([[maybe_unused]] const WindowResizedEvent& e) {
        [[maybe_unused]] ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(static_cast<float>(e.GetWidth()), static_cast<float>(e.GetHeight()));
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
    }

}
