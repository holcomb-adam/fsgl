#include "EditorState.hpp"

// --- RLE ---
#include "RLE/Rendering/RenderCommands.hpp"

// --- Anvil ---
#include "../UI/ImGui/ImGuiDemoPanel.hpp"
#include "../UI/Panels/DeveloperPanel.hpp"
#include "../UI/Panels/SceneEditorPanel.hpp"



void anvil::EditorState::onStateEnter()
{
    m_ImGuiRenderer.init();

    auto* developer_panel = new DeveloperPanel();
    m_Docker.addPanel(developer_panel);
    m_Docker.addPanel(new ImGuiDemoPanel());
    m_Docker.addPanel(new SceneEditorPanel());
}

void anvil::EditorState::onStateExit()
{

}

void anvil::EditorState::onStateUpdate(const rle::time::step_ms delta)
{
    m_ImGuiRenderer.update(delta);
    m_Docker.updatePanels(delta);

    // --- Rendering ---
    // Clear any current rendering
    rle::RenderCommands::setClearColor({ 1.0f, 0.0f, 1.0f, 1.0f });
    rle::RenderCommands::clear();

    m_ImGuiRenderer.begin();

    m_Docker.drawPanels(m_Renderer2D);

    m_ImGuiRenderer.end();
}
