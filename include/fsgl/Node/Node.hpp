#pragma once

// --- Standard ---
#include <map>
#include <memory>
#include <string>
#include <vector>

// --- fsgl ---
#include "fsgl/Core/Time.hpp"
#include "fsgl/Node/Aspect.hpp"
#include "fsgl/Utils/UniqueID.hpp"



namespace fsgl
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
        static const std::shared_ptr<Node>& getRoot();



    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - PUBLIC DATA ---------------------------------------------------------------

        // Unique Identifier
        UniqueID<Node> UID;



    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

        Node() = default;

        /// @brief 
        /// @param name 
        Node(const std::string& name);

        virtual ~Node() = default;



        ////////////////////////////////////////////////////////////////////////////////
        // - GETTERS -------------------------------------------------------------------

        /// @returns The name of the node
        const std::string& getName() const;

        /// @brief 
        /// @return 
        Node* getParent();

        /// @brief 
        /// @return 
        const std::vector<std::unique_ptr<Node>>& getChildren() const;



        ////////////////////////////////////////////////////////////////////////////////
        // - MODIFIERS -----------------------------------------------------------------

        /// @brief Add a child node.
        /// @param node Child node
        /// @return std::unique_ptr to child node
        std::unique_ptr<Node>& addNode(Node* node);

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
        std::map<std::size_t, std::unique_ptr<Aspect>> m_Components;

        // - Node Heirarchy -
        Node* m_Parent = nullptr;
        std::vector<std::unique_ptr<Node>> m_Children;
    };
}



// --- Inline Definition ---
#include "Node.inl"
