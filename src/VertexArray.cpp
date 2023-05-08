#include "fsgl_pch.hpp"
#include "fsgl/Rendering/VertexArray.hpp"

// --- fsgl impl ---
#include "impl/API/OpenGL/OpenGL_VertexArray.hpp"



std::shared_ptr<fsgl::VertexArray> fsgl::factory<fsgl::VertexArray>::create()
{
	return std::shared_ptr<VertexArray>(new impl::OpenGL_VertexArray());
}