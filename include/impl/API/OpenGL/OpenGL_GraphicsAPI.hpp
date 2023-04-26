#pragma once

// RLE Library includes
#include "RLE/Rendering/GraphicsAPI.hpp"



// GLFW Forward Declarations
struct GLFWwindow;



namespace rle
{
	// RLE Forward Declarations
	class Window;



	namespace impl
	{
		class OpenGL_GraphicsAPI final : public GraphicsAPI
		{
		public:
			////////////////////////////////////////////////////////////////////////////////
			// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

			// Constructor
			OpenGL_GraphicsAPI();

			// Default destructor
			~OpenGL_GraphicsAPI();



			////////////////////////////////////////////////////////////////////////////////
			// - OVERRIDES -----------------------------------------------------------------

			// Inherited via GraphicsHandle
			virtual void init() override;
			virtual void setClearColor(const glm::vec4& color) const override;
			virtual void clear() const override;
			virtual void viewport(const std::int32_t x, const std::int32_t y, const std::int32_t width, const std::int32_t height) const override;
			virtual void draw(const std::shared_ptr<VertexArray>& vao) const override;
		};
	}
}
