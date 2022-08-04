#pragma once

// --- Standard ---
#include <memory>

// --- RLE ---
#include "RLE/Rendering/RenderingAPI.hpp"



namespace rle
{
	// RLE Forward Declarations
	class VertexArray;
	struct Color;



	namespace RenderCommands
	{
		// Initialize the rendering command system
		void init(const RenderingAPI::API api);

		// Set the color to clear the screen with
		void setClearColor(const Color& color);

		// TODO: Eventually needs to take flags
		// Clear the screen
		void clear();

		// Draw a vertex array object
		void draw(const std::shared_ptr<VertexArray>& vao);
	}
}
