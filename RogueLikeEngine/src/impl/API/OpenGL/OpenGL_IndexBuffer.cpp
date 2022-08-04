#include "RLEpch.h"
#include "OpenGL_IndexBuffer.hpp"

// External Library includes
#include <glad/glad.h>

rle::impl::OpenGL_IndexBuffer::OpenGL_IndexBuffer(const std::uint32_t count, const std::uint32_t* indices) :
	m_Count(count)
{
	glCreateBuffers(1, &m_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(std::uint32_t), indices, GL_STATIC_DRAW);
}

rle::impl::OpenGL_IndexBuffer::~OpenGL_IndexBuffer()
{
	glDeleteBuffers(1, &m_ID);
}

std::uint32_t rle::impl::OpenGL_IndexBuffer::count() const
{
	return m_Count;
}

void rle::impl::OpenGL_IndexBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void rle::impl::OpenGL_IndexBuffer::unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
