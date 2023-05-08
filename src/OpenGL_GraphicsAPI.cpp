#include "fsgl_pch.hpp"
#include "impl/API/OpenGL/OpenGL_GraphicsAPI.hpp"

// --- GLAD ---
#include <glad/gl.h>

// --- GLFW ---
#include <GLFW/glfw3.h>

// --- fsgl ---
#include "fsgl/Debug/Log.hpp"
#include "fsgl/Rendering/IndexBuffer.hpp"
#include "fsgl/Rendering/VertexArray.hpp"



namespace // OpenGL House Keeping
{
	void gl_onDebugMessage(
		GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const GLchar* message,
		const void* userParam)
	{
		switch (severity)
		{
		case GL_DEBUG_SEVERITY_NOTIFICATION:
			FSGL_CORE_INFO("OpenGL[NOTIFICATION]: {0}", message);
			break;

		case GL_DEBUG_SEVERITY_LOW:
			FSGL_CORE_WARN("OpenGL[LOW]: {0}", message);
			break;

		case GL_DEBUG_SEVERITY_MEDIUM:
			FSGL_CORE_ERROR("OpenGL[MEDIUM]: {0}", message);
			break;

		case GL_DEBUG_SEVERITY_HIGH:
			FSGL_CORE_CRITICAL("OpenGL[HIGH]: {0}", message);
			break;

		default:
			FSGL_CORE_CRITICAL("Unkown OpenGL severity level!");
			assert(false);
			break;
		}
	}
}



fsgl::impl::OpenGL_GraphicsAPI::OpenGL_GraphicsAPI() :
	GraphicsAPI(GraphicsAPI::API::OpenGL)
{

}

fsgl::impl::OpenGL_GraphicsAPI::~OpenGL_GraphicsAPI()
{

}

void fsgl::impl::OpenGL_GraphicsAPI::init()
{
	// Enable GLAD
	const int version = gladLoadGL(glfwGetProcAddress);
	FSGL_CORE_INFO("GLAD: Successfully loaded glfw proc adress");

	// Enable OpenGL debugging
	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageCallback(&gl_onDebugMessage, nullptr);
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, nullptr, GL_FALSE);

	FSGL_CORE_INFO("OpenGL info:");
	FSGL_CORE_INFO("-\tVendor: {0}", (const char*)glGetString(GL_VENDOR));
	FSGL_CORE_INFO("-\tRenderer: {0}", (const char*)glGetString(GL_RENDERER));
	FSGL_CORE_INFO("-\tVersion: {0}", (const char*)glGetString(GL_VERSION));
}

void fsgl::impl::OpenGL_GraphicsAPI::setClearColor(const glm::vec4& color) const
{
	glClearColor(color.r, color.g, color.b, color.a);
}

void fsgl::impl::OpenGL_GraphicsAPI::clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void fsgl::impl::OpenGL_GraphicsAPI::viewport(const std::int32_t x, const std::int32_t y, const std::int32_t width, const std::int32_t height) const
{
	glViewport(x, y, width, height);
}

void fsgl::impl::OpenGL_GraphicsAPI::draw(const std::shared_ptr<VertexArray>& vao) const
{
	vao->bind();
	glDrawElements(GL_TRIANGLES, vao->getIndexBuffer()->count(), GL_UNSIGNED_INT, nullptr);
}
