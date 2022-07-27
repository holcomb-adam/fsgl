#include "AnvilApplication.h"

// Anvil includes
#include "UI/ImGuiLayer.h"



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

	push(new ImGuiLayer());

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

void anvil::AnvilApplication::onRender() const
{
}

void anvil::AnvilApplication::onPostRender()
{
	m_ImGuiRenderer.end();
}
