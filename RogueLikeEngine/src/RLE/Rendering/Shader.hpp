#pragma once

// --- External ---
#include <glm/mat4x4.hpp>

// --- Standard ---
#include <string>

// --- RLE ---
#include "RLE/Core/Factory.hpp"



namespace rle
{
	class Shader
	{
	public:
		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Default constructor
		Shader() = default;

		// Virtual default destructor
		virtual ~Shader() = default;



		////////////////////////////////////////////////////////////////////////////////
		// - PURE VIRTUALS -------------------------------------------------------------

		// Bind the shader to underlying rendering API
		virtual void bind() const = 0;

		// Unbind the shader from the underlying rendering API
		virtual void unbind() const = 0;

		// Upload Matrix 4x4 uniform
		virtual void uploadUniform(const std::string& name, const glm::mat4& matrix) = 0;
	};





	////////////////////////////////////////////////////////////////////////////////
	// - FACTORY METHODS -----------------------------------------------------------

	template<>
	struct factory<Shader> final
	{
		// Creates and compiles a shader program 
		static std::shared_ptr<Shader> create(const std::string& vertex_src, const std::string& fragment_src);
	};
}
