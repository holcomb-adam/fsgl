#include "ImGuiDemoPanel.hpp"

// --- ImGui ---
#include <imgui/imgui.h>



anvil::ImGuiDemoPanel::ImGuiDemoPanel() : 
	rle::Panel("ImGui Demo Panel")
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
