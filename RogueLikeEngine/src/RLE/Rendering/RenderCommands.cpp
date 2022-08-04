#include "RLEpch.h"
#include "RenderCommands.hpp"

// --- RLE ----
#include "RLE/Debug/Log.h"

// --- RLE impl ---
#include "impl/API/OpenGL/OpenGL_RenderingAPI.hpp"



namespace // private anonymous namespace
{
	static std::unique_ptr<rle::RenderingAPI> s_API;
}



void rle::RenderCommands::init(const RenderingAPI::API api)
{
	switch (api)
	{
	case RenderingAPI::API::OpenGL: // --------------------------- OpenGL API
		s_API.reset(new rle::impl::OpenGL_RenderingAPI());
		break;

	default: // -------------------------------------------------- Unknown API
		RLE_CORE_CRITICAL(
			"{0} recieved an invalid api argument: {1}",
			__FUNCSIG__,
			static_cast<std::underlying_type_t<RenderingAPI::API>>(api));
		assert(false);
		return;
	}

	// Initialize the api
	s_API->init();
}

void rle::RenderCommands::setClearColor(const Color& color)
{
	s_API->setClearColor(color);
}

void rle::RenderCommands::clear()
{
	s_API->clear();
}

void rle::RenderCommands::draw(const std::shared_ptr<VertexArray>& vao)
{
	s_API->draw(vao);
}
