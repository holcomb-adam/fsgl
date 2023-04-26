#include "RLEpch.hpp"
#include "RLE/Rendering/ShaderHandle.hpp"

// --- RLE impl ---
#include "impl/API/OpenGL/OpenGL_ShaderHandle.hpp"



std::shared_ptr<rle::ShaderHandle> rle::ShaderHandle::make(const std::string& vertex_src, const std::string& fragment_src)
{
    return std::shared_ptr<ShaderHandle>(new impl::OpenGL_ShaderHandle(vertex_src, fragment_src));
}
