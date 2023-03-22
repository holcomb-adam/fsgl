#include "SceneEditorPanel.hpp"

// --- ImGui ---
#include <imgui.h>
#include <imgui_internal.h>

// --- RLE ---
#include <RLE/Core/Engine.hpp>
#include <RLE/Node/Node.hpp>
#include <RLE/Node/Components/Render2D.hpp>
#include <RLE/Node/Components/Shape2D.hpp>
#include <RLE/Node/Components/Transform2D.hpp>
#include <RLE/Rendering/RenderCommands.hpp>
#include <RLE/Rendering/Renderer2D.hpp>
#include <RLE/Resources/CommonShapes.hpp>



anvil::SceneEditorPanel::SceneEditorPanel() :
	rle::Panel("Empty Scene")
{

}

void anvil::SceneEditorPanel::onPanelEnter()
{
	// Retrieve the window we are rendering to
	const auto& win = rle::Engine::get()->getWindow();

	// Initialize viewport data
	m_ViewportSize = { win->width(), win->height() };
	m_ViewportAspect = static_cast<float>(m_ViewportSize.x) /
		static_cast<float>(m_ViewportSize.y);

	// Create a frame buffer object
	m_FrameBuffer = rle::factory<rle::FrameBuffer>::create(win->width(), win->height());

	// Set the scene to the root node as default if the node isnt already set
	if (!m_SceneNode)
		m_SceneNode = rle::Node::getRoot();



	// - TEMP -
	// Set up scene node to render a simple square

	auto* shape_node = new rle::Node();
	shape_node->addComponent<rle::Render2D>();
	shape_node->addComponent<rle::Transform2D>();
	shape_node->addComponent<rle::Shape2D>().setGeometry(rle::res::makeRect());
	m_SceneNode->addNode(shape_node);
}

void anvil::SceneEditorPanel::onPanelExit()
{

}

void anvil::SceneEditorPanel::onPanelUpdate(const rle::time::step_ms delta)
{
	// Get the ImGui window
	const auto imgui_win = ImGui::FindWindowByName(name().c_str());

	// Check if the ImGui window exists
	if (imgui_win)
	{
		// If the viewport has been resized, then the camera and FBO must be updated
		if (imgui_win->Size.x != m_ViewportSize.x || imgui_win->Size.y != m_ViewportSize.y)
		{
			// Update the viewport
			m_ViewportPosition = { imgui_win->Pos.x, imgui_win->Pos.y };
			m_ViewportSize = { imgui_win->Size.x, imgui_win->Size.y };
			m_ViewportAspect = static_cast<float>(imgui_win->Size.x) /
				static_cast<float>(imgui_win->Size.y);

			// Update the frame buffer update texture
			m_FrameBuffer->resizeTexture(m_ViewportSize.x, m_ViewportSize.y);
		}
	}
}

void anvil::SceneEditorPanel::onPanelDraw(rle::Renderer2D& renderer)
{
	// Bind the rendering to the frame buffer
	m_FrameBuffer->bind();

	// Clear the frame buffer rendering
	rle::RenderCommands::clear();

	// Set the rendering viewport
	rle::RenderCommands::viewport(
		0,
		0,
		m_ViewportSize.x,
		m_ViewportSize.y);

	// Begin the rendering scene
	renderer.beginScene();

	// Submit scene for rendering
	if (m_SceneNode)
		renderer.draw(*m_SceneNode);

	// End the rendering scene
	renderer.endScene();

	// Unbind the FBO
	m_FrameBuffer->unbind();



	// --- UI rendering ---

	// Begin an ImGui window
	if (ImGui::Begin(name().c_str()))
	{
		// Get the ImGui cursor position
		const auto& cursor_pos = ImGui::GetCursorScreenPos();

		// Create a child window
		// This will make the rendered scene to fit nicely and uniformly into the
		// window
		if (ImGui::BeginChild(ImGui::GetID("Scene View")))
		{
			// Add the rendered scene to the ImGui window draw list
			ImGui::GetWindowDrawList()->AddImage(
				reinterpret_cast<void*>(static_cast<std::size_t>(m_FrameBuffer->texture())), // Need to cast to a larger type first
				cursor_pos,
				{ cursor_pos.x + m_ViewportSize.x, cursor_pos.y + m_ViewportSize.y },
				{ 0, 1 }, // Need to invert the coordinate system
				{ 1, 0 });

			// End the child window
			ImGui::EndChild();
		}

		// End the window
		ImGui::End();
	}
}
