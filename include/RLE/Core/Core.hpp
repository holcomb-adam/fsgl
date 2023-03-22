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

// Check system OS
// Create system specific defines
#   if defined(_WIN64)
#       define RLE_OS_WIN64
#       define RLE_FUNCSIG __FUNCSIG__
#   elif defined(__linux__)
#       define RLE_OS_LINUX
#       define RLE_FUNCSIG __func__
#	else
#		error Rouge-like Engine currently only supports Windows and Linux systems!
#   endif

// Check external APIs
#   if !defined(RLE_API_WINDOW_NONE) // Compile RLE with windowing
#       define RLE_API_WINDOW_GLFW
#   endif



////////////////////////////////////////////////////////////////////////////////
// - RLE UTILITY MACROS --------------------------------------------------------

// Set the bit of an integral type
// - 9 [00001001] == RLE_BIT(3) | RLE_BIT(0)
#	define RLE_BIT(n) 1ULL << n

// Stringize an argument
// - For brevity's sake
#	define RLE_STRINGIZE(arg) #arg

// Color constant macros
// - Produces a comma separated list
#	define RLE_WHITE 1.0f, 1.0f, 1.0f // White
#	define RLE_BLACK 0.0f, 0.0f, 0.0f // Black
#	define RLE_RED   1.0f, 0.0f, 0.0f // Red
#	define RLE_GREEN 0.0f, 1.0f, 0.0f // Green
#	define RLE_BLUE  0.0f, 0.0f, 1.0f // Blue

// Macro to help with event functions
// This will bind a function with "this" keyword and 1 placeholder argument
#	define RLE_BIND_THIS_FN(fn, ...) std::bind(&fn, this, __VA_ARGS__)



namespace rle
{
    namespace core
    {
        // Return whether core is initialized or not
        bool isCoreInitialized();
        
        // Initialize core components of the RLE engine
        bool initialize();
    }
}