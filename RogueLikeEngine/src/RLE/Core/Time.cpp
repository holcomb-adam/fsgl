#include "RLEpch.h"
#include "Time.h"

rle::time::point rle::time::now()
{
	return std::chrono::time_point_cast<step_ms>(clock::now());
}
