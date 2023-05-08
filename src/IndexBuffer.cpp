#include "fsgl_pch.hpp"
#include "fsgl/Rendering/IndexBuffer.hpp"

// --- fsgl ---
#include "impl/API/OpenGL/OpenGL_IndexBuffer.hpp"



std::shared_ptr<fsgl::IndexBuffer> fsgl::factory<fsgl::IndexBuffer>::create(const std::uint32_t* indicies, const std::uint32_t count)
{
	return std::shared_ptr<fsgl::IndexBuffer>(new impl::OpenGL_IndexBuffer(count, indicies));
}