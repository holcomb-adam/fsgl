#include "RLEpch.hpp"
#include "RLE/Core/Core.hpp"

// --- RLE ---
#include "RLE/Core/Window.hpp"
#include "RLE/Debug/Log.hpp"
#include "RLE/Node/Node.hpp"



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
    log::init();
    Node::initializeRootNode();

    s_CoreInitialized = true;
    return s_CoreInitialized;
}
