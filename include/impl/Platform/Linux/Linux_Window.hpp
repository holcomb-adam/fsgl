#pragma once

// --- FSGL impl ---
#include "impl/API/GLFW/GLFW_Window.hpp"


namespace fsgl
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

