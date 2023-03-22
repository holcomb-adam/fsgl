#include "RLE/UI/Docker.hpp"

// --- RLE ---
#include "RLE/Rendering/Renderer2D.hpp"


void rle::Docker::addPanel(Panel* panel)
{
    m_Panels.emplace_back(panel)->enter();
}

void rle::Docker::updatePanels(const time::step_ms delta)
{
    for (auto& panel : m_Panels)
        panel->update(delta);
}

void rle::Docker::drawPanels(Renderer2D& renderer)
{
    for (auto& panel : m_Panels)
        panel->draw(renderer);
}