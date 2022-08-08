#pragma once

// --- Standard ---
#include <memory>



namespace rle
{
	// RLE Forward Declarations
	class VertexArray;
	struct Color;



	class RenderingAPI
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - MEMBER TYPES --------------------------------------------------------------
		
		// An enum representing the underlying graphics API
		enum class API
		{
			None,
			OpenGL
		};



	public:
		////////////////////////////////////////////////////////////////////////////////
		// - PUBLIC STATIC MEMBERS -----------------------------------------------------

		// Get the API
		static API api();



	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		RenderingAPI(const API api);

		// Virtual default destructor
		virtual ~RenderingAPI() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - PURE VIRTUALS -------------------------------------------------------------

		// Perform any neccesary initialization for the underlying API
		virtual void init() = 0;

		// Set the color to clear the screen with
		virtual void setClearColor(const Color& color) const = 0;

		// Clear the screen
		virtual void clear() const = 0;

		// Specify the Api viewport
		virtual void viewport(
			const std::int32_t x,
			const std::int32_t y,
			const std::int32_t width,
			const std::int32_t height) const = 0;

		// Draw a vertex array object
		virtual void draw(const std::shared_ptr<VertexArray>& vao) const = 0;



	private:
		inline static API s_API = API::None;
	};
}
