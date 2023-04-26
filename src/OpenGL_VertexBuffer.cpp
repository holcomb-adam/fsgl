#include "RLEpch.hpp"
#include "impl/API/OpenGL/OpenGL_VertexBuffer.hpp"

// --- GLAD ---
#include <glad/gl.h>

// --- Standard ---
#include <unordered_map>

// --- RLE ---
#include "RLE/Debug/Log.hpp"
#include "RLE/Rendering/2D/Vertex2D.hpp"



rle::impl::OpenGL_VertexBuffer::OpenGL_VertexBuffer(const Vertex2D* data, const std::size_t count)
{
	glCreateBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(Vertex2D), data, GL_STATIC_DRAW);
}

rle::impl::OpenGL_VertexBuffer::~OpenGL_VertexBuffer()
{
	glDeleteBuffers(1, &m_ID);
}

void rle::impl::OpenGL_VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void rle::impl::OpenGL_VertexBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void rle::impl::OpenGL_VertexBuffer::setData(const Vertex2D* data, const std::size_t count)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferSubData(GL_ARRAY_BUFFER, 0, count, data);
}
