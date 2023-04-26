#include "RLEpch.hpp"
#include "RLE/Rendering/GraphicsAPI.hpp"

// --- RLE ----
#include "RLE/Debug/Log.hpp"

// --- RLE impl ---
#include "impl/API/OpenGL/OpenGL_GraphicsAPI.hpp"



namespace
{
    static std::unique_ptr<rle::GraphicsAPI> s_API;
    static rle::GraphicsAPI::API s_APIType = rle::GraphicsAPI::API::None;
}



void rle::GraphicsAPI::init(const API graphics_api)
{
    switch (graphics_api)
    {
    case API::None: // ------------------------------ No API
        RLE_CORE_WARN("{0} recieved API::None. This is not an error but nothing will be drawn to "
                      "the window.", RLE_FUNCSIG);
        break;

    case API::OpenGL: // ---------------------------- OpenGL API
        s_API.reset(new rle::impl::OpenGL_GraphicsAPI());
        break;

    default: // ------------------------------------- Unknown API
        RLE_CORE_CRITICAL(
            "{0} recieved invalid API argument: {1}",
            RLE_FUNCSIG,
            static_cast<std::underlying_type_t<API>>(graphics_api));
        assert(false);
        return;
    }

    // Initialize the underlying API
    s_API->init();
}

const std::unique_ptr<rle::GraphicsAPI> &rle::GraphicsAPI::get()
{
    return s_API;
}

rle::GraphicsAPI::API rle::GraphicsAPI::activeAPI()
{
    return s_APIType;
}

rle::GraphicsAPI::GraphicsAPI(API api_type)
{
    s_APIType = api_type;
}
