#include "RLEpch.hpp"
#include "RLE/Rendering/GraphicsHandle.hpp"

// --- RLE ---
#include "RLE/Core/Core.hpp"
#include "RLE/Rendering/FrameBuffer.hpp"
#include "RLE/Rendering/GraphicsAPI.hpp"



namespace
{
    
}



std::shared_ptr<rle::GraphicsHandle> rle::GraphicsHandle::make()
{ 
    return std::shared_ptr<GraphicsHandle>(new GraphicsHandle());
}

rle::GraphicsHandle::GraphicsHandle() :
    m_ClearColor(RLE_BUFFER_CLEAR_COLOR, 1.0f)
{

}

void rle::GraphicsHandle::setClearColor(const glm::vec4& color)
{
    m_ClearColor = color;
}

void rle::GraphicsHandle::setFrameBuffer(std::weak_ptr<rle::FrameBuffer> fbo_ptr)
{
    m_FBO = std::move(fbo_ptr);
}

void rle::GraphicsHandle::bind() const
{
    if (!m_FBO.expired())
        m_FBO.lock()->bind();
    GraphicsAPI::get()->setClearColor(m_ClearColor);
}

void rle::GraphicsHandle::unbind() const
{
    m_FBO.lock()->unbind();
}

void rle::GraphicsHandle::clear()
{
    GraphicsAPI::get()->clear();
}

void rle::GraphicsHandle::viewport(std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h) const
{
    GraphicsAPI::get()->viewport(x, y, w, h);
}

void rle::GraphicsHandle::draw(const std::shared_ptr<VertexArray> &vao) const
{
    GraphicsAPI::get()->draw(vao);
}
