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
			// - Generates an underlying OpenGL VBO populated with data
			// - 'data': The vertex data to be copied into the underlying VBO
			// - 'size': The number of elements the vertex buffer allocates
			OpenGL_VertexBuffer(const void* data, const std::size_t size);

			// Destructor
			// - Destroys the underlying VBO
			~OpenGL_VertexBuffer();



			////////////////////////////////////////////////////////////////////////////////
			// - OVERRIDES -----------------------------------------------------------------

			// Inherited via VertexBuffer
			virtual void bind() const;
			virtual void unbind() const;
			virtual void setData(const void* data, const std::size_t size);



		private:
			std::uint32_t m_ID = 0;
		};
	}
}
