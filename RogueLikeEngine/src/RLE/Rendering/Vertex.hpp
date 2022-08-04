#pragma once

// --- External ---
#include <glm/vec3.hpp>

// --- RLE ---
#include "Color.hpp"



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

		// Color at the vertex
		Color color;
	};
}
