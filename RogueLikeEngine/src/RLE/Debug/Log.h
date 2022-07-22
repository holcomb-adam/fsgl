#pragma once

// External Library includes
#include <spdlog/spdlog.h>

// Standard Library includes
#include <memory>

// RLE Library includes
#include "RLE/Core/Core.h"



namespace rle
{
	namespace log
	{
		// Initialize logging system
		void init();

		// Get the Rogue-like Engine logger
		// - This is utilized by the engine for debugging purposes
		// - Should not be used by client applications (see: 'clientLogger')
		std::shared_ptr<spdlog::logger>& coreLogger();



		// Get the client logger
		// - This logger is provided as a means to debugging client applications
		std::shared_ptr<spdlog::logger>& clientLogger();
	}
}



// Core Logging Macros...
#define RLE_CORE_TRACE(...) ::rle::log::coreLogger()->trace(__VA_ARGS__)
#define RLE_CORE_INFO(...) ::rle::log::coreLogger()->info(__VA_ARGS__)
#define RLE_CORE_WARN(...) ::rle::log::coreLogger()->warn(__VA_ARGS__)
#define RLE_CORE_ERROR(...) ::rle::log::coreLogger()->error(__VA_ARGS__)
#define RLE_CORE_CRITICAL(...) ::rle::log::coreLogger()->critical(__VA_ARGS__)

// Client Logging Macros...
#define RLE_TRACE(...) ::rle::log::clientLogger()->trace(__VA_ARGS__)
#define RLE_INFO(...) ::rle::log::clientLogger()->info(__VA_ARGS__)
#define RLE_WARN(...) ::rle::log::clientLogger()->warn(__VA_ARGS__)
#define RLE_ERROR(...) ::rle::log::clientLogger()->error(__VA_ARGS__)
#define RLE_CRITICAL(...) ::rle::log::clientLogger()->critical(__VA_ARGS__)

