#pragma once

// --- SPDLOG ---
#pragma warning(push, 0) // Disable MSVC warnings for external libs
#	include <spdlog/spdlog.h>
#pragma warning(pop)

// --- Standard ---
#include <memory>

// --- fsgl ---
#include "fsgl/Core/Core.hpp"



namespace fsgl
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
#define FSGL_CORE_TRACE(...) ::fsgl::log::coreLogger()->trace(__VA_ARGS__)
#define FSGL_CORE_INFO(...) ::fsgl::log::coreLogger()->info(__VA_ARGS__)
#define FSGL_CORE_WARN(...) ::fsgl::log::coreLogger()->warn(__VA_ARGS__)
#define FSGL_CORE_ERROR(...) ::fsgl::log::coreLogger()->error(__VA_ARGS__)
#define FSGL_CORE_CRITICAL(...) ::fsgl::log::coreLogger()->critical(__VA_ARGS__)

// Client Logging Macros...
#define FSGL_TRACE(...) ::fsgl::log::clientLogger()->trace(__VA_ARGS__)
#define FSGL_INFO(...) ::fsgl::log::clientLogger()->info(__VA_ARGS__)
#define FSGL_WARN(...) ::fsgl::log::clientLogger()->warn(__VA_ARGS__)
#define FSGL_ERROR(...) ::fsgl::log::clientLogger()->error(__VA_ARGS__)
#define FSGL_CRITICAL(...) ::fsgl::log::clientLogger()->critical(__VA_ARGS__)

