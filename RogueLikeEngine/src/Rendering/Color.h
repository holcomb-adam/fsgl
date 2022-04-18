#pragma once

#include <cstdint>



namespace rle
{
	// defines an rgba color
	struct Color final
	{
		// default ctor
		inline Color() = default;

		// ctor
		// takes red, green, blue and alpha channel parameters
		// constexpr contructor for constexpr colors!
		inline constexpr Color(const std::uint8_t r, const std::uint8_t g,
			const std::uint8_t b, const std::uint8_t a = 255) noexcept :
			red(r),
			green(g),
			blue(b),
			alpha(a)
		{ }

		// default dtor
		~Color() = default;



		// color channels
		std::uint8_t red = 0;
		std::uint8_t green = 0;
		std::uint8_t blue = 0;
		std::uint8_t alpha = 255;
	};



	// colors namespace
	namespace color_constants
	{
		////////////////////////////////////////////////////////////////////////////////
		// - USEFUL COLOR CONSTANTS ----------------------------------------------------
		constexpr Color WHITE = { 255, 255, 255 };
		constexpr Color BLACK = { 0, 0, 0 };
	}
}
