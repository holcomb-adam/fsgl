#include "fsgl_pch.hpp"
#include "fsgl/Rendering/FrameBuffer.hpp"

// --- fsgl impl ---
#include "impl/API/OpenGL/OpenGL_FrameBuffer.hpp"



std::shared_ptr<fsgl::FrameBuffer> fsgl::factory<fsgl::FrameBuffer>::create(const std::uint32_t width, const std::uint32_t height)
{
	return std::shared_ptr<FrameBuffer>(new impl::OpenGL_FrameBuffer(width, height));
}
