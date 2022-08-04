#pragma once



namespace rle
{
	// "POD" style struct with a constructor
	// - Holds color clamp values
	// - Can be extended for certain conversions i.e. to_RGBA()
	struct Color final
	{
		////////////////////////////////////////////////////////////////////////////////
		// - PUBLIC DATA ---------------------------------------------------------------

		// Respective color channel clamp values
		float red = 0.0f;
		float green = 0.0f;
		float blue = 0.0f;
		float alpha = 0.0f;



		////////////////////////////////////////////////////////////////////////////////
		// - CONSTRUCTORS / DESTRUCTORS ------------------------------------------------

		// Constructor, takes ARGB clamp values
		/*inline explicit Color(
			const float clamp_a,
			const float clamp_r,
			const float clamp_g,
			const float clamp_b) : 
			alpha(clamp_a),
			red(clamp_r),
			green(clamp_g),
			blue(clamp_b) {}*/
	};
}