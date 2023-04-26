#pragma once

// --- Standard ---
#include <string>

// --- RLE ---
#include "RLE/Rendering/ShaderHandle.hpp"



namespace rle
{
	namespace impl
	{
		class OpenGL_ShaderHandle final : public rle::ShaderHandle
		{
		public:
			////////////////////////////////////////////////////////////////////////////////
			// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

			// Constructor
			// - 'vertex_src': Vertex shader source code
			// - 'fragment_src': Fragment shader source code
			OpenGL_ShaderHandle(const std::string& vertex_src, const std::string& fragment_src);

			// Destructor
			// - Deletes the OpenGL shader
			~OpenGL_ShaderHandle();



			////////////////////////////////////////////////////////////////////////////////
			// - OVERRIDES -----------------------------------------------------------------

			// Inherited via ShaderHandle
			virtual void bind() const override;
			virtual void unbind() const override;
			virtual void uploadUniform(const std::string& name, const glm::mat4& matrix) override;
			


		private:
			std::uint32_t m_ID = 0;
		};
	}
}
