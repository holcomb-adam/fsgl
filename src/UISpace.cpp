#include "fsgl/UI/UISpace.hpp"

// --- fsgl ---
#include "fsgl/Rendering/Renderer2D.hpp"



const std::vector<std::unique_ptr<fsgl::Panel>> &fsgl::UISpace::getPanels() const
{
    return m_Panels;
}

void fsgl::UISpace::setBoundingSize(std::uint32_t winw, std::uint32_t winh)
{
    m_Width = winw;
    m_Height = winh;
}

void fsgl::UISpace::addPanel(Panel* panel)
{
    auto& uptr = m_Panels.emplace_back(panel);
    onAddPanel(uptr);
    panel->onPanelEnter();
}

void fsgl::UISpace::updatePanels(time::step_ms delta)
{
    for (auto& panel : m_Panels)
        panel->onPanelUpdate(delta);
}

void fsgl::UISpace::draw(Renderer2D& renderer)
{
    onUIDraw();

    for (auto& panel : m_Panels)
        panel->onPanelDraw(renderer);
}
