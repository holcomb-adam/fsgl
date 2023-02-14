#include "RLEpch.hpp"
#include "Node.hpp"

// --- RLE ---
#include "RLE/Debug/Log.hpp"
#include "RLE/Rendering/Renderer.hpp"



namespace
{
	
	// - RLE Root Node -
	// This is the root scene node. All main scenes should be be children of this node
	static struct RootNode final : public rle::Node
	{
		// Default Constructor
		inline RootNode() : 
			Node(this, "root") {}

		// Inherited via Node
		inline virtual void onRender(rle::Renderer& target) const override
		{
			// Loop through the nodes and render them
			for (const auto c : getChildren())
				if (c) // Ensure the node exists
					target.submit(*c);
		}
	} s_Root; // static root node instance
}



rle::Node* rle::Node::getRoot()
{
	return &s_Root;
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
