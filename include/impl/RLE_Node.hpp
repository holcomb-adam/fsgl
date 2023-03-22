#pragma once

// --- Standard ---
#include <cstddef>


namespace rle
{
    namespace impl
    {
        std::size_t newComponentID();

        template<class T>
        std::size_t getComponentTypeID();
    }
}



#include "RLE_Node.inl"
