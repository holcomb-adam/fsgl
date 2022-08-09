#pragma once

// This file serves as an engine standard to the template madness that is std::chrono

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

		// A nice type alias for std::chrono::duration<double, std::milli>
		// - This represents a floating point (double) time step_ms in milliseconds 
		using step_ms = std::chrono::duration<double, std::milli>;

		// Type alias for representing 1 second
		// - Prefer using this alias over 'std::chrono::seconds' as the time is
		//   represented using a floating point double rather than the standard 
		//   implementation which represents the time as long long
		using step_sec = std::chrono::duration<double>;

		// Type alias for std::chrono::time_point<clock, time_step>
		using point = std::chrono::time_point<clock, step_ms>;



		////////////////////////////////////////////////////////////////////////////////
		// - GETTERS -------------------------------------------------------------------

		// Get the current time point
		point now();
	}
}
