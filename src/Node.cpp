#include "RLEpch.hpp"
#include "RLE/Node/Node.hpp"

// --- RLE ---
#include "RLE/Debug/Log.hpp"
#include "RLE/Node/Components/Render2D.hpp"



namespace
{
	// - RLE Root Node -
	// This is the root scene node. All main scenes should be a child of this node
	struct RootNode : public rle::Node
	{
		// Default Constructor
		inline RootNode() : 
			Node(nullptr, "root") {}
	};

	// static root node instance
	static std::unique_ptr<RootNode> s_Root;
}



void rle::Node::initializeRootNode()
{
    s_Root.reset(new RootNode());

    auto& render2d_comp = s_Root->addComponent<Render2D>("", ""); // Dont compile shader
    render2d_comp.setIgnoreComponents(true); // Dont render components for root node

    RLE_CORE_INFO("Initialized root node");
}

rle::Node* rle::Node::getRoot()
{
	return s_Root.get();
}

rle::Node::Node(Node* parent) :
	m_Parent(parent)
{

}

rle::Node::Node(Node* parent, const std::string& name) : 
	m_Parent(parent),
	m_Name(name)
{

}

void rle::Node::onInit(Node* parent)
{

}

void rle::Node::onUpdate(const time::step_ms delta)
{

}

const std::string & rle::Node::getName() const
{
	return m_Name;
}

rle::Node* rle::Node::getParent()
{
	return m_Parent;
}

const std::vector<rle::Node*>& rle::Node::getChildren() const
{
	return m_Children;
}

rle::Node* rle::Node::addNode(Node* node)
{
	// Ensure the pointer is valid
	if (!node)
	{
		RLE_CORE_WARN("Node \"{0}\" 'node' recieved invalid pointer");
		return nullptr;
	}

	// Add the child node
	m_Children.push_back(node);
	
	// Set up child's new parents
	node->m_Parent = this;
	node->onInit(this);

	return node;
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
