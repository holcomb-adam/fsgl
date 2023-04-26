#pragma once

// --- Anvil ---
#include "../ImGui/ImGuiPanel.hpp"



namespace anvil
{
    class FileExplorerPanel : public ImGuiPanel
    {
    public:
        FileExplorerPanel(const std::string& dir);



    private:
        virtual void onPanelEnter() override;
        virtual void onPanelExit() override;
        virtual void onPanelUpdate(const rle::time::step_ms delta) override;

        virtual void onDraw(rle::Renderer2D& renderer) override;
        virtual void onImGuiDraw() override;



    private:
        std::string m_Directory;
    };
}
