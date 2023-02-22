#include "RLEpch.hpp"
#include "RLE/Rendering/VertexBuffer.hpp"

// --- RLE impl ---
#include "impl/API/OpenGL/OpenGL_VertexBuffer.hpp"



std::shared_ptr<rle::VertexBuffer> rle::factory<rle::VertexBuffer>::create(
	const std::size_t size)
{
	// TEMP: Only cuz its a late night...
	return std::shared_ptr<VertexBuffer>(new impl::OpenGL_VertexBuffer(nullptr, size));
}

std::shared_ptr<rle::VertexBuffer> rle::factory<rle::VertexBuffer>::create(
	const void* data,
	const std::size_t size)
{
	// TEMP: Only cuz its a late night...
	return std::shared_ptr<VertexBuffer>(new impl::OpenGL_VertexBuffer(data, size));
}
