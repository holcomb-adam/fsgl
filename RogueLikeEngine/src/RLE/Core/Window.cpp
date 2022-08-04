#include "RLEpch.h"
#include "Window.h"



// Check if we are compiling for windows
#   if defined(RLE_OS_WIN64)
#       include "impl/Platform/Windows/Win64_Window.hpp"
#       define RLE_PLATFORM_WINDOW_INSTANCE rle::impl::Win64_Window

#   else
#       define RLE_PLATFORM_WINDOW_INSTANCE nullptr

#   endif



std::unique_ptr<rle::Window> rle::factory<rle::Window>::create(const Window::Properties& props)
{
	return std::unique_ptr<Window>(new RLE_PLATFORM_WINDOW_INSTANCE(props));
}
