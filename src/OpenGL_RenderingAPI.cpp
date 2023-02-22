#include "RLEpch.hpp"
#include "impl/API/OpenGL/OpenGL_RenderingAPI.hpp"

// --- GLAD ---
#include <glad/gl.h>

// --- GLFW ---
#include <GLFW/glfw3.h>

// --- RLE ---
#include "RLE/Debug/Log.hpp"
#include "RLE/Rendering/IndexBuffer.hpp"
#include "RLE/Rendering/VertexArray.hpp"



namespace
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
			RLE_CORE_INFO("OpenGL[NOTIFICATION]: {0}", message);
			break;

		case GL_DEBUG_SEVERITY_LOW:
			RLE_CORE_WARN("OpenGL[LOW]: {0}", message);
			break;

		case GL_DEBUG_SEVERITY_MEDIUM:
			RLE_CORE_ERROR("OpenGL[MEDIUM]: {0}", message);
			break;

		case GL_DEBUG_SEVERITY_HIGH:
			RLE_CORE_CRITICAL("OpenGL[HIGH]: {0}", message);
			break;

		default:
			RLE_CORE_CRITICAL("Unkown OpenGL severity level!");
			assert(false);
			break;
		}
	}
}



rle::impl::OpenGL_RenderingAPI::OpenGL_RenderingAPI() :
	RenderingAPI(RenderingAPI::API::OpenGL)
{

}

rle::impl::OpenGL_RenderingAPI::~OpenGL_RenderingAPI()
{

}

void rle::impl::OpenGL_RenderingAPI::init()
{
	// Enable GLAD
	const int version = gladLoadGL(glfwGetProcAddress);
	RLE_CORE_INFO("GLAD: Successfully loaded glfw proc adress");

	// Enable OpenGL debugging
	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageCallback(&gl_onDebugMessage, nullptr);
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, nullptr, GL_FALSE);

	RLE_CORE_INFO("OpenGL info:");
	RLE_CORE_INFO("-\tVendor: {0}", (const char*)glGetString(GL_VENDOR));
	RLE_CORE_INFO("-\tRenderer: {0}", (const char*)glGetString(GL_RENDERER));
	RLE_CORE_INFO("-\tVersion: {0}", (const char*)glGetString(GL_VERSION));
}

void rle::impl::OpenGL_RenderingAPI::setClearColor(const glm::vec4& color) const
{
	glClearColor(color.r, color.g, color.b, color.a);
}

void rle::impl::OpenGL_RenderingAPI::clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void rle::impl::OpenGL_RenderingAPI::viewport(const std::int32_t x, const std::int32_t y, const std::int32_t width, const std::int32_t height) const
{
	glViewport(x, y, width, height);
}

void rle::impl::OpenGL_RenderingAPI::draw(const std::shared_ptr<VertexArray>& vao) const
{
	vao->bind();
	glDrawElements(GL_TRIANGLES, vao->getIndexBuffer()->count(), GL_UNSIGNED_INT, nullptr);
}
