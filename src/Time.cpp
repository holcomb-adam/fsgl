#include "fsgl_pch.hpp"
#include "fsgl/Core/Time.hpp"



fsgl::time::point fsgl::time::now()
{
	return std::chrono::time_point_cast<step_ms>(clock::now());
}
