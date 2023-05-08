#include "fsgl_pch.hpp"
#include "fsgl/Core/Window.hpp"



// Check the windowing API that is being used
#   if defined(FSGL_API_WINDOW_GLFW)
#       include "impl/API/GLFW/GLFW_Window.hpp"
#       define FSGL_API_WINDOW_T ::fsgl::impl::GLFW_Window

#   else
#       error FSGL doesnt support console windowing yet!

#   endif



std::unique_ptr<fsgl::Window> fsgl::factory<fsgl::Window>::create(const Window::Properties& props)
{
	// Create API window instance
	auto api_win = factory<FSGL_API_WINDOW_T>::create(props);
	return std::move(api_win);
}
