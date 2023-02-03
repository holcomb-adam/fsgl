#pragma once

// --- Standard ---
#include <string>
#include <vector>

// --- RLE ---
#include "RLE/Core/Time.h"
#include "RLE/Rendering/Renderable.hpp"
#include "RLE/Utils/UniqueID.hpp"



namespace rle
{
	// The Node class is an abstract base class that is used to represent any given object
	// within a 2D or 3D scene
	class Node : public Renderable
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - STATIC MEMBERS ------------------------------------------------------------

		// - The Root Node -
		// The root of scene rendering
		// - The renderer utilizes this node to render to the screen
		// - Any node that is being rendered will have the root node at the top of the
		//   node tree
		static Node* getRoot();



	public:
		////////////////////////////////////////////////////////////////////////////////
		// - PUBLIC DATA ---------------------------------------------------------------

		// Unique Identifier
		UniqueID<Node> UID;
		


	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default Constructor
		Node() = default;

		// Constructor
		// - Intializes node with parent node reference
		Node(Node* parent);

		// Constructor
		// - Intializes node with parent node reference
		Node(Node* parent, const std::string& name);

		// Virtual Default Destructor
		virtual ~Node() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - VIRTUALS ------------------------------------------------------------------

		// Called to initialize the node when it is added as a child
		// - This is only called once and is not called when the the node is added to
		//   another node
		// - 'parent': Parent node
		virtual void onInit(Node* parent);

		// Called when the node is updated
		virtual void onUpdate(const time::step_ms delta);



		////////////////////////////////////////////////////////////////////////////////
		// - OBSERVERS -----------------------------------------------------------------

		// Get a raw pointer to the parent node
		Node* getParent();

		// Get a constant reference to a vector of raw pointers to children
		const std::vector<Node*>& getChildren() const;



		////////////////////////////////////////////////////////////////////////////////
		// - MODIFIERS -----------------------------------------------------------------

		// Add a child node
		Node* addNode(Node* node);



	private:
		// - Flags -
		bool m_Initialized = false;

		// - Information -
		std::string m_Name = "Node";

		// - Node Heirarchy -
		Node* m_Parent = nullptr;
		std::vector<Node*> m_Children;
	};
}
