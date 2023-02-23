#include "RLEpch.hpp"
#include "RLE/Rendering/VertexBuffer.hpp"

// --- RLE ---
#include "RLE/Debug/Log.hpp"
#include "RLE/Rendering/RenderingAPI.hpp"

// --- RLE impl ---
#include "impl/API/OpenGL/OpenGL_VertexBuffer.hpp"



std::shared_ptr<rle::VertexBuffer> rle::factory<rle::VertexBuffer>::create(
	const std::size_t size)
{
	return create(nullptr, size);
}

std::shared_ptr<rle::VertexBuffer> rle::factory<rle::VertexBuffer>::create(
	const void* data,
	const std::size_t size)
{
	std::shared_ptr<VertexBuffer> ptr;

	switch (RenderingAPI::getAPI())
	{
	case RenderingAPI::API::OpenGL:
		ptr = std::make_shared<impl::OpenGL_VertexBuffer>(data, size);
		break;

	case RenderingAPI::API::None:
		RLE_CORE_WARN("Trying to create VertexBuffer object with no active rendering API.");
		break;
	}
	
	return ptr;
}
