#include "ImGuiRenderer.hpp"

// External Library includes
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>



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

	// Get engine window
	const auto& win = m_Engine->window();

	// Convert our delta time to seconds since ImGui takes delta time in seconds
	const auto delta_sec = std::chrono::duration_cast<rle::time::step_sec>(delta);

	// Update the ImGui data
	const auto adj_delta = delta_sec.count() == 0.0 ? 1.0 / 60.0 : delta_sec.count();
	io.DeltaTime = static_cast<float>(adj_delta);
	io.DisplaySize = ImVec2(static_cast<float>(win->width()),
		static_cast<float>(win->height()));
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
