#include "ImGui_DemoPanel.hpp"

// --- ImGui ---
#include <imgui/imgui.h>



anvil::ImGuiDemoPanel::ImGuiDemoPanel() :
    ImGui_Panel("ImGui Demo Panel")
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

void anvil::ImGuiDemoPanel::onPanelDraw(rle::Renderer2D& renderer)
{
    static bool show = true;
    ImGui::ShowDemoWindow(&show);
}

void anvil::ImGuiDemoPanel::onDraw(rle::Renderer2D& renderer)
{

}

void anvil::ImGuiDemoPanel::onImGuiBegin()
{

}
