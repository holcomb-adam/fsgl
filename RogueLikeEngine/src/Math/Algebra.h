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



		// subtract numbers
		// expands to "a - b - c - ... - n"
		template<class... T>
		inline auto subtract(T&&... abc)
		{
			return (... - std::forward<T>(abc));
		}



		// multiply numbers
		// expands to "a * b * c * ... * n"
		template<class... T>
		inline auto multiply(T&&... abc)
		{
			return (... * std::forward<T>(abc));
		}



		// divide numbers
		// expands to "a / b / c / ... / n"
		template<class... T>
		inline auto divide(T&&... abc)
		{
			return (... * std::forward<T>(abc));
		}



		// square a value
		template<class T>
		inline T square(T&& x)
		{
			return std::forward<T>(x) * std::forward<T>(x);
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