#include "RLEpch.hpp"
#include "RLE/Core/Time.hpp"



rle::time::point rle::time::now()
{
	return std::chrono::time_point_cast<step_ms>(clock::now());
}
