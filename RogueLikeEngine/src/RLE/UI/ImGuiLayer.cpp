#include "RLEpch.h"
#include "ImGuiLayer.h"

// External Library includes
#include <ImGui/imgui.h>
#include <ImGui/backends/imgui_impl_glfw.h>
#include <ImGui/backends/imgui_impl_opengl3.h>

// RLE Library includes
#include "RLE/Core/Engine.h"



rle::ImGuiLayer::ImGuiLayer() : 
	Layer("ImGuiLayer")
{

}

void rle::ImGuiLayer::onEnter()
{
	// Initialize ImGui
	ImGui::CreateContext();
	auto& io = ImGui::GetIO();

	// Retrieve Engine instance
	Engine * engine = Engine::get();

	// Set io flags
	//im_io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Enable ImGui Docking
	io.DisplaySize = ImVec2(engine->window()->width(), engine->window()->height());

	auto* glfw_win = static_cast<GLFWwindow*>(engine->window()->nativeHandle());

	// Initialize ImGui backends
	ImGui_ImplGlfw_InitForOpenGL(glfw_win, true);
	ImGui_ImplOpenGL3_Init("#version 460");
}

void rle::ImGuiLayer::onExit()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void rle::ImGuiLayer::onUpdate(const time::step_ms delta)
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui::NewFrame();

	auto& io = ImGui::GetIO();
	Engine* engine = Engine::get();
	io.DisplaySize = ImVec2(engine->window()->width(), engine->window()->height());

	const auto delta_sec = std::chrono::duration_cast<time::step_sec>(delta);
	const auto d = delta_sec.count() > 0.0f ? delta_sec.count() : 1.0f / 60.0f;
	io.DeltaTime = d;

	static bool show = true;
	ImGui::ShowDemoWindow(&show);

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
