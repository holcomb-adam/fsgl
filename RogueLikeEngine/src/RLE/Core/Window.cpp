#include "RLEpch.hpp"
#include "Window.hpp"



// Check the windowing API that is being used
#   if defined(RLE_API_WINDOW_GLFW)
#       include "impl/API/GLFW/GLFW_Window.hpp"
#       define RLE_API_WINDOW_T ::rle::impl::GLFW_Window

#   else
#       error RLE doesnt support console windowing yet!

#   endif



std::unique_ptr<rle::Window> rle::factory<rle::Window>::create(const Window::Properties& props)
{
	// Create API window instance
	auto api_win = factory<RLE_API_WINDOW_T>::create(props);
	return std::move(api_win);
}
