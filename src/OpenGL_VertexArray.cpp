#include "RLEpch.hpp"
#include "impl/API/OpenGL/OpenGL_VertexArray.hpp"

// --- GLAD ---
#include <glad/gl.h>

// --- RLE ---
#include "RLE/Rendering/IndexBuffer.hpp"
#include "RLE/Rendering/VertexBuffer.hpp"
#include "RLE/Rendering/2D/Vertex2D.hpp"



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

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), nullptr);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (const void*)offsetof(Vertex2D, color));

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
