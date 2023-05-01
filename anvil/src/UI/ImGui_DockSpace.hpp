#pragma once

// --- rle ---
#include <RLE/UI/UISpace.hpp>



namespace anvil
{
    class ImGui_DockSpace : public rle::UISpace
    {
    private:
        virtual void onAddPanel(std::unique_ptr<rle::Panel>& panel) override;
        virtual void onUIDraw() override;
    };
}
