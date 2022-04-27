#pragma once

#include <cstdint>
#include <string>



namespace rle
{
	namespace version
	{
		////////////////////////////////////////////////////////////////////////////////
		// - BUILD VERSION -------------------------------------------------------------

		// the major build number of the Rogue-like Engine
		constexpr std::uint8_t MAJOR = 0;

		// the minor build number of the Rogue-like Engine
		constexpr std::uint8_t MINOR = 0;

		// the current patch number since last minor/major update
		constexpr std::uint8_t PATCH = 0;



		////////////////////////////////////////////////////////////////////////////////
		// - VERSION UTILITIES ---------------------------------------------------------

		// version number as a concatenated string of numbers
		// i.e. "1203"
		constexpr std::uint64_t CAT_BUILD_VER = MAJOR * 100 + MINOR * 10 + PATCH;
	}
}
