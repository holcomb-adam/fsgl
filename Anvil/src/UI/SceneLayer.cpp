#include "SceneLayer.hpp"

// --- External ---
#include <glm/gtc/matrix_transform.hpp>
#include <ImGui/imgui.h>
#include <ImGui/imgui_internal.h>

// --- RLE ---
#include <RLE/Core/Engine.h>
#include <RLE/Core/Input.hpp>
#include <RLE/Rendering/RenderCommands.hpp>
#include <RLE/Scene/Node/2D/ShapeNode.hpp>
#include <RLE/Resources/CommonShapes.hpp>



anvil::SceneLayer::SceneLayer() :
	rle::Layer("Empty Scene")
{

}

void anvil::SceneLayer::onEnter()
{
	// ---------------------------
	// --- Setup the rendering ---
	// ---------------------------

	// Retrieve the window we are rendering to
	const auto& win = rle::Engine::get()->window();

	// Initialize viewport data
	m_ViewportSize = { win->width(), win->height() };
	m_ViewportAspect = static_cast<float>(m_ViewportSize.x) /
		static_cast<float>(m_ViewportSize.y);

	// Create a frame buffer object
	m_FrameBuffer = rle::factory<rle::FrameBuffer>::create(win->width(), win->height());



	// --------------------------------
	// --- Setup Graphics and Scene ---
	// --------------------------------

	// Create a camera
	m_Camera = rle::factory<rle::Camera>::make_orthographic(
		-m_ViewportAspect,
		m_ViewportAspect,
		-1.0f,
		1.0f);

	// Set the scene to the root node as default if the node isnt already set
	if (!m_SceneNode)
		m_SceneNode = rle::Node::getRoot();



	// - TEMP -
	// Set up scene node to render a simple square
	auto* shape_node = new rle::ShapeNode();
	shape_node->setShape(rle::res::makeRect());
	m_SceneNode->addNode(shape_node);
}

void anvil::SceneLayer::onExit()
{

}

void anvil::SceneLayer::onUpdate(const rle::time::step_ms delta)
{
	// -----------------------------
	// --- Update rendering info ---
	// -----------------------------

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

			// Update the camera
			m_Camera->setProjectionMatrix(glm::ortho(-m_ViewportAspect, m_ViewportAspect, -1.0f, 1.0f));

			// Update the frame buffer update texture
			m_FrameBuffer->resizeTexture(m_ViewportSize.x, m_ViewportSize.y);
		}
	}



	// -------------------------
	// --- Handle User Input ---
	// -------------------------

	// Camera information
	const auto& cam_pos = m_Camera->position();
	const auto cam_velocity = m_CameraSpeed * delta.count();

	// Handle keyboard key states
	if (rle::input::isKeyPressed(rle::KeyCode::W))
		m_Camera->setPosition(cam_pos + glm::vec3{          0.0f,  cam_velocity, 0.0f });
	if (rle::input::isKeyPressed(rle::KeyCode::S))
		m_Camera->setPosition(cam_pos + glm::vec3{          0.0f, -cam_velocity, 0.0f });
	if (rle::input::isKeyPressed(rle::KeyCode::A))
		m_Camera->setPosition(cam_pos + glm::vec3{ -cam_velocity,          0.0f, 0.0f });
	if (rle::input::isKeyPressed(rle::KeyCode::D))
		m_Camera->setPosition(cam_pos + glm::vec3{  cam_velocity,          0.0f, 0.0f });
}

void anvil::SceneLayer::onRender(rle::Renderer& renderer) const
{
	// -----------------------
	// --- Scene rendering ---
	// -----------------------
	
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
	renderer.beginScene(m_Camera);

	// Submit scene for rendering
	if (m_SceneNode)
		renderer.submit(*m_SceneNode);

	// End the rendering scene
	renderer.endScene();

	// Unbind the FBO
	m_FrameBuffer->unbind();



	// -------------------
	// --- UI rendering --
	// -------------------

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
