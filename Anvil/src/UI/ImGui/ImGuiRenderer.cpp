#include "ImGuiRenderer.h"

// External Library includes
#include <ImGui/imgui.h>
#include <ImGui/backends/imgui_impl_glfw.h>
#include <ImGui/backends/imgui_impl_opengl3.h>



anvil::ImGuiRenderer::~ImGuiRenderer()
{
	// Destroy ImGui
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void anvil::ImGuiRenderer::init()
{
	// Create the ImGui context
	ImGui::CreateContext();

	// Get access to the engine
	m_Engine = rle::Engine::get();
	assert(m_Engine);

	// Setup ImGui, set flags
	auto& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Enable ImGui Docking

	// Initialize the required ImGui backends
	assert(ImGui_ImplGlfw_InitForOpenGL(
		static_cast<GLFWwindow*>(m_Engine->window()->nativeHandle()),
		true));
	assert(ImGui_ImplOpenGL3_Init("#version 460"));

	// Set ImGui Color style
	ImGui::StyleColorsDark();
}

void anvil::ImGuiRenderer::update(const rle::time::step_ms delta)
{
	// Get the ImGui io
	auto& io = ImGui::GetIO();

	// Convert our delta time to seconds since ImGui takes delta time in seconds
	const auto delta_sec = std::chrono::duration_cast<rle::time::step_sec>(delta);

	// Update the ImGui data
	io.DeltaTime = delta_sec.count();
	io.DisplaySize = ImVec2(m_Engine->window()->width(), m_Engine->window()->height());
}

void anvil::ImGuiRenderer::begin() const
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui::NewFrame();
}

void anvil::ImGuiRenderer::end() const
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
