#include "RLEpch.hpp"
#include "RLE/Rendering/VertexArray.hpp"

// --- RLE impl ---
#include "impl/API/OpenGL/OpenGL_VertexArray.hpp"



std::shared_ptr<rle::VertexArray> rle::factory<rle::VertexArray>::create()
{
	return std::shared_ptr<VertexArray>(new impl::OpenGL_VertexArray());
}