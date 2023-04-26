#include "NodeInspectorPanel.hpp"

// --- ImGui ---
#include <imgui.h>



anvil::NodeInspectorPanel::NodeInspectorPanel(std::weak_ptr<rle::Node> inspect_node) : 
    ImGuiPanel("Node Inspector"),
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

void anvil::NodeInspectorPanel::onImGuiDraw()
{
    // Begin an imgui window
    if (ImGui::Begin(name().c_str()))
    {
        ImGui::Text("%s", m_InspectNode.lock()->getName().c_str());
        ImGui::End();
    }
}
