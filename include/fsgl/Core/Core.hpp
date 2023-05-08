#pragma once

// Preprocessor Directives



////////////////////////////////////////////////////////////////////////////////
// - C++ COMPILER --------------------------------------------------------------

// Ensure we are using a valid C++ compiler
#	if !defined(__cplusplus)
#		error C++ compiler required.
#	endif



////////////////////////////////////////////////////////////////////////////////
// - FSGL API DEFINES -----------------------------------------------------------

// Check system OS
// Create system specific defines
#   if defined(_WIN64)
#       define FSGL_OS_WIN64
#       define FSGL_FUNCSIG __FUNCSIG__
#   elif defined(__linux__)
#       define FSGL_OS_LINUX
#       define FSGL_FUNCSIG __func__
#	else
#		error Rouge-like Engine currently only supports Windows and Linux systems!
#   endif

// Check external APIs
#   if !defined(FSGL_API_WINDOW_NONE) // Compile FSGL with windowing
#       define FSGL_API_WINDOW_GLFW
#   endif



////////////////////////////////////////////////////////////////////////////////
// - FSGL UTILITY MACROS --------------------------------------------------------

// Set the bit of an integral type
// - 9 [00001001] == FSGL_BIT(3) | FSGL_BIT(0)
#	define FSGL_BIT(n) 1ULL << n

// Stringize an argument
// - For brevity's sake
#	define FSGL_STRINGIZE(arg) #arg

// Color constant macros
// - Produces a comma separated list
#	define FSGL_WHITE 1.0f, 1.0f, 1.0f // White
#	define FSGL_BLACK 0.0f, 0.0f, 0.0f // Black
#	define FSGL_RED   1.0f, 0.0f, 0.0f // Red
#	define FSGL_GREEN 0.0f, 1.0f, 0.0f // Green
#	define FSGL_BLUE  0.0f, 0.0f, 1.0f // Blue

#   define FSGL_BUFFER_CLEAR_COLOR 1.0f, 0.0f, 1.0f // Rendering buffer clear color. Magenta

// Macro to help with event functions
// This will bind a function with "this" keyword and 1 placeholder argument
#	define FSGL_BIND_THIS_FN(fn, ...) std::bind(&fn, this, __VA_ARGS__)



namespace fsgl
{
    namespace core
    {
        // Return whether core is initialized or not
        bool isCoreInitialized();
        
        // Initialize core components of the FSGL engine
        bool initialize();
    }
}
