#pragma once

#include "Math/Constants.h"



namespace rle
{
	namespace math
	{
		template<class T>
		inline constexpr T degToRad(const T deg)
		{
			return deg / T{ 180.0 } * T{ constants::PI };
		}



		template<class T>
		inline constexpr T radToDeg(const T rad)
		{
			return rad / T{ constants::PI } * T{ 180.0 };
		}
	}
}