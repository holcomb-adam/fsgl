#include "RLEpch.hpp"
#include "RLE/Rendering/Shader.hpp"

// --- RLE impl ---
#include "impl/API/OpenGL/OpenGL_Shader.hpp"



std::shared_ptr<rle::Shader> rle::factory<rle::Shader>::create(const std::string& vertex_src, const std::string& fragment_src)
{
	return std::shared_ptr<Shader>(new impl::OpenGL_Shader(vertex_src, fragment_src));
}
