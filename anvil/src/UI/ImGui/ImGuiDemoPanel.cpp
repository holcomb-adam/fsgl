#include "ImGuiDemoPanel.hpp"

// --- ImGui ---
#include <imgui/imgui.h>



anvil::ImGuiDemoPanel::ImGuiDemoPanel() : 
    ImGuiPanel("ImGui Demo Panel")
{

}

void anvil::ImGuiDemoPanel::onPanelEnter()
{

}

void anvil::ImGuiDemoPanel::onPanelExit()
{

}

void anvil::ImGuiDemoPanel::onPanelUpdate(const rle::time::step_ms delta)
{

}

void anvil::ImGuiDemoPanel::onDraw(rle::Renderer2D& renderer)
{

}

void anvil::ImGuiDemoPanel::onImGuiDraw()
{
    static bool show = true;
    ImGui::ShowDemoWindow(&show);
}
