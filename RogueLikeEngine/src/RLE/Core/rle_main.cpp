// This file contains the entry point of the Rogue-like Engine

#include "RLEpch.h"

// --- RLE ---
#include "RLE.h" // RLE main header
#include "Core.h"
#include "RLE/Debug/Log.h"



#	if defined(RLE_OS_WIN64)

int main(int argc, char* argv[])
{
	// initialize logging system
	rle::log::init();
	RLE_CORE_INFO("Initialized Logging System!");

	// create the engine application
	auto* client = rle::entry::instance();
	if (!client)
	{
		RLE_CORE_CRITICAL("Failed to initialize client RLE application!");
		return -1;
	}

	// initialize the client
	client->init();

	return client->exec();
}

#	endif
