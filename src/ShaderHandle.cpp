#include "fsgl_pch.hpp"
#include "fsgl/Rendering/ShaderHandle.hpp"

// --- fsgl impl ---
#include "impl/API/OpenGL/OpenGL_ShaderHandle.hpp"



std::shared_ptr<fsgl::ShaderHandle> fsgl::ShaderHandle::make(const std::string& vertex_src, const std::string& fragment_src)
{
    return std::shared_ptr<ShaderHandle>(new impl::OpenGL_ShaderHandle(vertex_src, fragment_src));
}
