#include "RLEpch.h"
#include "VertexBuffer.hpp"

// --- RLE impl ---
#include "impl/API/OpenGL/OpenGL_VertexBuffer.hpp"



std::shared_ptr<rle::VertexBuffer> rle::factory<rle::VertexBuffer>::create(
	const std::size_t size)
{
	// TEMP: Only cuz its a late night...
	return std::shared_ptr<VertexBuffer>(new impl::OpenGL_VertexBuffer(size));
}

std::shared_ptr<rle::VertexBuffer> rle::factory<rle::VertexBuffer>::create(
	const std::size_t size,
	const Vertex* data)
{
	// TEMP: Only cuz its a late night...
	return std::shared_ptr<VertexBuffer>(new impl::OpenGL_VertexBuffer(size, data));
}
