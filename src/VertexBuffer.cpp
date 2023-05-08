#include "fsgl_pch.hpp"
#include "fsgl/Rendering/VertexBuffer.hpp"

// --- fsgl ---
#include "fsgl/Debug/Log.hpp"
#include "fsgl/Rendering/GraphicsAPI.hpp"
#include "fsgl/Rendering/2D/Vertex2D.hpp"

// --- fsgl impl ---
#include "impl/API/OpenGL/OpenGL_VertexBuffer.hpp"



std::shared_ptr<fsgl::VertexBuffer> fsgl::factory<fsgl::VertexBuffer>::create(const std::size_t count)
{
    return create(nullptr, count);
}

std::shared_ptr<fsgl::VertexBuffer> fsgl::factory<fsgl::VertexBuffer>::create(
	const Vertex2D* data,
	const std::size_t count)
{
	std::shared_ptr<VertexBuffer> ptr;

	switch (GraphicsAPI::activeAPI())
	{
	case GraphicsAPI::API::OpenGL:
		ptr = std::make_shared<impl::OpenGL_VertexBuffer>(data, count);
		break;

	case GraphicsAPI::API::None:
		FSGL_CORE_WARN("Trying to create VertexBuffer object with no active rendering API.");
		break;
	}
	
	return ptr;
}
