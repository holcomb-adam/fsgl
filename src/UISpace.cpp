#include "RLE/UI/UISpace.hpp"

// --- rle ---
#include "RLE/Rendering/Renderer2D.hpp"



const std::vector<std::unique_ptr<rle::Panel>> &rle::UISpace::getPanels() const
{
    return m_Panels;
}

void rle::UISpace::setBoundingSize(std::uint32_t winw, std::uint32_t winh)
{
    m_Width = winw;
    m_Height = winh;
}

void rle::UISpace::addPanel(Panel* panel)
{
    auto& uptr = m_Panels.emplace_back(panel);
    onAddPanel(uptr);
    panel->onPanelEnter();
}

void rle::UISpace::updatePanels(time::step_ms delta)
{
    for (auto& panel : m_Panels)
        panel->onPanelUpdate(delta);
}

void rle::UISpace::draw(Renderer2D& renderer)
{
    onUIDraw();

    for (auto& panel : m_Panels)
        panel->onPanelDraw(renderer);
}
