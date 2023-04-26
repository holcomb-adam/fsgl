#pragma once

// --- GLM ---
#include <glm/vec2.hpp>

// --- imgui ---
#include <imgui.h>



namespace anvil
{
    template<class T>
    inline ImVec2 to_imvec(const glm::vec<2, T>& vec)
    {
        return ImVec2(static_cast<float>(vec.x), static_cast<float>(vec.y));
    }
}
