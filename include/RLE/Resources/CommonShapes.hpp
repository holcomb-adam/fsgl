#pragma once

// --- RLE ---
#include "RLE/Resources/Geometry.hpp"



namespace rle
{
    namespace res
    {
        // Create a rectangle shape resource
        // - This function by default parameters creates a rectangle resource
        //   that is half screen space size
        std::shared_ptr<Geometry> makeRect(
            const float w = 0.5f,
            const float h = 0.5f);
    }
}
