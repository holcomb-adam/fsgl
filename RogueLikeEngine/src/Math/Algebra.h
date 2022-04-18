#pragma once

#include <cmath>



namespace rle
{
	namespace math
	{
		// add numbers together
		template<class... T>
		inline auto add(T&&... abc)
		{
			return (... + std::forward<T>(abc));
		}



		// square a value
		template<class T>
		inline T square(T&& x)
		{
			return x * x;
		}



		// euclidean distance formula, optimized distance formula
		// by removing the square root step
		template<class... T>
		inline auto euclidDist(T&&... xyz)
		{
			return add(std::forward<T>(square(xyz))...);
		}



		// distance formula
		template<class... T>
		inline auto distance(T&&... xyz)
		{
			return sqrt(euclidDist(std::forward<T>(xyz)...));
		}
	}
}