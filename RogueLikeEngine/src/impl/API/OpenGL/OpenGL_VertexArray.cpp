#include "RLEpch.h"
#include "OpenGL_VertexArray.hpp"

// External Library includes
#include <glad/glad.h>

// RLE Library includes
#include "RLE/Rendering/IndexBuffer.hpp"
#include "RLE/Rendering/Vertex.hpp"
#include "RLE/Rendering/VertexBuffer.hpp"



rle::impl::OpenGL_VertexArray::OpenGL_VertexArray()
{
	glCreateVertexArrays(1, &m_ID);
}

rle::impl::OpenGL_VertexArray::~OpenGL_VertexArray()
{
	glDeleteVertexArrays(1, &m_ID);
}

void rle::impl::OpenGL_VertexArray::bind() const
{
	glBindVertexArray(m_ID);
}

void rle::impl::OpenGL_VertexArray::unbind() const
{
	glBindVertexArray(0);
}

void rle::impl::OpenGL_VertexArray::addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertex_buffer)
{
	// Bind the array and then the buffer
	glBindVertexArray(m_ID);
	vertex_buffer->bind();

	// Setup vertex attribute pointers for Vertex struct
	// 1st attrib - position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);

	// 2nd attrib - color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, Vertex::color));

	// add the buffer to the vector
	m_VertexBuffers.push_back(vertex_buffer);
}

void rle::impl::OpenGL_VertexArray::setIndexBuffer(const std::shared_ptr<IndexBuffer>& index_buffer)
{
	glBindVertexArray(m_ID);
	index_buffer->bind();

	m_IndexBuffer = index_buffer;
}

const std::shared_ptr<rle::IndexBuffer>& rle::impl::OpenGL_VertexArray::getIndexBuffer() const
{
	return m_IndexBuffer;
}
