#pragma once

// RLE Library includes
#include "RLE/Rendering/IndexBuffer.hpp"



namespace rle
{
	namespace impl
	{
		class OpenGL_IndexBuffer : public IndexBuffer
		{
		public:
			////////////////////////////////////////////////////////////////////////////////
			// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

			// Constructor
			// - Generates an underlying OpenGL VBO for indicies
			// - 'count': The number of indices being copied
			// - 'indices': C-style array of indicies to be copied to the gpu
			OpenGL_IndexBuffer(const std::uint32_t count, const std::uint32_t* indices);

			// Destructor
			// - Destroys the underlying VBO
			~OpenGL_IndexBuffer();



			////////////////////////////////////////////////////////////////////////////////
			// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

			// Inherited via IndexBuffer
			virtual std::uint32_t count() const override;
			virtual void bind() const override;
			virtual void unbind() const override;



		private:
			std::uint32_t m_ID = 0;
			
			std::uint32_t m_Count = 0;
		};
	}
}
