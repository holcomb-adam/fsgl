#pragma once

#include "Core/PP.h" // preprocessor compatibility

#include <string>



// a few defines...
// Logging is disabled in release mode
// Logging can be enabled with special release mode with macro defined
#ifdef RLE_DEBUG
	#define RLE_LOGGING
#endif // RLE_DEBUG

// define rle logging macro "functions"
#ifdef RLE_LOGGING
	#define RLE_LOG_INIT(path) \
		rle::log::detail::init(path)

	#define RLE_LOG_OUT(severity, msg) \
		rle::log::detail::out(severity, msg)
#else
	#define RLE_LOG_OPEN(...) true
	#define RLE_LOG_OUT(...)
#endif // RLE_LOGGING



namespace rle
{
	namespace log
	{
		constexpr std::uint8_t INFO = 0;
		constexpr std::uint8_t WARN = 1;
		constexpr std::uint8_t ERR  = 2;

		// basic for now
		constexpr auto GENERAL_PATH = "log.txt";



#ifdef RLE_LOGGING

		namespace detail
		{
			bool init(const std::string& path);
			void out(const std::uint8_t severity, const std::string& msg);
		}

#endif // RLE_LOGGING
	}
}
