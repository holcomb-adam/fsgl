#pragma once

// --- RLE ---
#include <RLE/Node/Node.hpp>

// --- Anvil ---
#include "../ImGui_Panel.hpp"



namespace anvil
{
    class NodeInspectorPanel : public ImGui_Panel
    {
    public:
        NodeInspectorPanel(std::weak_ptr<rle::Node> inspect_node);
        ~NodeInspectorPanel() = default;



    private:
        virtual void onPanelEnter() override;
        virtual void onPanelExit() override;
        virtual void onPanelUpdate(const rle::time::step_ms delta) override;
        
        virtual void onDraw(rle::Renderer2D& renderer) override;
        virtual void onImGuiBegin() override;



    private:
        std::weak_ptr<rle::Node> m_InspectNode;
    };
}
