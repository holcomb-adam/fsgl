#include "RLEpch.hpp"
#include "RLE/Core/Core.hpp"

// --- RLE ---
#include "RLE/Debug/Log.hpp"



namespace
{
    static bool s_CoreInitialized = false;
}



bool rle::core::isCoreInitialized()
{
    return s_CoreInitialized;
}

bool rle::core::initialize()
{
    // Initialize the rle logging system
    rle::log::init();
	RLE_CORE_INFO("Initialized Logging System!");

    s_CoreInitialized = true;

    return s_CoreInitialized;
}
