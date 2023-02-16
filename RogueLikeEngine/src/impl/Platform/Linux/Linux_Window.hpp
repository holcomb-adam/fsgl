#pragma once

// --- RLE impl ---
#include "impl/API/GLFW/GLFW_Window.hpp"


namespace rle
{
    namespace impl
    {
        class Linux_Window : public GLFW_Window
        {
        public:
            // [default]
            // Constructor
            Linux_Window(const Window::Properties& props);

            // [default]
            // Destructor
            ~Linux_Window() = default;
        };
    }
}

