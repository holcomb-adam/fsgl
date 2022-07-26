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

void rle::ImGuiLayer::onUpdate(const float delta)
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui::NewFrame();

	auto& io = ImGui::GetIO();
	Engine* engine = Engine::get();
	io.DisplaySize = ImVec2(engine->window()->width(), engine->window()->height());

	io.DeltaTime = delta;

	static bool show = true;
	ImGui::ShowDemoWindow(&show);

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
