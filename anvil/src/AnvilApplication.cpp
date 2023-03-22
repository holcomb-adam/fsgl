#include "AnvilApplication.hpp"

// --- Anvil ---
#include "UI/DebuggerLayer.hpp"
#include "UI/DockingLayer.hpp"
#include "UI/SceneLayer.hpp"
#include "UI/ImGui/ImGuiLayer.hpp"



anvil::AnvilApplication::AnvilApplication() :
	rle::Engine(
		rle::Window::Properties
		{
			.title = "RLE Anvil v0.0.0",
			.w = 1280,
			.h = 960
		})
{

}

std::size_t anvil::AnvilApplication::init()
{
	// Initialize the ImGui renderer
	m_ImGuiRenderer.init();

	// Push layers onto the stack
	push(new DockingLayer());
	pushOverlay(new DebuggerLayer());
	push(new SceneLayer());

	// - ImGui Debug - 
	//push(new ImGuiLayer());

	return 0;
}

void anvil::AnvilApplication::onUpdate(const rle::time::step_ms delta)
{
	m_ImGuiRenderer.update(delta);
}

void anvil::AnvilApplication::onPreRender()
{
	m_ImGuiRenderer.begin();
}

void anvil::AnvilApplication::onRender(rle::Renderer& renderer)
{

}

void anvil::AnvilApplication::onPostRender()
{
	m_ImGuiRenderer.end();
}