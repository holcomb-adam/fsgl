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

void anvil::DockingLayer::onRender(rle::Renderer& renderer) const
{
	// The window
	const auto& win = m_Engine->window();

	// ImGui window data
	static bool open = true;
	static bool fullscreen = true;
	const ImGuiWindowFlags win_flags =
		ImGuiWindowFlags_MenuBar | 
		ImGuiWindowFlags_NoDocking |
		ImGuiWindowFlags_NoTitleBar |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoBringToFrontOnFocus |
		ImGuiWindowFlags_NoNavFocus;

	// ImGui viewport initialization
	const ImGuiViewport* viewport = ImGui::GetMainViewport();
	ImGui::SetNextWindowPos(viewport->WorkPos);
	ImGui::SetNextWindowSize(viewport->WorkSize);
	ImGui::SetNextWindowViewport(viewport->ID);

	// This is the entrance to our main docking window
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0.0f, 0.0f });
	if (ImGui::Begin("Dockspace Test", &open, win_flags))
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
				if (ImGui::MenuItem(""))

				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}

		ImGui::End();
	}
}
