//
// Created by blinku on 29.05.19.
//

#include "imgui_layer.h"
#include "imgui.h"

#ifdef TRAVIS
#include "vendor/imgui/examples/imgui_impl_opengl2.h"
#else
#include "vendor/imgui/examples/imgui_impl_opengl3.h"
#endif

#include "vendor/imgui/examples/imgui_impl_glfw.h"
#include "application.h"

#include "GLFW/glfw3.h"

namespace Bald::Debug {

    void ImGuiLayer::OnAttach() noexcept {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
        //io.ConfigViewportsNoAutoMerge = true;
        //io.ConfigViewportsNoTaskBarIcon = true;

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsClassic();

        // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        Application& app = Application::GetApplication();

        // Setup Platform/Renderer bindings
        ImGui_ImplGlfw_InitForOpenGL(app.GetWindow()->GetWindow(), true);

#ifdef TRAVIS
        ImGui_ImplOpenGL2_Init();
#else
        ImGui_ImplOpenGL3_Init("#version 330");
#endif

    }

    void ImGuiLayer::OnDetach() noexcept {
#ifdef TRAVIS
        ImGui_ImplOpenGL2_Shutdown();
#else
        ImGui_ImplOpenGL3_Shutdown();
#endif
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::OnUpdate() noexcept {}

    void ImGuiLayer::OnRender() noexcept {
        static bool show = true;
        ImGui::ShowDemoWindow(&show);
    }

    void ImGuiLayer::Begin() noexcept {
#ifdef TRAVIS
        ImGui_ImplOpenGL2_NewFrame();
#else
        ImGui_ImplOpenGL3_NewFrame();
#endif

        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiLayer::End() noexcept {
        Application& app = Application::GetApplication();

        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(static_cast<float>(app.GetWindow()->GetWidth()), static_cast<float>(app.GetWindow()->GetHeight()));

        ImGui::Render();
#ifdef TRAVIS
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
#else
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
#endif

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }



} // END OF NAMESPACE Bald::Debug
