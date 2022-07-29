#pragma once

// RLE Library includes
#include "RLE/Rendering/RenderingContext.h"



// GLFW Forward Declarations
struct GLFWwindow;



namespace rle
{
	namespace impl
	{
		class OpenGLContext final : public RenderingContext
		{ 
		public:
			////////////////////////////////////////////////////////////////////////////////
			// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

			// Default constructor
			OpenGLContext(GLFWwindow* glfw_win);

			// Default destructor
			~OpenGLContext() = default;



			////////////////////////////////////////////////////////////////////////////////
			// - PURE VIRTUALS -------------------------------------------------------------

			// Inherited via RenderingContext
			virtual void init() override;
			virtual void swapBuffers() override;



		private:
			GLFWwindow* m_Handle = nullptr;
		};
	}
}
