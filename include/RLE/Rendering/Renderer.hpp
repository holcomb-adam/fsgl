#pragma once

// --- External
#include <glm/mat4x4.hpp>

// --- Standard ---
#include <memory>



namespace rle
{
	// RLE Forward Declarations
	class Camera;
	class Renderable;
	class Shader;
	class VertexArray;



	class Renderer final
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		Renderer() = default;

		// Default destructor
		~Renderer() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - OPERATIONS ----------------------------------------------------------------

		// Begin a scene
		void beginScene(const std::unique_ptr<Camera>& camera);

		// End the scene
		void endScene();

		// Submit an object for rendering
		void submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vao);

		// Submit an object for rendering
		void submit(const Renderable& renderable);



	private:
		glm::mat4 m_ViewProjection;
	};
}
