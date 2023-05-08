#pragma once

// --- fsgl ---
#include "fsgl/Core/Factory.hpp"



namespace fsgl
{
	class FrameBuffer
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		FrameBuffer() = default;

		// Virtual default destructor
		virtual ~FrameBuffer() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - PURE VIRTUALS -------------------------------------------------------------

		// Bind to the renderer
		virtual void bind() const = 0;

		// Unbind from the renderer
		virtual void unbind() const = 0;

		// Get the id of the underlying texture
		virtual std::uint32_t texture() const = 0;

		// Resize the frame buffer texture
		virtual void resizeTexture(const std::uint32_t width, const std::uint32_t height) = 0;
	};





	////////////////////////////////////////////////////////////////////////////////
	// - FACTORY METHODS -----------------------------------------------------------

	template<>
	struct factory<FrameBuffer> final
	{
		static std::shared_ptr<FrameBuffer> create(const std::uint32_t width, const std::uint32_t height);
	};
}
