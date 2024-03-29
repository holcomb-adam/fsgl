#pragma once

// --- fsgl ---
#include "fsgl/Rendering/VertexArray.hpp"



namespace fsgl
{
	namespace impl
	{
		class OpenGL_VertexArray final : public VertexArray
		{
		public:
			////////////////////////////////////////////////////////////////////////////////
			// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

			// Constructor
			// - Creates an underlying OpenGL vertex array
			OpenGL_VertexArray();

			// Destructor
			// - Destroys the underlying OpenGL vertex array
			~OpenGL_VertexArray();



			////////////////////////////////////////////////////////////////////////////////
			// - OVERRIDES -----------------------------------------------------------------
			
			// Inherited via VertexArray
			virtual void bind() const override;
			virtual void unbind() const override;
			virtual void addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertex_buffer) override;
			virtual void setIndexBuffer(const std::shared_ptr<IndexBuffer>& index_buffer) override;



		private:
			std::uint32_t m_ID = 0;

			std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
			std::shared_ptr<IndexBuffer> m_IndexBuffer;

			// Inherited via VertexArray
			virtual const std::shared_ptr<IndexBuffer>& getIndexBuffer() const override;
		};
	}
}
