#pragma once

// Preprocessor Directives



////////////////////////////////////////////////////////////////////////////////
// - C++ COMPILER --------------------------------------------------------------

// Ensure we are using a valid C++ compiler
#	if !defined(__cplusplus)
#		error C++ compiler required.
#	endif





////////////////////////////////////////////////////////////////////////////////
// - RLE API DEFINES -----------------------------------------------------------

// Check the operating system
#	if defined(RLE_OS_WIN64)
#	else
#		error Rouge-like Engine only supports Windows!
#	endif





////////////////////////////////////////////////////////////////////////////////
// - RLE UTILITY MACROS --------------------------------------------------------

// Set the bit of an integral type
// - 9 [00001001] == RLE_BIT(3) | RLE_BIT(0)
#	define RLE_BIT(n) 1ULL << n

// Stringize and argument
// - For brevity's sake
#	define RLE_STRINGIZE(arg) #arg

// Macro to help with event functions
// This will bind a function with "this" keyword and 1 placeholder argument
#	define RLE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

// Color constant macros
// - Produces a comma separated list
#	define RLE_WHITE 1.0f, 1.0f, 1.0f // White
#	define RLE_BLACK 0.0f, 0.0f, 0.0f // Black
#	define RLE_RED   1.0f, 0.0f, 0.0f // Red
#	define RLE_GREEN 0.0f, 1.0f, 0.0f // Green
#	define RLE_BLUE  0.0f, 0.0f, 1.0f // Blue
