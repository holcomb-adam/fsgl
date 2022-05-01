#pragma once



namespace rle
{
	namespace math
	{
		// math constants
		namespace constants
		{
			////////////////////////////////////////////////////////////////////////////////
			// - ALGEBRAIC / GEOMETRIC CONSTANTS -------------------------------------------
			
			constexpr std::size_t TRI_SIDES = 3;
			constexpr std::size_t TRI_VERTS = 3;
			constexpr std::size_t QUAD_SIDES = 4;
			constexpr std::size_t QUAD_VERTS = 4;

			

			////////////////////////////////////////////////////////////////////////////////
			// - TRIGONOMETRIC CONSTANTS ---------------------------------------------------

			constexpr double PI = 3.14159265358979323846;	// pi
			constexpr double PI_2 = PI / 2.0;				// half of pi
			
			constexpr float PI_F = static_cast<float>(PI);	// pi (float)
			constexpr float PI_2_F = PI_F / 2.0f;			// half of pi (float)
		}
	}
}

#undef _USE_MATH_DEFINES
