#pragma once

// This file serves as an engine standard to the template madness that is 
// std::chrono
// Note: std::chrono objects are still being used in RLE and these aliases
//       are not mandatory for RLE use

// --- Standard ---
#include <chrono>



namespace rle
{
	namespace time
	{
		////////////////////////////////////////////////////////////////////////////////
		// - USER DATA TYPES -----------------------------------------------------------

		// Type alias for std::chrono::steady_clock
		using clock = std::chrono::steady_clock;

		// Type alias for a time step
		template<class Period>
		using time_step = std::chrono::duration<double, Period>;

		// A nice type alias for std::chrono::duration<double, std::milli>
		// - This represents a floating point (double) time step_ms in milliseconds 
		using step_ms = time_step<std::milli>;

		// Type alias for representing a time step in seconds
		// - Prefer using this alias over 'std::chrono::seconds' as the time is
		//   represented using a floating point double rather than the standard 
		//   implementation which represents the time as long long
		using step_sec = time_step<std::ratio<1>>;

		// Type alias for std::chrono::time_point<clock, time_step>
		using point = std::chrono::time_point<clock, step_ms>;



		////////////////////////////////////////////////////////////////////////////////
		// - CONSTANTS -----------------------------------------------------------------

		// Time representation of 1 second defaulting in seconds
		template<class Period = std::ratio<1>>
		constexpr time_step<Period> s_1 = time_step<Period>(1.0);



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Get the current time point
		point now();
	}
}
