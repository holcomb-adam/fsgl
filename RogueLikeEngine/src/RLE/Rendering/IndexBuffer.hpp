#pragma once

// --- Standard ---
#include <memory>

// --- RLE ---
#include "RLE/Core/Factory.hpp"



namespace rle
{
	class IndexBuffer
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		IndexBuffer() = default;

		// Virtual default destructor
		virtual ~IndexBuffer() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - PURE VIRTUALS -------------------------------------------------------------

		// Get the number of verticies that are in the buffer
		virtual std::uint32_t count() const = 0;

		// Bind the buffer to the renderer
		virtual void bind() const = 0;

		// Unbind the buffer from the renderer
		virtual void unbind() const = 0;
	};





	/// <summary>
	/// Specialized factory methods for retrieving an IndexBuffer from the rendering API
	/// </summary>
	template<>
	struct factory<IndexBuffer> final
	{
		static std::shared_ptr<IndexBuffer> create(const std::uint32_t* indicies, const std::uint32_t count);
	};
}
