#include "RLE/UI/Panel.hpp"



rle::Panel::Panel(const std::string& name) :
    m_Name(name)
{

}

void rle::Panel::setSize(const glm::u32vec2& size)
{
    m_Size = size;
}

const std::string &rle::Panel::name() const
{
    return m_Name;
}

const glm::vec2 &rle::Panel::getPosition() const
{
    return m_Position;
}

const glm::u32vec2 &rle::Panel::getSize() const
{
    return m_Size;
}

void rle::Panel::setPosition(const glm::vec2& position)
{
    m_Position = position;
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
