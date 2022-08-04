#pragma once

// --- Standard ---
#include <memory>

// --- RLE ---
#include "RLE/Core/Factory.hpp"



namespace rle
{
	// RLE Forward Declarations
	class IndexBuffer;
	class VertexBuffer;



	class VertexArray
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		VertexArray() = default;

		// Virtual default destructor
		virtual ~VertexArray() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - PURE VIRTUALS -------------------------------------------------------------

		// Bind to the renderer
		virtual void bind() const = 0;

		// Unbind from the renderer
		virtual void unbind() const = 0;

		// Add a Vertex buffer to the array
		// - 'vertex_buffer': Shared pointer to the vertex buffer being added
		virtual void addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertex_buffer) = 0;

		// Set the index buffer of the array
		virtual void setIndexBuffer(const std::shared_ptr<IndexBuffer>& index_buffer) = 0;

		// Get a constant reference to a shared pointer to the index buffer
		virtual const std::shared_ptr<IndexBuffer>& getIndexBuffer() const = 0;
	};





	////////////////////////////////////////////////////////////////////////////////
	// - FACTORY METHODS -----------------------------------------------------------

	template<>
	struct factory<VertexArray> final
	{
		static std::shared_ptr<VertexArray> create();
	};
}
