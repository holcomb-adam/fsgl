#pragma once

// --- External ---
#include <glm/vec4.hpp>

// --- Standard ---
#include <memory>

// --- RLE ---
#include "RLE/Rendering/RenderingAPI.hpp"



namespace rle
{
	// RLE Forward Declarations
	class VertexArray;



	namespace RenderCommands
	{
		// Initialize the rendering command system
		void init(const RenderingAPI::API api);

		// Set the color to clear the screen with
		void setClearColor(const glm::vec4& color);

		// TODO: Eventually needs to take flags
		// Clear the screen
		void clear();

		// Specify the API viewport
		void viewport(
			const std::int32_t x,
			const std::int32_t y,
			const std::int32_t width,
			const std::int32_t height);

		// Draw a vertex array object
		void draw(const std::shared_ptr<VertexArray>& vao);
	}
}
