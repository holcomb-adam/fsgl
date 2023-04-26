#include "RLEpch.hpp"
#include "RLE/Node/Node.hpp"

// --- RLE ---
#include "RLE/Debug/Log.hpp"
#include "RLE/Node/Aspects/Render2D.hpp"



namespace
{
    // - RLE Root Node -
    // This is the root scene node. All main scenes should be a child of this node
    struct RootNode : public rle::Node
    {
        // Default Constructor
        inline RootNode() : 
            Node("root") {}
    };

    // static root node instance
    static std::shared_ptr<rle::Node> s_Root;
}



void rle::Node::initializeRootNode()
{
    s_Root.reset(new RootNode());

    auto& render2d_comp = s_Root->addComponent<Render2D>("", ""); // Dont compile shader
    render2d_comp.setIgnoreComponents(true); // Dont render components for root node

    RLE_CORE_INFO("Initialized root node");
}

const std::shared_ptr<rle::Node>& rle::Node::getRoot()
{
    return s_Root;
}

rle::Node::Node(const std::string& name) : 
    m_Name(name)
{

}

void rle::Node::onInit(Node* parent)
{

}

void rle::Node::onUpdate(const time::step_ms delta)
{

}

const std::string &rle::Node::getName() const
{
    return m_Name;
}

rle::Node* rle::Node::getParent()
{
    return m_Parent;
}

const std::vector<std::unique_ptr<rle::Node>>& rle::Node::getChildren() const
{
    return m_Children;
}

std::unique_ptr<rle::Node>& rle::Node::addNode(Node* node)
{
    // Add the child node
    auto& uptr = m_Children.emplace_back(node);
    
    // Set up child's new parents
    node->m_Parent = this;
    node->onInit(this);

    return uptr;
}

void rle::Node::update(const time::step_ms delta)
{
    onUpdate(delta);

    for (auto& component : m_Components)
        if (component.second)
            component.second->onUpdate(delta);
    
    for (auto& child : m_Children)
        if (child)
            child->update(delta);
}
