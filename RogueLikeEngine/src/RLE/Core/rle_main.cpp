// This file contains the entry point of the Rogue-like Engine

#include "RLEpch.hpp"

// --- RLE ---
#include "RLE.hpp" // RLE main header
#include "Core.hpp"
#include "RLE/Debug/Log.hpp"



#	if defined(RLE_OS_WIN64)

int main(int argc, char* argv[])
{
	// Initialize logging system
	rle::log::init();
	RLE_CORE_INFO("Initialized Logging System!");

	// Create the engine application
	auto* client = rle::entry::instance();
	if (!client)
	{
		RLE_CORE_CRITICAL("Failed to initialize client RLE application!");
		return -1;
	}

	// Initialize the client
	client->init();

	return client->exec();
}

#	endif
