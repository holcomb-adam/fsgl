#pragma once

#define _USE_MATH_DEFINES
#include <math.h>



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

			

			////////////////////////////////////////////////////////////////////////////////
			// - TRIGONOMETRIC CONSTANTS ---------------------------------------------------

			constexpr double PI = M_PI;						// pi
			constexpr double PI_2 = PI / 2.0;				// half of pi
			
			constexpr float PI_F = static_cast<float>(PI);	// pi (float)
			constexpr float PI_2_F = PI_F / 2.0f;			// half of pi (float)
		}
	}
}

#undef _USE_MATH_DEFINES
