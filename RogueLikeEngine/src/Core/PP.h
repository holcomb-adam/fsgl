#pragma once

// Preprocessor Directives

// Enabling Windows 10 64 bit support
// Make sure correct preprocessor macros are defined for correct platform support!
// Non-defined platforms may result in undefined behavior so error is result
#ifdef RLE_WIN64_SUPPORT
	#ifdef RLE_DEBUG
	#elif RLE_RELEASE
	#else
		#error Windows 64 bit only supports debug and release modes!
	#endif // RLE_DEBUG

#endif // RLE_WIN64_SUPPORT

