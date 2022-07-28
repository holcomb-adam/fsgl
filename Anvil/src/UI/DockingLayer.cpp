#include "DockingLayer.h"

// External Library includes
#include <ImGui/imgui.h>

// RLE Library includes
#include <RLE/Debug/Log.h>



anvil::DockingLayer::DockingLayer() : 
	rle::Layer("Docking Layer")
{

}

void anvil::DockingLayer::onEnter()
{
	m_Engine = rle::Engine::get();
	assert(m_Engine);
}

void anvil::DockingLayer::onExit()
{

}

void anvil::DockingLayer::onUpdate(const rle::time::step_ms delta)
{

}

void anvil::DockingLayer::onRender() const
{
	// The window
	const auto& win = m_Engine->window();

	// ImGui window data
	static bool open = true;
	const ImGuiWindowFlags dock_win_flags =
		ImGuiWindowFlags_MenuBar |
		ImGuiWindowFlags_NoDocking |
		ImGuiWindowFlags_NoSavedSettings |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoTitleBar |
		ImGuiWindowFlags_NoMove | 
		ImGuiWindowFlags_NoBringToFrontOnFocus | 
		ImGuiWindowFlags_NoNavFocus;

	// This is the entrance to our main docking window
	if (ImGui::Begin("Test", &open, dock_win_flags))
	{
		ImGui::SetWindowSize(ImVec2(win->width(), win->height()));
		ImGui::SetWindowPos(ImVec2(0.0f, 0.0f));

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

			ImGui::EndMenuBar();
		}

		ImGui::End();
	}
}
