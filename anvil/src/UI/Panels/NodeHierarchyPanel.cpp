#include "NodeHierarchyPanel.hpp"

// --- ImGui ---
#include <imgui.h>



anvil::NodeHierarchyPanel::NodeHierarchyPanel(std::weak_ptr<rle::Node> top_node, const std::function<void(rle::Node*)>& selection_callback) :
    ImGui_Panel("Node Hierarchy"),
    m_Top(std::move(top_node)),
    m_SelectionCallback(selection_callback)
{

}

void anvil::NodeHierarchyPanel::onPanelEnter()
{

}

void anvil::NodeHierarchyPanel::onPanelExit()
{
    
}

void anvil::NodeHierarchyPanel::onPanelUpdate(const rle::time::step_ms delta)
{
    if (m_CallbackSignal)
    {
        m_SelectionCallback(m_Selected);
        m_CallbackSignal = false;
    }
}

void anvil::NodeHierarchyPanel::onDraw(rle::Renderer2D& renderer)
{

}

void anvil::NodeHierarchyPanel::onImGuiBegin()
{
    // Lambda for recursively drawing the tree of nodes
    std::function<void(rle::Node*)> recursive_draw_tree_node =
    [&recursive_draw_tree_node, &selected = m_Selected, &signal = m_CallbackSignal](rle::Node* node)
    {
        // Set flags for the tree nodes
        const auto& children = node->getChildren();
        ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow;
        if (children.empty())
            flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_Bullet;
        if (selected && selected->UID == node->UID)
            flags |= ImGuiTreeNodeFlags_Selected;

        if (ImGui::TreeNodeEx((void*)node->UID.raw(), flags, "%s", node->getName().c_str()))
        {
            if (ImGui::IsItemClicked() && !ImGui::IsItemToggledOpen())
            {
                selected = node;
                signal = true;
            }
            for (auto& child : children)
                recursive_draw_tree_node(child.get());
            ImGui::TreePop();
        }
    };
    recursive_draw_tree_node(m_Top.lock().get());
}
