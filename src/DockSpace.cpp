#include "RLE/UI/DockSpace.hpp"

// --- RLE ---
#include "RLE/Rendering/Renderer2D.hpp"



void rle::DockSpace::setBoundingSize(std::uint32_t winw, std::uint32_t winh)
{
    m_Width = winw;
    m_Height = winh;
}

void rle::DockSpace::addPanel(Panel* panel)
{
    m_Panels.emplace_back(panel);
    
    // Very rudimentary dockspace. Docks panels spanning horizontally
    glm::u32vec2 size = { m_Width / static_cast<std::size_t>(m_Panels.size()), m_Height};
    for (std::size_t i = 0; i < m_Panels.size(); i++)
    {
        m_Panels[i]->setSize(size);
        m_Panels[i]->setPosition({ size.x * i, 0.0f });
    }
    panel->enter();
}

void rle::DockSpace::updatePanels(const time::step_ms delta)
{
    for (auto& panel : m_Panels)
        panel->update(delta);
}

void rle::DockSpace::draw(Renderer2D& renderer)
{
    for (auto& panel : m_Panels)
        panel->draw(renderer);
}
