#include "fsgl_pch.hpp"
#include "fsgl/Rendering/GraphicsAPI.hpp"

// --- fsgl ----
#include "fsgl/Debug/Log.hpp"

// --- fsgl impl ---
#include "impl/API/OpenGL/OpenGL_GraphicsAPI.hpp"



namespace
{
    static std::unique_ptr<fsgl::GraphicsAPI> s_API;
    static fsgl::GraphicsAPI::API s_APIType = fsgl::GraphicsAPI::API::None;
}



void fsgl::GraphicsAPI::init(const API graphics_api)
{
    switch (graphics_api)
    {
    case API::None: // ------------------------------ No API
        FSGL_CORE_WARN("{0} recieved API::None. This is not an error but nothing will be drawn to "
                      "the window.", FSGL_FUNCSIG);
        break;

    case API::OpenGL: // ---------------------------- OpenGL API
        s_API.reset(new fsgl::impl::OpenGL_GraphicsAPI());
        break;

    default: // ------------------------------------- Unknown API
        FSGL_CORE_CRITICAL(
            "{0} recieved invalid API argument: {1}",
            FSGL_FUNCSIG,
            static_cast<std::underlying_type_t<API>>(graphics_api));
        assert(false);
        return;
    }

    // Initialize the underlying API
    s_API->init();
}

const std::unique_ptr<fsgl::GraphicsAPI> &fsgl::GraphicsAPI::get()
{
    return s_API;
}

fsgl::GraphicsAPI::API fsgl::GraphicsAPI::activeAPI()
{
    return s_APIType;
}

fsgl::GraphicsAPI::GraphicsAPI(API api_type)
{
    s_APIType = api_type;
}
