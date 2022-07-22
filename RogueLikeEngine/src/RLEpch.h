#pragma once

// RLE Precompiled Header



// Avoid compiler issues with windows headers
#	if defined(RLE_OS_WIN64) && !defined(NOMINMAX)
#		define NOMINMAX
#	endif



// Standard Library data structures
#include <string>
#include <unordered_map>
#include <vector>



// Standard Library utilities
#include <algorithm>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>



// Win32 API header
#	if defined(RLE_OS_WIN64)
#		include <Windows.h>
#	endif
