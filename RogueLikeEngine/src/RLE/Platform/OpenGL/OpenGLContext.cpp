#include "RLEpch.h"
#include "OpenGLContext.h"

// Standard Library includes
#include <cassert>

// External Library includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>



rle::impl::OpenGLContext::OpenGLContext(GLFWwindow* glfw_win) : 
	m_Handle(glfw_win)
{
	
}

void rle::impl::OpenGLContext::init()
{
	glfwMakeContextCurrent(m_Handle);

	// Enable GLAD
	const int glad_success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	assert(glad_success);
}

void rle::impl::OpenGLContext::swapBuffers()
{
	glfwSwapBuffers(m_Handle);
}
