#pragma once

// --- RLE ---
#include "RLE/Core/Factory.hpp"



namespace rle
{
	class VertexBuffer
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		VertexBuffer() = default;

		// Virtual default constructor
		virtual ~VertexBuffer() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - PURE VIRTUALS -------------------------------------------------------------

		// Bind the data to the renderer api
		virtual void bind() const = 0;

		// Unbine the data from the renderer api
		virtual void unbind() const = 0;

		// Set the data of the VBO
		// - 'data':    Vector of vertice data being moved to the GPU
		// - 'size':    Number of vertice in the vector being moved
		virtual void setData(const void* data, const std::size_t size) = 0;
	};





	////////////////////////////////////////////////////////////////////////////////
	// - FACTORY METHODS -----------------------------------------------------------

	// Specialized factory methods for retrieving a VertexBuffer from the rendering API
	template<>
	struct factory<VertexBuffer> final
	{
		//	Creates a VertexBuffer from the current rendering API
		// - 'size': The size in bytes to allocate on the gpu
		// - Return: A unique_ptr to a VertexBuffer
		static std::shared_ptr<VertexBuffer> create(const std::size_t size);

		// Creates a VertexBuffer from the current rendering API
		// - 'data': A pointer to a c-style array of vertex data to be copied to the gpu
		// - 'size': The size in bytes to allocate on the gpu
		// - Return: A unique_ptr to a VertexBuffer
		static std::shared_ptr<VertexBuffer> create(const void* data, const std::size_t size);
	};
}
