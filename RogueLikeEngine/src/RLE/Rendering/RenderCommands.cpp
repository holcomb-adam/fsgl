#include "RLEpch.hpp"
#include "RenderCommands.hpp"

// --- RLE ----
#include "RLE/Debug/Log.hpp"

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
			"{0} recieved invalid API argument: {1}",
			RLE_FUNCSIG,
			static_cast<std::underlying_type_t<RenderingAPI::API>>(api));
		assert(false);
		return;
	}

	// Initialize the api
	s_API->init();
}

void rle::RenderCommands::setClearColor(const glm::vec4& color)
{
	s_API->setClearColor(color);
}

void rle::RenderCommands::clear()
{
	s_API->clear();
}

void rle::RenderCommands::viewport(const std::int32_t x, const std::int32_t y, const std::int32_t width, const std::int32_t height)
{
	s_API->viewport(x, y, width, height);
}

void rle::RenderCommands::draw(const std::shared_ptr<VertexArray>& vao)
{
	s_API->draw(vao);
}
