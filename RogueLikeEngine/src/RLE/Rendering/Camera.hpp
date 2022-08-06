#pragma once

// --- External ---
#include <glm/mat4x4.hpp>

// --- Standard ---
#include <memory>

// --- RLE ---
#include "RLE/Core/Factory.hpp"



namespace rle
{
	// FIXME: This sort of represents a 2D camera
	//        - Only for testing the renderer
	class Camera final
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		Camera(const glm::mat4& proj, const glm::vec3& position = { 0.0f, 0.0f, 0.0f });

		// Virtual default destructor
		virtual ~Camera() = default;
		 


		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS / SETTERS ---------------------------------------------------------

		// Get the position of the camera
		const glm::vec3& position() const;

		// Set the position of the camera
		void setPosition(const glm::vec3& position);

		// Get the rotation of the camera
		float rotation() const;

		// Set the rotation of the camera
		void setRotation(const float degrees);

		// Get the projection matrix
		const glm::mat4& projectionMatrix() const;

		// Calculate the view projection matrix
		glm::mat4 calcViewProjectionMatrix() const;



	private:
		glm::mat4 m_Projection;
		glm::vec3 m_Position;

		float m_Rotation = 0.0f;
	};





	////////////////////////////////////////////////////////////////////////////////
	// - FACTORY METHODS -----------------------------------------------------------

	template<>
	struct factory<Camera> final
	{
		static std::unique_ptr<Camera> make_orthographic(
			const float x_min,
			const float x_max,
			const float y_min,
			const float y_max,
			const float z_near = -1.0f,
			const float z_far = 1.0f);
	};
}
