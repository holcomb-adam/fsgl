#include "fsgl_pch.hpp"
#include "fsgl/Node/Node.hpp"

// --- fsgl ---
#include "fsgl/Debug/Log.hpp"
#include "fsgl/Node/Aspects/Render2D.hpp"



namespace
{
    // - fsgl Root Node -
    // This is the root scene node. All main scenes should be a child of this node
    struct RootNode : public fsgl::Node
    {
        // Default Constructor
        inline RootNode() : 
            Node("root") {}
    };

    // static root node instance
    static std::shared_ptr<fsgl::Node> s_Root;
}



void fsgl::Node::initializeRootNode()
{
    s_Root.reset(new RootNode());

    auto& render2d_comp = s_Root->addComponent<Render2D>("", ""); // Dont compile shader
    render2d_comp.setIgnoreComponents(true); // Dont render components for root node

    FSGL_CORE_INFO("Initialized root node");
}

const std::shared_ptr<fsgl::Node>& fsgl::Node::getRoot()
{
    return s_Root;
}

fsgl::Node::Node(const std::string& name) : 
    m_Name(name)
{

}

void fsgl::Node::onInit(Node* parent)
{

}

void fsgl::Node::onUpdate(const time::step_ms delta)
{

}

const std::string &fsgl::Node::getName() const
{
    return m_Name;
}

fsgl::Node* fsgl::Node::getParent()
{
    return m_Parent;
}

const std::vector<std::unique_ptr<fsgl::Node>>& fsgl::Node::getChildren() const
{
    return m_Children;
}

std::unique_ptr<fsgl::Node>& fsgl::Node::addNode(Node* node)
{
    // Add the child node
    auto& uptr = m_Children.emplace_back(node);
    
    // Set up child's new parents
    node->m_Parent = this;
    node->onInit(this);

    return uptr;
}

void fsgl::Node::update(const time::step_ms delta)
{
    onUpdate(delta);

    for (auto& component : m_Components)
        if (component.second)
            component.second->onUpdate(delta);
    
    for (auto& child : m_Children)
        if (child)
            child->update(delta);
}
