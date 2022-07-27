#include "RLEpch.h"
#include "ImGuiLayer.h"

// External Library includes
#include <ImGui/imgui.h>

// RLE Library includes
#include "RLE/Core/Engine.h"



anvil::ImGuiLayer::ImGuiLayer() :
	rle::Layer("ImGuiLayer")
{

}

void anvil::ImGuiLayer::onEnter()
{

}

void anvil::ImGuiLayer::onExit()
{

}

void anvil::ImGuiLayer::onUpdate(const rle::time::step_ms delta)
{

}

void anvil::ImGuiLayer::onRender() const
{
	static bool show = true;
	ImGui::ShowDemoWindow(&show);
}
