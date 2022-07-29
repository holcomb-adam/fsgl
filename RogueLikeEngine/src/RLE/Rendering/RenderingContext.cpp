#include "RLEpch.h"
#include "RenderingContext.h"

// Standard Library includes
#include <cassert>

// RLE Library includes
#include "RLE/Platform/OpenGL/OpenGLContext.h"



std::unique_ptr<rle::RenderingContext> rle::RenderingContext::create(const RenderingAPI api, void* win_handle)
{
    switch (api)
    {
    case RenderingAPI::OpenGL:
        return std::unique_ptr<rle::RenderingContext>(new impl::OpenGLContext(static_cast<GLFWwindow*>(win_handle)));
    }
    
    assert(false);
    return nullptr;
}
