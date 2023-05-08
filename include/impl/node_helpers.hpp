#pragma once

// --- Standard ---
#include <cstddef>


namespace fsgl
{
    namespace impl
    {
        inline std::size_t newComponentID()
        {
            static std::size_t ID = 0;
            return ID++;
        }

        template<class T>
        inline std::size_t getComponentTypeID()
        {
            static auto ID = newComponentID();
            return ID;
        }
    }
}
