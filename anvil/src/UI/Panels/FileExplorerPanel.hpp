#pragma once

// --- Anvil ---
#include "../ImGui_Panel.hpp"



namespace anvil
{
    class FileExplorerPanel : public ImGui_Panel
    {
    public:
        FileExplorerPanel(const std::string& dir);



    private:
        virtual void onPanelEnter() override;
        virtual void onPanelExit() override;
        virtual void onPanelUpdate(const rle::time::step_ms delta) override;

        virtual void onDraw(rle::Renderer2D& renderer) override;
        virtual void onImGuiBegin() override;



    private:
        std::string m_Directory;
    };
}
