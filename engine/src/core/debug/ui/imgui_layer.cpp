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

        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        Application& app = Application::GetApplication();
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
        static bool my_tool_active = true;
        static float my_color[4];

        ImGui::ShowDemoWindow(&show);

        ImGui::Begin("My First Tool", &my_tool_active, ImGuiWindowFlags_MenuBar);
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
                if (ImGui::MenuItem("Save", "Ctrl+S"))   { /* Do stuff */ }
                if (ImGui::MenuItem("Close", "Ctrl+W"))  { my_tool_active = false; }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }

        // Edit a color (stored as ~4 floats)
        ImGui::ColorEdit4("Color", my_color);

        // Plot some values
        const float my_values[] = { 0.2f, 0.1f, 1.0f, 0.5f, 0.9f, 2.2f };
        ImGui::PlotLines("Frame Times", my_values, IM_ARRAYSIZE(my_values));

        // Display contents in a scrolling region
        ImGui::TextColored(ImVec4(1,1,0,1), "Important Stuff");
        ImGui::BeginChild("Scrolling");
        for (int n = 0; n < 50; n++)
            ImGui::Text("%04d: Some text", n);
        ImGui::EndChild();
        ImGui::End();
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
