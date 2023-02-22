#include "RLEpch.hpp"
#include "RLE/Rendering/FrameBuffer.hpp"

// --- RLE impl ---
#include "impl/API/OpenGL/OpenGL_FrameBuffer.hpp"



std::shared_ptr<rle::FrameBuffer> rle::factory<rle::FrameBuffer>::create(const std::uint32_t width, const std::uint32_t height)
{
	return std::shared_ptr<FrameBuffer>(new impl::OpenGL_FrameBuffer(width, height));
}
