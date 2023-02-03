#include "AnvilApplication.h"

// --- Anvil ---
#include "UI/DebuggerLayer.hpp"
#include "UI/DockingLayer.h"
#include "UI/SceneLayer.hpp"
#include "UI/ImGui/ImGuiLayer.h"


static auto* root = rle::Node::getRoot();



// Define RLE's creation instance
RLE_INSTANCE(anvil::AnvilApplication)



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

	// - ImGUI Debug - 
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
