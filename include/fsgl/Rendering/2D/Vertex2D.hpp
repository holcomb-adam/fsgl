#pragma once

// --- GLM ---
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>



/// @fixme At some point, data being uploaded shouldnt be limited to specific classes.
///        Standard tuple may provide a good way to upload data in a uniform templated way.

namespace fsgl
{
    struct Vertex2D
    {
        glm::vec2 position;
        glm::vec4 color;
    };
}
