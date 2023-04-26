#include "EditorState.hpp"

// --- Anvil ---
#include "../UI/ImGui/ImGuiDemoPanel.hpp"
#include "../UI/Panels/DeveloperPanel.hpp"
#include "../UI/Panels/FileExplorerPanel.hpp"
#include "../UI/Panels/NodeHierarchyPanel.hpp"
#include "../UI/Panels/NodeInspectorPanel.hpp"
#include "../UI/Panels/SceneEditorPanel.hpp"


// --- Testing ---
#include <RLE/Node/Aspects/Render2D.hpp>
#include <RLE/Node/Aspects/Shape2D.hpp>
#include <RLE/Node/Aspects/Transform2D.hpp>
#include <RLE/Resources/CommonShapes.hpp>



void anvil::EditorState::onStateEnter()
{
    m_ImGuiRenderer.init();

    m_GraphicsHandle = rle::GraphicsHandle::make();
    m_GraphicsHandle->setClearColor(SCREEN_CLEAR_COLOR);

    // Set the scene to the root node as default if the node isnt already set
    if (!m_SceneNode)
        m_SceneNode = rle::Node::getRoot();

    const auto& win = rle::Engine::get()->getWindow();
    m_DockSpace.setBoundingSize(win->width(), win->height());
    m_DockSpace.addPanel(new DeveloperPanel());
    m_DockSpace.addPanel(new ImGuiDemoPanel());
    m_DockSpace.addPanel(new SceneEditorPanel(m_SceneNode));
    m_DockSpace.addPanel(new NodeHierarchyPanel(m_SceneNode, std::bind(&EditorState::slot_onNodeSelect, this, std::placeholders::_1)));
    m_DockSpace.addPanel(new NodeInspectorPanel(m_SceneNode));
    m_DockSpace.addPanel(new FileExplorerPanel("./"));



    // - TEMP -
    // Set up scene node to render a simple square
    auto* shape_node = new rle::Node();
    shape_node->addComponent<rle::Render2D>();
    shape_node->addComponent<rle::Transform2D>();
    shape_node->addComponent<rle::Shape2D>().setGeometry(rle::res::makeRect());
    m_SceneNode->addNode(shape_node);
}

void anvil::EditorState::onStateExit()
{

}

void anvil::EditorState::onStateUpdate(const rle::time::step_ms delta)
{
    m_ImGuiRenderer.update(delta);
    m_DockSpace.updatePanels(delta);

    // Clear any current rendering
    m_GraphicsHandle->bind();
    m_GraphicsHandle->clear();

    m_ImGuiRenderer.begin();

    m_DockSpace.draw(m_Renderer2D);

    m_ImGuiRenderer.end();
}

void anvil::EditorState::slot_onNodeSelect(rle::Node* node)
{
    
}
