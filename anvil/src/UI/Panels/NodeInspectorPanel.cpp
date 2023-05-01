#include "NodeInspectorPanel.hpp"

// --- ImGui ---
#include <imgui.h>



anvil::NodeInspectorPanel::NodeInspectorPanel(std::weak_ptr<rle::Node> inspect_node) : 
    ImGui_Panel("Node Inspector"),
    m_InspectNode(std::move(inspect_node))
{

}

void anvil::NodeInspectorPanel::onPanelEnter()
{

}

void anvil::NodeInspectorPanel::onPanelExit()
{

}

void anvil::NodeInspectorPanel::onPanelUpdate(const rle::time::step_ms delta)
{

}

void anvil::NodeInspectorPanel::onDraw(rle::Renderer2D& renderer)
{
    
}

void anvil::NodeInspectorPanel::onImGuiBegin()
{
    ImGui::Text("%s", m_InspectNode.lock()->getName().c_str());
}
