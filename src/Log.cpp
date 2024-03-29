#include "fsgl_pch.hpp"
#include "fsgl/Debug/Log.hpp"

// --- SPDLOG ---
#include <spdlog/sinks/stdout_color_sinks.h>



namespace
{
	// Logger for the engine itself (core)
	static std::shared_ptr<spdlog::logger> s_CoreLogger;

	// Logger for the client application (client)
	static std::shared_ptr<spdlog::logger> s_ClientLogger;
}



void fsgl::log::init()
{
	spdlog::set_pattern("%^[%l]: [%Y-%m-%d %T] [%n] %v%$");
	
	// initialize the core logger
	s_CoreLogger = spdlog::stdout_color_mt("Rogue-Like");
	s_CoreLogger->set_level(spdlog::level::trace);

	// initialize the core logger
	s_ClientLogger = spdlog::stdout_color_mt("Client");
	s_ClientLogger->set_level(spdlog::level::trace);

    FSGL_CORE_INFO("Initialized logging system!");
}

std::shared_ptr<spdlog::logger>& fsgl::log::coreLogger()
{
	return s_CoreLogger;
}

std::shared_ptr<spdlog::logger>& fsgl::log::clientLogger()
{
	return s_ClientLogger;
}
