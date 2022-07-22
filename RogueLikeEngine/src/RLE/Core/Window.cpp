#include "RLEpch.h"
#include "Window.h"



#   if defined(RLE_OS_WIN64)
#       include "RLE/Platform/Windows/Win64_Window.h"
#       define RLE_PLATFORM_WINDOW_INSTANCE rle::Win64_Window

#   else
#       define RLE_PLATFORM_WINDOW_INSTANCE nullptr

#   endif



std::unique_ptr<rle::Window> rle::Window::create(const Properties& props)
{
    return std::unique_ptr<Window>(new RLE_PLATFORM_WINDOW_INSTANCE(props));
}
