#include "RLE/Node/Component.hpp"

// --- RLE ---
#include "RLE/Node/Node.hpp"



rle::Node& rle::Component::getNode()
{
    /// @bug Need to throw exceptions here if the node doesnt have a parent
    return *m_Owner;
}

const rle::Node& rle::Component::getNode() const
{
    /// @bug Need to throw exceptions here if the node doesnt have a parent
    return *m_Owner;
}

void rle::Component::onInit()
{
    
}

void rle::Component::onUpdate(const time::step_ms delta)
{
    
}
