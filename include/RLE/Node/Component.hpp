#pragma once

// --- RLE ---
#include "RLE/Core/Time.hpp"



namespace rle
{
    // - Forward Declarations -
    class Node;



    class Component
    {
        // - Friends -
        friend class Node;



    public:
        ////////////////////////////////////////////////////////////////////////////////
        // - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

        /// @brief Default constructor
        Component() = default;

        /// @brief Default destructor
        virtual ~Component() = default;



        ////////////////////////////////////////////////////////////////////////////////
        // - GETTERS -------------------------------------------------------------------

        /// @brief Get the owning node
        /// @return The node
        Node& getNode();
        const Node& getNode() const;



    private:
        virtual void onInit();
        virtual void onUpdate(const time::step_ms delta);



    private:
        Node* m_Owner = nullptr;
    };
}
