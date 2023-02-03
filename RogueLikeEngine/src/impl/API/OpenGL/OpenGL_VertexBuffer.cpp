#include "RLEpch.h"
#include "OpenGL_VertexBuffer.hpp"

// --- External ---
#include <glad/glad.h>

// --- Standard ---
#include <unordered_map>

// --- RLE ---
#include "RLE/Debug/Log.h"



rle::impl::OpenGL_VertexBuffer::OpenGL_VertexBuffer(const void* data, const std::size_t size)
{
	glCreateBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
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

void rle::impl::OpenGL_VertexBuffer::setData(const void* data, const std::size_t size)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
}
