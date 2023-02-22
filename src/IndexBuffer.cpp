#include "RLEpch.hpp"
#include "RLE/Rendering/IndexBuffer.hpp"

// --- RLE ---
#include "impl/API/OpenGL/OpenGL_IndexBuffer.hpp"



std::shared_ptr<rle::IndexBuffer> rle::factory<rle::IndexBuffer>::create(const std::uint32_t* indicies, const std::uint32_t count)
{
	return std::shared_ptr<rle::IndexBuffer>(new impl::OpenGL_IndexBuffer(count, indicies));
}