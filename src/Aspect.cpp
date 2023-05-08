#include "fsgl_pch.hpp"
#include "fsgl/Node/Aspect.hpp"

// --- fsgl ---
#include "fsgl/Node/Node.hpp"



fsgl::Node& fsgl::Aspect::getNode()
{
    /// @bug Need to throw exceptions here if the node doesnt have a parent
    return *m_Owner;
}

const fsgl::Node& fsgl::Aspect::getNode() const
{
    /// @bug Need to throw exceptions here if the node doesnt have a parent
    return *m_Owner;
}

void fsgl::Aspect::onInit()
{
    
}

void fsgl::Aspect::onUpdate(const time::step_ms delta)
{
    
}
