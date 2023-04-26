#pragma once

// --- RLE ---
#include "RLE/Core/Factory.hpp"



namespace rle
{
	// --- Forward Declarations ---
	class Vertex2D;



	/// @brief 
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

		/// @brief Set the data of the VBO
		/// @param data C-style array of vertex data being moved to the GPU
		/// @param count Number of vertices being copied from the vector
		virtual void setData(const Vertex2D* data, const std::size_t count) = 0;
	};



	////////////////////////////////////////////////////////////////////////////////
	// - FACTORY METHODS -----------------------------------------------------------

	/// @brief Specialized factory methods for retrieving a VertexBuffer from the rendering API
	template<>
	struct factory<VertexBuffer>
	{
		/// @brief Creates a vertex buffer object from the current rendering API
		/// @param count Number of vertices to allocate on the GPU
		/// @return A unique_ptr containing the vertex buffer object
		static std::shared_ptr<VertexBuffer> create(const std::size_t count);

		/// @brief Creates a vertex buffer object from the current rendering API
		/// @param data C-style array of vertex data being moved to the GPU
		/// @param count Number of vertices to copy to the GPU
		/// @return A unique_ptr containing the vertex buffer object
		static std::shared_ptr<VertexBuffer> create(const Vertex2D* data, const std::size_t size);
	};
}
