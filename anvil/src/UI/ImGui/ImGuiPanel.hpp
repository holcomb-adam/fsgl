#pragma once

// --- imgui ---
#include <imgui.h>

// --- RLE ---
#include <RLE/UI/Panel.hpp>

// --- Anvil ---
#include "../../Utils.hpp"



namespace anvil
{
    class ImGuiPanel : public rle::Panel
    {
    public:
        inline ImGuiPanel(const std::string& name) :
            rle::Panel(name) { }
        virtual void onDraw(rle::Renderer2D& renderer) = 0;
        virtual void onImGuiDraw() = 0;

    private:
        inline virtual void onPanelDraw(rle::Renderer2D& renderer) override
        {
            onDraw(renderer);
            ImGui::SetNextWindowSize(to_imvec(getSize()));
            ImGui::SetNextWindowPos(to_imvec(getPosition()));
            onImGuiDraw();
        }
    };
    
}
