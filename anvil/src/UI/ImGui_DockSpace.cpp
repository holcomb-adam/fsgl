#include "ImGui_DockSpace.hpp"

// --- imgui ---
#include <imgui/imgui.h>

// --- rle --- 
#include <RLE/Core/Engine.hpp>
#include <RLE/Debug/Log.hpp>



void anvil::ImGui_DockSpace::onAddPanel(std::unique_ptr<rle::Panel>& panel)
{
    m_FocusedPanel = panel.get();
}

void anvil::ImGui_DockSpace::onUIDraw()
{
    static bool open = true;
    ImGuiWindowFlags flags = 
        ImGuiWindowFlags_MenuBar |
        ImGuiWindowFlags_NoDocking |
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoBringToFrontOnFocus |
        ImGuiWindowFlags_NoNavFocus;

    ImGui::SetNextWindowPos({ 0.0f, 0.0f });
    ImGui::SetNextWindowSize({ static_cast<float>(m_Width), static_cast<float>(m_Height) });
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0.0f, 0.0f });
    if (ImGui::Begin("Dockspace Test", &open, flags))
    {
        ImGui::PopStyleVar();
        auto& io = ImGui::GetIO();
        if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
        {
            const auto id = ImGui::GetID("Anvil Dockspace");
            ImGui::DockSpace(id, { 0.0f, 0.0f });
        }

        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Test"))
                    RLE_TRACE("Menu item 'Test' clicked!");
                    
                ImGui::Separator();

                if (ImGui::MenuItem("Exit"))
                    rle::Engine::get()->exit();

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Edit"))
            {
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("View"))
            {
                ImGui::EndMenu();
            }

            ImGui::EndMenuBar();
        }

        ImGui::End();
    }
}
