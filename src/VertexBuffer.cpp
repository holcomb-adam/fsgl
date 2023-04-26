#include "RLEpch.hpp"
#include "RLE/Rendering/VertexBuffer.hpp"

// --- RLE ---
#include "RLE/Debug/Log.hpp"
#include "RLE/Rendering/GraphicsAPI.hpp"
#include "RLE/Rendering/2D/Vertex2D.hpp"

// --- RLE impl ---
#include "impl/API/OpenGL/OpenGL_VertexBuffer.hpp"



std::shared_ptr<rle::VertexBuffer> rle::factory<rle::VertexBuffer>::create(const std::size_t count)
{
    return create(nullptr, count);
}

std::shared_ptr<rle::VertexBuffer> rle::factory<rle::VertexBuffer>::create(
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
		RLE_CORE_WARN("Trying to create VertexBuffer object with no active rendering API.");
		break;
	}
	
	return ptr;
}
