#pragma once

// --- Standard ---
#include <map>
#include <memory>
#include <string>
#include <vector>

// --- RLE ---
#include "RLE/Core/Time.hpp"
#include "RLE/Node/Component.hpp"
#include "RLE/Utils/UniqueID.hpp"



namespace rle
{
	// The Node class is an abstract base class that is used to represent any given object
	// within a 2D or 3D scene
	class Node
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - STATIC MEMBERS ------------------------------------------------------------

		// - The Root Node -

		// Initialize the root node
		static void initializeRootNode();

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
		// - GETTERS -------------------------------------------------------------------

		/// @returns The name of the node
		const std::string& getName() const;

		// Get a raw pointer to the parent node
		Node* getParent();

		// Get a constant reference to a vector of raw pointers to children
		const std::vector<Node*>& getChildren() const;



		////////////////////////////////////////////////////////////////////////////////
		// - MODIFIERS -----------------------------------------------------------------

		/// @brief Add a child node.
		/// @param node Child node
		/// @return The child node
		Node* addNode(Node* node);

		/// @brief Add a component type to the node.
		/// @tparam T Component type
		/// @tparam ...Targs Type T construction argument types
		/// @param ...targs Type T construction arguments
		/// @return A reference to the constructed node object
		template<class T, class... Targs>
		T& addComponent(Targs&&... targs);

		/// @brief Get the component of type T.
		/// @tparam T Type of component.
		/// @return Component reference
		template<class T>
		T& getComponent();

		/// @brief Get the component of type T.
		/// @tparam T Type of component.
		/// @return Component reference
		template<class T>
		const T& getComponent() const;

		/// @brief 
		/// @tparam T 
		/// @return 
		template<class T>
		bool hasComponent() const;



		////////////////////////////////////////////////////////////////////////////////
		// - OPERATIONS ----------------------------------------------------------------

		/// @brief Update the node, it's components, and it's children
		/// @param delta Time step since last update
		void update(const time::step_ms delta);



	private:
		////////////////////////////////////////////////////////////////////////////////
		// - VIRTUALS ------------------------------------------------------------------

		// Called to initialize the node when it is added as a child
		// - This is only called once and is not called when the the node is added to
		//   another node
		// - 'parent': Parent node
		virtual void onInit(Node* parent);

		// Called when the node is updated
		virtual void onUpdate(const time::step_ms delta);



	private:
		// - Flags -
		bool m_Initialized = false;

		// - Information -
		std::string m_Name = "Node";

		// - Components -
		std::map<std::size_t, std::unique_ptr<Component>> m_Components;

		// - Node Heirarchy -
		Node* m_Parent = nullptr;
		std::vector<Node*> m_Children;
	};
}



// --- Inline Definition ---
#include "Node.inl"
