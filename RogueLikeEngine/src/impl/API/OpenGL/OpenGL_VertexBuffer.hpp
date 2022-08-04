#pragma once

// Standard Library includes
#include <cstdint>

// RLE Library includes
#include "RLE/Rendering/VertexBuffer.hpp"



namespace rle
{
	namespace impl
	{
		class OpenGL_VertexBuffer final : public VertexBuffer
		{
		public:
			////////////////////////////////////////////////////////////////////////////////
			// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

			// Constructor
			// - Generates an underlying empty OpenGL VBO
			// - 'size': The size of the buffer in bytes to allocate
			OpenGL_VertexBuffer(const std::size_t size);

			// Constructor
			// - Generates an underlying OpenGL VBO populated with data
			// - 'size': The number of elements the vertex buffer allocates
			// - 'data': The vertex data to be copied into the VBO
			OpenGL_VertexBuffer(const std::size_t size, const Vertex* data);

			// Destructor
			// - Destroys the underlying VBO
			~OpenGL_VertexBuffer();



			////////////////////////////////////////////////////////////////////////////////
			// - OVERRIDES -----------------------------------------------------------------

			// Inherited via VertexBuffer
			virtual void bind() const;
			virtual void unbind() const;
			virtual void setData(const Vertex* data, const std::size_t size);



		private:
			// Initializes the OpenGL vertex buffer
			void init(const std::size_t size, const Vertex* data);



		private:
			std::uint32_t m_ID = 0;
		};
	}
}
