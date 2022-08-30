#pragma once

// --- External ---
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>



namespace rle
{
	// This represents the vertex data being passed to the GPU from the engine to
	// the rendering API.
	struct Vertex final
	{
		////////////////////////////////////////////////////////////////////////////////
		// - PUBLIC DATA ---------------------------------------------------------------

		// NDC position
		glm::vec3 position;

		// RGB color at the vertex
		glm::vec4 color;

		// Coordinates of the 2D texture at the vertex
		glm::vec2 texture_coords;
	};
}
