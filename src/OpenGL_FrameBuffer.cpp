#include "fsgl_pch.hpp"
#include "impl/API/OpenGL/OpenGL_FrameBuffer.hpp"

// --- GLAD ---
#include <glad/gl.h>

// --- fsgl ---
#include "fsgl/Debug/Log.hpp"



fsgl::impl::OpenGL_FrameBuffer::OpenGL_FrameBuffer(const std::uint32_t width, const std::uint32_t height)
{
	// Create the frame buffer
	glCreateFramebuffers(1, &m_ID);
	glBindFramebuffer(GL_FRAMEBUFFER, m_ID);

	// Create a texture to attach to the frame buffer
	glCreateTextures(GL_TEXTURE_2D, 1, &m_TextureID);
	glBindTexture(GL_TEXTURE_2D, m_TextureID);

	// Initialize the texture
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Attach the texture to the frame buffer
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_TextureID, 0);

	// Check if the frame buffer is complete
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		FSGL_CORE_CRITICAL("OpenGL FBO is invalid!");
}

fsgl::impl::OpenGL_FrameBuffer::~OpenGL_FrameBuffer()
{
	glDeleteTextures(1, &m_TextureID);
	glDeleteFramebuffers(1, &m_ID);
}

void fsgl::impl::OpenGL_FrameBuffer::bind() const
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_TextureID);
}

void fsgl::impl::OpenGL_FrameBuffer::unbind() const
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

std::uint32_t fsgl::impl::OpenGL_FrameBuffer::texture() const
{
	return m_TextureID;
}

void fsgl::impl::OpenGL_FrameBuffer::resizeTexture(const std::uint32_t width, const std::uint32_t height)
{
	glBindTexture(GL_TEXTURE_2D, m_TextureID);

	// Reallocate the texture with the new width and height
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}
