#pragma once

// --- External ---
#include <glm/mat4x4.hpp>

// --- Standard ---
#include <string>



namespace rle
{
	class ShaderHandle
	{
	public:
		/// @brief 
		/// @param vertex_src 
		/// @param fragment_src 
		/// @return 
		static std::shared_ptr<ShaderHandle> make(const std::string& vertex_src,
											const std::string& fragment_src);



	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		ShaderHandle() = default;

		// Virtual default destructor
		virtual ~ShaderHandle() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - PURE VIRTUALS -------------------------------------------------------------

		// Bind the shader to underlying rendering API
		virtual void bind() const = 0;

		// Unbind the shader from the underlying rendering API
		virtual void unbind() const = 0;

		/// @brief 
		/// @param name 
		/// @param matrix 
		virtual void uploadUniform(const std::string& name, const glm::mat4& matrix) = 0;
	};
}
