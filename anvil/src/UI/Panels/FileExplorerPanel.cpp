#include "FileExplorerPanel.hpp"

// --- ImGui ---
#include <imgui.h>



anvil::FileExplorerPanel::FileExplorerPanel(const std::string& dir) : 
    ImGuiPanel("File Explorer"),
    m_Directory(dir)
{

}

void anvil::FileExplorerPanel::onPanelEnter()
{

}

void anvil::FileExplorerPanel::onPanelExit()
{

}

void anvil::FileExplorerPanel::onPanelUpdate(const rle::time::step_ms delta)
{

}

void anvil::FileExplorerPanel::onDraw(rle::Renderer2D& renderer)
{

}

void anvil::FileExplorerPanel::onImGuiDraw()
{
    if (ImGui::Begin(name().c_str()))
    {
        ImGui::Text("%s", m_Directory.c_str());
        

        ImGui::End();
    }
}
