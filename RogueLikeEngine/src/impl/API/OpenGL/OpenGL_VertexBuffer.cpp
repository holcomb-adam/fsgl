#include "RLEpch.h"
#include "OpenGL_VertexBuffer.hpp"

// External Library includes
#include <glad/glad.h>

// Standard Library includes
#include <unordered_map>

// RLE Library includes
#include "RLE/Debug/Log.h"



rle::impl::OpenGL_VertexBuffer::OpenGL_VertexBuffer(const std::size_t size)
{
	init(size, nullptr);
}

rle::impl::OpenGL_VertexBuffer::OpenGL_VertexBuffer(const std::size_t size, const Vertex* data)
{
	init(size, data);
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

void rle::impl::OpenGL_VertexBuffer::setData(const Vertex* data, const std::size_t size)
{
	bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
}

void rle::impl::OpenGL_VertexBuffer::init(const std::size_t size, const Vertex* data)
{
	glCreateBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
}
