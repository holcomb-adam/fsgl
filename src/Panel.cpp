#include "RLE/UI/Panel.hpp"



rle::Panel::Panel(const std::string& name) :
    m_Name(name)
{
}

const std::string& rle::Panel::name() const
{
    return m_Name;
}

void rle::Panel::enter()
{
    onPanelEnter();
}

void rle::Panel::update(const time::step_ms delta)
{
    onPanelUpdate(delta);
}

void rle::Panel::draw(Renderer2D& renderer)
{
    onPanelDraw(renderer);
}

void rle::Panel::onPanelEnter()
{
}

void rle::Panel::onPanelExit()
{
}
