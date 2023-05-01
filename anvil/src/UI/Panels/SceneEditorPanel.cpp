#include "SceneEditorPanel.hpp"

// --- ImGui ---
#include <imgui.h>
#include <imgui_internal.h>

// --- RLE ---
#include <RLE/Core/Engine.hpp>
#include <RLE/Core/Input.hpp>
#include <RLE/Rendering/Renderer2D.hpp>



anvil::SceneEditorPanel::SceneEditorPanel(std::weak_ptr<rle::Node> scene_node) :
    ImGui_Panel("Empty Scene"),
    m_SceneNode(std::move(scene_node))
{

}

void anvil::SceneEditorPanel::onPanelEnter()
{
    // Retrieve the window we are rendering to
    const auto& win = rle::Engine::get()->getWindow();

    // Initialize viewport data
    m_ViewportSize = { win->width(), win->height() };
    //m_View->setRotation(45.0f);

    // Setup graphics
    m_FrameBuffer = rle::factory<rle::FrameBuffer>::create(win->width(), win->height());
    m_GraphicsHandle = rle::GraphicsHandle::make();
    m_GraphicsHandle->setClearColor({RLE_BUFFER_CLEAR_COLOR, 1.0f});
    m_GraphicsHandle->setFrameBuffer(m_FrameBuffer);
}

void anvil::SceneEditorPanel::onPanelExit()
{

}

void anvil::SceneEditorPanel::onPanelUpdate(const rle::time::step_ms delta)
{
    // Get the ImGui window
    const auto imgui_win = ImGui::FindWindowByName(getName().c_str());
    if (imgui_win)
    {
        // If the viewport has been resized, then the camera and FBO must be updated
        if (imgui_win->Size.x != m_ViewportSize.x || imgui_win->Size.y != m_ViewportSize.y)
        {
            m_ViewportSize = { imgui_win->Size.x, imgui_win->Size.y };
            m_FrameBuffer->resizeTexture(imgui_win->Size.x, imgui_win->Size.y);
            m_View.setSize(m_ViewportSize.x, m_ViewportSize.y);
        }
    }

    // --- Handle Panel Inputs ---
    if (rle::input::isKeyPressed(rle::KeyCode::W))
        m_View.move({0.0f, -0.01f});
    if (rle::input::isKeyPressed(rle::KeyCode::S))
        m_View.move({0.0f, 0.01f});
    if (rle::input::isKeyPressed(rle::KeyCode::A))
        m_View.move({0.01f, 0.0f});
    if (rle::input::isKeyPressed(rle::KeyCode::D))
        m_View.move({-0.01f, 0.0f});
}

void anvil::SceneEditorPanel::onDraw(rle::Renderer2D& renderer)
{
    // Draw the node tree
    renderer.beginScene(m_GraphicsHandle, m_View, m_ViewportSize);
    if (!m_SceneNode.expired())
        renderer.draw(*m_SceneNode.lock());
    renderer.endScene();
}

void anvil::SceneEditorPanel::onImGuiBegin()
{
    const auto& cursor_pos = ImGui::GetCursorScreenPos();

    // Create a child window. This will make the rendered scene to fit nicely 
    // and uniformly into the window
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
}
