#pragma once

// --- Standard ---
#include <cstdint>

// --- RLE ---
#include "RLE/Rendering/FrameBuffer.hpp"



namespace rle
{
	namespace impl
	{
		class OpenGL_FrameBuffer final : public FrameBuffer
		{
		public:
			////////////////////////////////////////////////////////////////////////////////
			// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

			// Constructor
			OpenGL_FrameBuffer(const std::uint32_t width, const std::uint32_t height);

			// Destructor
			~OpenGL_FrameBuffer();



			////////////////////////////////////////////////////////////////////////////////
			// - OVERRIDES -----------------------------------------------------------------

			// Inherited via FrameBuffer
			virtual void bind() const override;
			virtual void unbind() const override;
			virtual std::uint32_t texture() const override;
			virtual void resizeTexture(const std::uint32_t width, const std::uint32_t height) override;



		private:
			std::uint32_t m_ID = 0;

			// TEMP: We dont have a texture class yet
			// TEMP: Only creates 1 texture
			std::uint32_t m_TextureID = 0;
		};
	}
}