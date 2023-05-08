#include "fsgl_pch.hpp"
#include "fsgl/Rendering/GraphicsHandle.hpp"

// --- fsgl ---
#include "fsgl/Core/Core.hpp"
#include "fsgl/Rendering/FrameBuffer.hpp"
#include "fsgl/Rendering/GraphicsAPI.hpp"



std::shared_ptr<fsgl::GraphicsHandle> fsgl::GraphicsHandle::make()
{ 
    return std::shared_ptr<GraphicsHandle>(new GraphicsHandle());
}

fsgl::GraphicsHandle::GraphicsHandle() :
    m_ClearColor(FSGL_BUFFER_CLEAR_COLOR, 1.0f)
{

}

void fsgl::GraphicsHandle::setClearColor(const glm::vec4& color)
{
    m_ClearColor = color;
}

void fsgl::GraphicsHandle::setFrameBuffer(std::weak_ptr<fsgl::FrameBuffer> fbo_ptr)
{
    m_FBO = std::move(fbo_ptr);
}

void fsgl::GraphicsHandle::bind() const
{
    if (!m_FBO.expired())
        m_FBO.lock()->bind();
    GraphicsAPI::get()->setClearColor(m_ClearColor);
}

void fsgl::GraphicsHandle::unbind() const
{
    m_FBO.lock()->unbind();
}

void fsgl::GraphicsHandle::clear()
{
    GraphicsAPI::get()->clear();
}

void fsgl::GraphicsHandle::viewport(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h) const
{
    GraphicsAPI::get()->viewport(x, y, w, h);
}

void fsgl::GraphicsHandle::draw(const std::shared_ptr<VertexArray> &vao) const
{
    GraphicsAPI::get()->draw(vao);
}
