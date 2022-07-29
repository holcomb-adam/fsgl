#pragma once

// Standard Library includes
#include <memory>

// RLE Library includes
#include "RenderingAPI.h"



namespace rle
{
	class RenderingContext
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - STATIC MEMBERS ------------------------------------------------------------

		// Get a rendering context from the desired api
		static std::unique_ptr<RenderingContext> create(const RenderingAPI api, void* win_handle);

	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		RenderingContext() = default;

		// Virtual default destructor
		virtual ~RenderingContext() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - PURE VIRTUALS -------------------------------------------------------------

		// Initialize the underlying api
		virtual void init() = 0;

		// Swap the rendering buffer
		virtual void swapBuffers() = 0;
	};
}
