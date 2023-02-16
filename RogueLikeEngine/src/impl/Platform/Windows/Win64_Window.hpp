#pragma once

// --- RLE impl ---
#include "impl/API/GLFW/GLFW_Window.hpp"



// - Forward Declarations -
struct GLFWwindow;



namespace rle
{
	namespace impl
	{
		class Win64_Window : public GLFW_Window
		{
		public:
			////////////////////////////////////////////////////////////////////////////////
			// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

			// Constructor
			Win64_Window(const Properties& props);

			// Destructor
			~Win64_Window() = default;
		};
	}
}
