#include "AnvilApplication.h"

// --- Anvil ---
#include "UI/DockingLayer.h"
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
	// Cool color: (0.57, 0.34, 0.78, 1.0)
	
	// Our Vertex shader
	const std::string vert_src =
		R"(
			#version 330 core

			layout(location = 0) in vec3 pos;
			layout(location = 1) in vec4 i_color;
			out vec4 o_color;

			void main()
			{
				gl_Position = vec4(pos, 1.0);
				o_color = i_color;
			}
		)";

	// ... and our fragment shader
	const std::string frag_src =
		R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			in vec4 o_color;

			void main()
			{
				color = o_color;
			}
		)";

	m_Shader = rle::factory<rle::Shader>::create(vert_src, frag_src);
}

std::size_t anvil::AnvilApplication::init()
{
	// Initialize the ImGui renderer
	m_ImGuiRenderer.init();

	// Disabled for rendering system setup
	//push(new DockingLayer());
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

	m_Shader->bind();
}

void anvil::AnvilApplication::onRender() const
{

}

void anvil::AnvilApplication::onPostRender()
{
	m_ImGuiRenderer.end();
}
