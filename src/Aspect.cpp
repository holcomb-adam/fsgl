#include "RLE/Node/Aspect.hpp"

// --- RLE ---
#include "RLE/Node/Node.hpp"



rle::Node& rle::Aspect::getNode()
{
    /// @bug Need to throw exceptions here if the node doesnt have a parent
    return *m_Owner;
}

const rle::Node& rle::Aspect::getNode() const
{
    /// @bug Need to throw exceptions here if the node doesnt have a parent
    return *m_Owner;
}

void rle::Aspect::onInit()
{
    
}

void rle::Aspect::onUpdate(const time::step_ms delta)
{
    
}
