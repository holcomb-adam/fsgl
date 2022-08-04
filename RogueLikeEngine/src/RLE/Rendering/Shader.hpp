#pragma once

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

		// ind the shader to underlying rendering API
		virtual void unbind() const = 0;
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
