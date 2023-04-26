#pragma once

// --- Standard ---
#include <memory>

// --- RLE ---
#include <RLE/Node/Node.hpp>

// --- Anvil ---
#include "../ImGui/ImGuiPanel.hpp"



namespace anvil
{
    class NodeHierarchyPanel : public ImGuiPanel
    {
    public:
        /// @brief 
        /// @param top_node 
        NodeHierarchyPanel(std::weak_ptr<rle::Node> top_node, 
                           const std::function<void(rle::Node*)>& selection_callback);
        ~NodeHierarchyPanel() = default;



    private:
        virtual void onPanelEnter() override;
        virtual void onPanelExit() override;
        virtual void onPanelUpdate(const rle::time::step_ms delta) override;

        virtual void onDraw(rle::Renderer2D& renderer) override;
        virtual void onImGuiDraw() override;



    private:
        std::weak_ptr<rle::Node> m_Top;

        // --- Callback info ---
        std::function<void(rle::Node*)> m_SelectionCallback;
        bool m_CallbackSignal = false; /// @todo This is bad and should be replaced with signals and slots
        rle::Node* m_Selected = nullptr;
    };
}
